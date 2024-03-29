// Copyright Jianing Yang <jianingy.yang@gmail.com> 2009

#include <string.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include "trie_impl.h"
#include "trie.h"

#define length(x) (strlen(x))
#define unsigned_value(x, y) static_cast<unsigned int>(j + 1)
#define signed_value(x, y) static_cast<int>(3 - j)

using namespace dutil;

int main()
{
    size_t i, j;
    trie::value_type val;
    trie::key_type key;
    const char *dict[][256] = {
        {"abc", "def"},
        {"baby", "bachelor", "back", "badge", "badger", "badness", "bcs"},
        {"in", "inspiration", "instant", "instrument", "prevision", "precession", "procession", "provision", NULL},
        {"moldy", "molochize", "Molochize", "molochized", "Molochize's", "monarchize", NULL},
        {"a", "abilities", "ability's", "about", "absence", "absence's", "absolute", "absolutely", "academic", "acceptable", NULL},
        {"sepaled", "Septembrizers", "septemia", "septicemia", "septicemias", NULL},
        {"abcd", "zdd", NULL},
        {"bcd", "bc", "b"},
        {"a", "ab", "abc"},
        {NULL}
    };

    printf("libxtree regress testing (exclude load and mmap)\n");
    printf("================================================\n");

/* basic_trie */
    printf("\nbasic_trie\n");
    printf("----------\n");
    for (i = 0; dict[i][0]; i++) {
        basic_trie btrie;
        printf("wordset %lu: ", i);
        for (j = 0; dict[i][j]; j++) {
            key.assign(dict[i][j], length(dict[i][j]));
            btrie.insert(key, unsigned_value(j, i));
        }
        for (j = 0; dict[i][j]; j++) {
            key.assign(dict[i][j], length(dict[i][j]));
            if (btrie.search(key, &val) && (unsigned)val
                == unsigned_value(j, i)) {
                printf("[%s,%d] ",dict[i][j],val);
            } else {
                printf("\nTEST FAILED on '%s'!\n", dict[i][j]);
                btrie.trace(1);
                exit(0);
            }
        }
        printf("\n");
    }
#if 0
    printf("\nbasic_trie copy constructor\n");
    printf("----------\n");
    for (i = 0; dict[i][0]; i++) {
        basic_trie btrie;
        printf("wordset %lu: ", i);
        for (j = 0; dict[i][j]; j++) {
            key.assign(dict[i][j], length(dict[i][j]));
            btrie.insert(key, unsigned_value(j, i));
        }
        basic_trie ctrie(btrie);
        for (j = 0; dict[i][j]; j++) {
            key.assign(dict[i][j], length(dict[i][j]));
            if (ctrie.search(key, &val) && (unsigned)val
                == unsigned_value(j, i)) {
                printf("[%d] ", val);
            } else {
                printf("\nTEST FAILED on '%s'!\n", dict[i][j]);
                ctrie.trace(1);
                exit(0);
            }
        }
        printf("\n");
    }

    printf("\nbasic_trie operator = \n");
    printf("----------\n");
    for (i = 0; dict[i][0]; i++) {
        basic_trie btrie;
        printf("wordset %lu: ", i);
        for (j = 0; dict[i][j]; j++) {
            key.assign(dict[i][j], length(dict[i][j]));
            btrie.insert(key, unsigned_value(j, i));
        }
        basic_trie ctrie;
        ctrie = btrie;
        for (j = 0; dict[i][j]; j++) {
            key.assign(dict[i][j], length(dict[i][j]));
            if (ctrie.search(key, &val) && (unsigned)val
                == unsigned_value(j, i)) {
                printf("[%d] ", val);
            } else {
                printf("\nTEST FAILED on '%s'!\n", dict[i][j]);
                ctrie.trace(1);
                exit(0);
            }
        }
        printf("\n");
    }

///* double_trie */
//    printf("\ndouble_trie\n");
//    printf("----------\n");
//    for (i = 0; dict[i][0]; i++) {
//        double_trie btrie;
//        printf("wordset %lu: ", i);
//        for (j = 0; dict[i][j]; j++) {
//            key.assign(dict[i][j], length(dict[i][j]));
//            btrie.insert(key, signed_value(j, i));
//        }
//        for (j = 0; dict[i][j]; j++) {
//            key.assign(dict[i][j], length(dict[i][j]));
//            if (btrie.search(key, &val) && val == signed_value(j, i)) {
//                printf("[%d] ", val);
//            } else {
//                printf("\nTEST FAILED on '%s' = %d!\n", dict[i][j], val);
//                btrie.trace_table(0, 0);
//                std::cout << "FRONT: \n";
//                btrie.front_trie()->trace(1);
//                std::cout << "REAR: \n";
//                btrie.rear_trie()->trace(1);
//                exit(0);
//            }
//        }
//        printf("\n");
//    }
//
///* binary test */
//    do {
//        double_trie btrie;
//        const char *binary[] = {"\x00\x01\x02", "\x00\x01", "\x00"};
//        size_t binary_size[] = {3, 2, 1};
//        printf("\ndouble_trie binary data\n");
//        printf("-------------------------\nbinary data:");
//        for (i = 0; i < sizeof(binary) / sizeof(char *); i++) {
//            key.assign(binary[i], binary_size[i]);
//            btrie.insert(key,  1 - i);
//        }
//        for (i = 0; i < sizeof(binary) / sizeof(char *); i++) {
//            key.assign(binary[i], binary_size[i]);
//            if (btrie.search(key, &val) && val + i == 1) {
//                printf("[%d] ", val);
//            } else {
//                printf("\nTEST FAILED on #%lu = %d!\n", i, val);
//                btrie.trace_table(0, 0);
//                std::cout << "FRONT: \n";
//                btrie.front_trie()->trace(1);
//                std::cout << "REAR: \n";
//                btrie.rear_trie()->trace(1);
//                exit(0);
//            }
//        }
//        printf("\n");
//    } while (0);
//
//


/* single_trie */
    printf("\nsingle_trie\n");
    printf("----------\n");
    for (i = 0; dict[i][0]; i++) {
        single_trie btrie;
        printf("wordset %lu: ", i);
        for (j = 0; dict[i][j]; j++) {
            key.assign(dict[i][j], length(dict[i][j]));
            btrie.insert(key, signed_value(j, i));
        }
        for (j = 0; dict[i][j]; j++) {
            key.assign(dict[i][j], length(dict[i][j]));
            if (btrie.search(key, &val) && val == signed_value(j, i)) {
                printf("[%s,%d] ",dict[i][j],val);
            } else {
                printf("\nTEST FAILED on '%s' = %d!\n", dict[i][j], val);
                std::cout << "TRIE: \n";
                btrie.trie()->trace(1);
                btrie.trace_suffix(0, 100);
                exit(0);
            }
        }
        printf("\n");
    }

#endif
      return 0;    
  }
 
//// vim: ts=4 sw=4 ai et
