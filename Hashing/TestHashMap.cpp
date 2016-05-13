
// Unit testing imports
#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>

// Cpp imports
#include <stdlib.h>
#include "limits.h"
#include "math.h"

// Test Classes
#include "hash_map.h"

// Constants
#define EXPERIMENTS 1000
#define SQRT(x) x * x
#define ADDTEST(test, func) testSuite->addTest\
								(new CppUnit::TestCaller<test>\
								 	("func", &test::func))


class TestHashMap: CppUnit::TestCase  {
private:
	int* array; size_t length;

public:
	// Constructors
	TestHashMap (std::string name): CppUnit::TestCase(name) {}
	TestHashMap () {}

	// Fixture handling
	void setUp () {
		srand(time(NULL));
	}

	void tearDown() {
	}
	

	// Tests
	void smokeTestHash() {
		int a [] = {-567, -345, 567, 999, 10456};
		size_t n = 79;
		for (size_t i = 0; i < 5; i++) {
			int hash_result = hash(a[i], n);
			CPPUNIT_ASSERT(0 <= hash_result && hash_result < n);
		}
	}

	void boundaryTestHash() {
		int a [] = {INT_MIN, -1, 0 , 1, INT_MAX};
		size_t n = 645;
		for (size_t i = 0; i < 5; i++) {
			int hash_result = hash(a[i], n);
			CPPUNIT_ASSERT(0 <= hash_result && hash_result < n);
		}
		// Should also test the edge cases for the possible values of n.
	}

	void fuzzTestHash() {
		int hash_result, n;
		for (size_t i = 0; i < EXPERIMENTS; i++) {
			n = rand();
			hash_result = hash(unsigned_rand(), n);
			CPPUNIT_ASSERT(0 <= hash_result && hash_result < n);
		}
	}
	// This does fuzz and boundary testing.
	// This doesn't check to see what happends when m get towards MAX_INT
	// If try_next returns a value out of range then visited_all will have a seg fault.
	void fuzzTestTryNext() {
		int m;
		for (size_t i = 0; i < EXPERIMENTS; i++) {
			m = rand() % 10000;
			int a [] = {0, 1, m - 1};
			for (size_t i = 0; i < 3; i++) {
				CPPUNIT_ASSERT(visited_all(a[i], m));
			}
		}
	}
	//void performanceTestHash() {
		//size_t n = 1024;
		//int hash_result;
		//int * a = (int*) malloc(sizeof(int) * n);
		//for (size_t i = 0; i < n; i++) {
			//a[i] = 0;
		//}
		//for (size_t i = 0; i < 10 * EXPERIMENTS; i++) {
			//hash_result = hash(unsigned_rand(), n);
			//a[hash_result]++;
		//}
		//printf("\n%f\n", sd(a, n, mean(a, n)));
		//CPPUNIT_ASSERT_MESSAGE("The amount of standard deviation is concerning:", sd(a, n, mean(a, n)) < 3);
	//}

	// Helper functions
	int unsigned_rand() {
		return (rand() % 2 == 1) ? rand() * -1 : rand();
	}

	bool visited_all(int begin, int m) {
		int a [m];
		int current = begin;
		do {
			a[current] = 1;
			current = try_next(current, m);
		} while (current != begin);

		for (size_t i = 0; i < m; i++) {
			if (a[i] != 1) {
				return false;
			}
		}
		return true;
	}
	//float mean(int * array, size_t length) {
		//int total = 0;
		//for (size_t i = 0; i < length; i++) {
			//total += array[i];
		//}
		//return total / length;
	//}

	//float sd(int* array, size_t length, float mean) {
		//double total = 0;
		//for (size_t i = 0; i < length; i++) {
			//total += pow(array[i] - mean, 2);
		//}
		//return sqrt(total/length);
	//}

	// Generate Suite
	static CppUnit::TestSuite* suite() {
		CppUnit::TestSuite* testSuite = new CppUnit::TestSuite("TestHashMap");
		ADDTEST(TestHashMap, smokeTestHash);
		ADDTEST(TestHashMap, boundaryTestHash);
		ADDTEST(TestHashMap, fuzzTestHash);
		ADDTEST(TestHashMap, fuzzTestTryNext);
		//ADDTEST(TestHashMap, performanceTestHash);
		return testSuite;
	}

};


int main(void) {
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(TestHashMap::suite());
	runner.run();
	return 0;
}
