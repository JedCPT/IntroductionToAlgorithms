make:
	clang hash_map.c
	./a.out

test:
	clang++ -c hash_map.c -o hash_map.o 
	clang++ hash_map.o TestHashMap.cpp -lcppunit
	./a.out
