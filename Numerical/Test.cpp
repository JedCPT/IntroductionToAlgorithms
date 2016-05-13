#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>

#include <string>
#include "string.h"
#include "math.h"
#include "stdlib.h"
#include "limits.h"
#include "stdint.h"

#define	EXPERIMENTS 1000
#define BIT(i) ((int) pow(2, i)) 
#define ADDTEST(test, func) testSuite->addTest\
								(new CppUnit::TestCaller<test>\
									("func", &test::func))


uint32_t bit_add(uint32_t x, uint32_t y) {
	int x_bit, y_bit, temp, z = 0, carry = 0;
	for (int i = 0; i < 32; i++) {
		// Extract the ith bit from x and y then move it to the leftmost bit.
		x_bit = (x & BIT(i)) >> i;
		y_bit = (y & BIT(i)) >> i;
		// ADD up the carry the ith bit of x and y.
		temp= x_bit + y_bit + carry;
		carry = (temp & BIT(1)) >> 1;// calcule the carry bit and move it left.
		temp &= 1; // Clear the carry bit. 
		z = z | (temp << i);// Set the correct bit in z.
	}
	return z;
}


uint16_t bit_mult_in(uint16_t x, uint16_t y, int m) {
	if (m == 1) {
		return x * y;
	}
	uint16_t x_1 = x  >> (m / 2);
	uint16_t y_1 = y  >> (m / 2);
	uint16_t x_0 = x - (x_1 << m /2); 
	uint16_t y_0 = y - (y_1 << m /2); 
	//uint32_t z_1 = bit_mult_in(x_1, y_1, m/2) << (m);
	//uint32_t z_2 = (bit_mult_in(x_0, y_1, m/2) + bit_mult_in(x_1, y_0, m/2)) << (m/2);
	//uint32_t z_3 = bit_mult_in(x_0, y_0, m/2);
	//uint32_t 
	//return z_1 + z_2 + z_3 + (z_1 + z_2 + z_3 < z_3 || z_1 + z_2 + z_3 < z_2 || z_1 + z_2 + z_3 < z_1);
	//return bit_add(it_add((bit_mult_in(x_1, y_1, m/2) << (m)), ((bit_mult_in(x_0, y_1, m/2) + bit_mult_in(x_1, y_0, m/2)) << (m/2))), bit_mult_in(x_0, y_0, m/2));
	//return (bit_mult_in(x_1, y_1, m/2) << (m)) + ((bit_mult_in(x_0, y_1, m/2) + bit_mult_in(x_1, y_0, m/2)) << (m/2)) + bit_mult_in(x_0, y_0, m/2);
	uint16_t z = (bit_mult_in(x_1, y_1, m/2) << (m)) + ((bit_mult_in(x_0, y_1, m/2) + bit_mult_in(x_1, y_0, m/2)) << (m/2)) + bit_mult_in(x_0, y_0, m/2);
	return z;
}

uint16_t bit_mult(uint16_t x, uint16_t y) {
	return bit_mult_in(x, y, 16);
}



class Test : CppUnit::TestCase {
public:
	// Both constructors are necessary.
	Test (std::string name) : CppUnit::TestCase(name) {}	
	Test () {}

	void setUp () {
		// Init fixtures that can be used by test functions.	
		srand(time(NULL));
	}

	void tearDown () {
		// Free any fixtures.	
	}
	
	void testBitMult() {
		//Smoke and boundary tests.
		CPPUNIT_ASSERT(0 == bit_mult(0,0));
		CPPUNIT_ASSERT(0 == bit_mult(100,0));
		CPPUNIT_ASSERT(100 == bit_mult(2,50));
		CPPUNIT_ASSERT(4000 == bit_mult(1000,4));
		printf("hello: %u\n", (uint16_t) UINT16_MAX * UINT16_MAX);
		printf("%u", bit_mult(UINT16_MAX, UINT16_MAX));
		//CPPUNIT_ASSERT( ((uint16_t) UINT16_MAX * UINT16_MAX) == bit_mult(UINT16_MAX, UINT16_MAX));
		//CPPUNIT_ASSERT(UINT_MAX == bit_mult(UINT_MAX,1));
		//CPPUNIT_ASSERT(0 == bit_mult(65536,65536));
		//printf("hello: %u\n", (unsigned int)pow(65536, 2) );
		//printf("hello: %u\n", bit_mult(65536, 65536) );
		//printf("hello: %u\n", 70000 * 70000 );
		//printf("hello: %u\n", bit_mult(70000, 70000) );
		//printf("hello: %u\n", UINT_MAX * UINT_MAX);
		//printf("hello: %u\n", bit_mult(UINT_MAX, UINT_MAX) );
		
		//uint32_t x, y;
		//for (size_t i = 0; i < EXPERIMENTS; i++) {
			//x = rand() % ((int) sqrt(UINT_MAX));
			//y = rand() % ((int) sqrt(UINT_MAX));
			//CPPUNIT_ASSERT(x * y == bit_mult(x, y));
		//}
	}
	void testBitAdd() {
		// Test the boundary cases
		CPPUNIT_ASSERT(0 == bit_add(0, 0));
		CPPUNIT_ASSERT(UINT_MAX == bit_add(UINT_MAX, 0));
		CPPUNIT_ASSERT(0 == bit_add(UINT_MAX, 1));
		CPPUNIT_ASSERT(UINT_MAX - 1 == bit_add(UINT_MAX, UINT_MAX));

		// Do some fuzz tests
		uint32_t x, y;
		for (size_t i = 0; i < EXPERIMENTS; i++) {
			x = rand();
			y = rand();
			CPPUNIT_ASSERT(x + y == bit_add(x, y));
		}
	}
	static CppUnit::Test* suite() {
		// create a test suite
		CppUnit::TestSuite *testSuite= new CppUnit::TestSuite("StudentTestCase");	
		ADDTEST(Test, testBitAdd);
		ADDTEST(Test, testBitMult);
		return testSuite;

	}
};

int main(int argc, const char *argv[]) {
	//CppUnit::TextUi::TestRunner runner;	
	//runner.addTest(Test::suite());
	//runner.run();
	void* x = malloc(8);
	void* y = malloc(8);
	memset(x, 0, 8);
	*x |= *y;
}















