
// Unit testing imports
#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>

// Cpp imports
#include <stdlib.h>

// Test Classes
#include "vector.h"

// Constants
#define MAX_LENGTH 100000
#define ADDTEST(test, func) testSuite->addTest\
								(new CppUnit::TestCaller<test>\
								 	("func", &test::func))


class TestVector: CppUnit::TestCase  {
private:
	int* array; size_t length;

public:
	// Constructors
	TestVector (std::string name): CppUnit::TestCase(name) {}
	TestVector () {}

	// Fixture handling
	void setUp () {
		srand(time(NULL));
		length = rand() & MAX_LENGTH;
		array = (int*) malloc(sizeof(int) * length);
		for (size_t i = 0; i < length; i++) {
			array[i] = rand() % 10000;
		}	
	}

	void tearDown() {
		free(array);
	}
	

	// Tests
	void testInit() 	 {
		Vector v;
		size_t init_size = rand() % 100;
		v_init(&v, init_size);
		CPPUNIT_ASSERT(v.length == 0);
		CPPUNIT_ASSERT(v.array_length == init_size);
	}

	void testAdd() {
		//bool pass_size_condition = true;
		bool assert_eq = true;
		size_t random_length;
		Vector v;
		for (size_t i = 0; i < 10; i++) {
			random_length = rand() % length;
			v_init(&v, rand() % random_length);
			printf("%d,", random_length);
			for (size_t j = 0; j < random_length; j++) {
				v_add(&v, array[j]);
				if (array[j] = )
				//if (2 * v.length >  v.array_length) {
					//pass_size_condition = false;
				//}
			}
			for (size_t j = 0; j < random_length; j++) {
				if (array[j] != v.array[j]) {
					assert_eq = false;
				}
			}
			v_free(&v);
		}
		//CPPUNIT_ASSERT(pass_size_condition);
		CPPUNIT_ASSERT(assert_eq);
	}


	// Generate Suite
	static CppUnit::TestSuite* suite() {
		CppUnit::TestSuite* testSuite = new CppUnit::TestSuite("TestVector");

		
		ADDTEST(TestVector, testInit);
		ADDTEST(TestVector, testAdd);
	
		return testSuite;
	}

};


int main(void) {
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(TestVector::suite());
	runner.run();
	return 0;
}
