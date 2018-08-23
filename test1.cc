// Copyright Jianing Yang <jianingy.yang@gmail.com> 2009

#include <string.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
#include "trie_impl.h"
#include "trie.h"

using namespace dutil;

int main(int argc,char **argv)
{
//	std::cout<<"please input infile,prefix,outfile:"<<std::endl;

    if(argc!=3)  
    {
        std::cerr<<"input argument invalid"<<std::endl;
        return 0;
    }

    trie::key_type key;

#if 0
	std::ifstream infile(argv[1]);
    std::string line,word;
/*
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
*/

    std::cout<<"========single_trie======="<<std::endl;
     
    single_trie btrie;
    while(std::getline(infile,line))
    {
        std::istringstream OneLine(line);
        while(OneLine>>word)
        {
            key.assign(word.c_str(),word.size());
            btrie.insert(key,word.size()+1);
        }
       
        
    }
#endif
	single_trie btrie(argv[1]);
    std::cout<<std::endl;
    trie::result_type result;
    key.assign(argv[2],strlen(argv[2]));
    btrie.prefix_search(key,&result);            
    for(size_t i=0;i<result.size();++i)
        std::cout<<result[i].first.c_str()<<std::endl;

	std::cout<<"================="<<std::endl;
	std::cout<<"detail:memory"<<std::endl;
//	btrie.build(argv[3],1);

    return 0;
}
