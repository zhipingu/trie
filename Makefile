objs=trie.o trie_impl.o test.o

test:${objs}
	g++ ${objs} -o test -std=c++11

trie_impl.o:trie_impl.cc trie_impl.h trie.h
	g++ -c -std=c++11 trie_impl.cc
trie.o:trie.h trie_impl.h trie.cc
	g++ -c -std=c++11 trie.cc
test.o:trie.h trie_impl.h test.cc
	g++ -c -std=c++11 test.cc

.PHONY:clean
clean:
	-rm ${objs} test
