make:
	clang vector.c
	./a.out

test:
	clang++ -c vector.c -o vector.o 
	clang++ vector.o TestVector.cpp -lcppunit
	./a.out
