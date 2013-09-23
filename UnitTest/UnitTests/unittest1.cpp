#include "stdafx.h"
#include "CppUnitTest.h"
#include "Common.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

SearchResult Search1(
	const int * const items,
	const int n_items,
	const int ascending,
	const int key,
	const SearchType type,
	int* const index);

SearchResult Search2(
	const int * const items,
	const int n_items,
	const int ascending,
	const int key,
	const SearchType type,
	int* const index);

SearchResult Search3(
	const int * const items,
	const int n_items,
	const int ascending,
	const int key,
	const SearchType type,
	int* const index);

SearchResult Search4(
	const int * const items,
	const int n_items,
	const int ascending,
	const int key,
	const SearchType type,
	int* const index);

SearchResult Search5(
	const int * const items,
	const int n_items,
	const int ascending,
	const int key,
	const SearchType type,
	int* const index);

namespace UnitTests
{		
	int test1[] = {0, 2, 4, 6, 8};
	int test2[] = {8, 6, 4, 2, 0};

	TEST_CLASS(Search1Test)
	{
	public:
		
		TEST_METHOD(Search1Test1)
		{
			int index = -1;
			Assert::AreEqual<int>(Search1(test1, sizeof(test1)/sizeof(test1[0]), 1, -1, LessThanEquals, &index), NotFound);
		}
		TEST_METHOD(Search1Test2)
		{
			int index = -1;
			Assert::AreEqual<int>(Search1(test1, sizeof(test1)/sizeof(test1[0]), 1, 0, LessThan, &index), NotFound);
		}
		TEST_METHOD(Search1Test3)
		{
			int index = -1;
			Assert::AreEqual<int>(Search1(test1, sizeof(test1)/sizeof(test1[0]), 1, 0, Equals, &index), FoundExact);
			Assert::AreEqual(index, 0);
		}
		TEST_METHOD(Search1Test4)
		{
			int index = -1;
			Assert::AreEqual<int>(Search1(test1, sizeof(test1)/sizeof(test1[0]), 1, 1, Equals, &index), NotFound);
		}
		TEST_METHOD(Search1Test5)
		{
			int index = -1;
			Assert::AreEqual<int>(Search1(test1, sizeof(test1)/sizeof(test1[0]), 1, 2, GreaterThanEquals, &index), FoundExact);
			Assert::AreEqual(index, 1);
		}
		TEST_METHOD(Search1Test6)
		{
			int index = -1;
			Assert::AreEqual<int>(Search1(test1, sizeof(test1)/sizeof(test1[0]), 1, 2, GreaterThan, &index), FoundGreater);
			Assert::AreEqual(index, 2);
		}


		TEST_METHOD(Search1Test7)
		{
			int index = -1;
			Assert::AreEqual<int>(Search1(test2, sizeof(test2)/sizeof(test2[0]), 0, -1, LessThan, &index), NotFound);
		}
		TEST_METHOD(Search1Test8)
		{
			int index = -1;
			Assert::AreEqual<int>(Search1(test2, sizeof(test2)/sizeof(test2[0]), 0, 4, LessThanEquals, &index), FoundExact);
			Assert::AreEqual(index, 2);
		}
		TEST_METHOD(Search1Test9)
		{
			int index = -1;
			Assert::AreEqual<int>(Search1(test2, sizeof(test2)/sizeof(test2[0]), 0, 8, Equals, &index), FoundExact);
			Assert::AreEqual(index, 0);
		}
		TEST_METHOD(Search1Test10)
		{
			int index = -1;
			Assert::AreEqual<int>(Search1(test2, sizeof(test2)/sizeof(test2[0]), 0, 5, GreaterThanEquals, &index), FoundGreater);
			Assert::AreEqual(index, 1);

		}
		TEST_METHOD(Search1Test11)
		{
			int index = -1;
			Assert::AreEqual<int>(Search1(test2, sizeof(test2)/sizeof(test2[0]), 0, 2, GreaterThanEquals, &index), FoundExact);
			Assert::AreEqual(index, 3);
		}
		TEST_METHOD(Search1Test12)
		{
			int index = -1;
			Assert::AreEqual<int>(Search1(test2, sizeof(test2)/sizeof(test2[0]), 0, 9, GreaterThan, &index), NotFound);
		}

	};

	TEST_CLASS(Search2Test)
	{
	public:
		
		TEST_METHOD(Search2Test1)
		{
			int index = -1;
			Assert::AreEqual<int>(Search2(test1, sizeof(test1)/sizeof(test1[0]), 1, -1, LessThanEquals, &index), NotFound);
		}
		TEST_METHOD(Search2Test2)
		{
			int index = -1;
			Assert::AreEqual<int>(Search2(test1, sizeof(test1)/sizeof(test1[0]), 1, 0, LessThan, &index), NotFound);
		}
		TEST_METHOD(Search2Test3)
		{
			int index = -1;
			Assert::AreEqual<int>(Search2(test1, sizeof(test1)/sizeof(test1[0]), 1, 0, Equals, &index), FoundExact);
			Assert::AreEqual(index, 0);
		}
		TEST_METHOD(Search2Test4)
		{
			int index = -1;
			Assert::AreEqual<int>(Search2(test1, sizeof(test1)/sizeof(test1[0]), 1, 1, Equals, &index), NotFound);
		}
		TEST_METHOD(Search2Test5)
		{
			int index = -1;
			Assert::AreEqual<int>(Search2(test1, sizeof(test1)/sizeof(test1[0]), 1, 2, GreaterThanEquals, &index), FoundExact);
			Assert::AreEqual(index, 1);
		}
		TEST_METHOD(Search2Test6)
		{
			int index = -1;
			Assert::AreEqual<int>(Search2(test1, sizeof(test1)/sizeof(test1[0]), 1, 2, GreaterThan, &index), FoundGreater);
			Assert::AreEqual(index, 2);
		}


		TEST_METHOD(Search2Test7)
		{
			int index = -1;
			Assert::AreEqual<int>(Search2(test2, sizeof(test2)/sizeof(test2[0]), 0, -1, LessThan, &index), NotFound);
		}
		TEST_METHOD(Search2Test8)
		{
			int index = -1;
			Assert::AreEqual<int>(Search2(test2, sizeof(test2)/sizeof(test2[0]), 0, 4, LessThanEquals, &index), FoundExact);
			Assert::AreEqual(index, 2);
		}
		TEST_METHOD(Search2Test9)
		{
			int index = -1;
			Assert::AreEqual<int>(Search2(test2, sizeof(test2)/sizeof(test2[0]), 0, 8, Equals, &index), FoundExact);
			Assert::AreEqual(index, 0);
		}
		TEST_METHOD(Search2Test10)
		{
			int index = -1;
			Assert::AreEqual<int>(Search2(test2, sizeof(test2)/sizeof(test2[0]), 0, 5, GreaterThanEquals, &index), FoundGreater);
			Assert::AreEqual(index, 1);

		}
		TEST_METHOD(Search2Test11)
		{
			int index = -1;
			Assert::AreEqual<int>(Search2(test2, sizeof(test2)/sizeof(test2[0]), 0, 2, GreaterThanEquals, &index), FoundExact);
			Assert::AreEqual(index, 3);
		}
		TEST_METHOD(Search2Test12)
		{
			int index = -1;
			Assert::AreEqual<int>(Search2(test2, sizeof(test2)/sizeof(test2[0]), 0, 9, GreaterThan, &index), NotFound);
		}
	};

	TEST_CLASS(Search3Test)
	{
	public:
		
		TEST_METHOD(Search3Test1)
		{
			int index = -1;
			Assert::AreEqual<int>(Search3(test1, sizeof(test1)/sizeof(test1[0]), 1, -1, LessThanEquals, &index), NotFound);
		}
		TEST_METHOD(Search3Test2)
		{
			int index = -1;
			Assert::AreEqual<int>(Search3(test1, sizeof(test1)/sizeof(test1[0]), 1, 0, LessThan, &index), NotFound);
		}
		TEST_METHOD(Search3Test3)
		{
			int index = -1;
			Assert::AreEqual<int>(Search3(test1, sizeof(test1)/sizeof(test1[0]), 1, 0, Equals, &index), FoundExact);
			Assert::AreEqual(index, 0);
		}
		TEST_METHOD(Search3Test4)
		{
			int index = -1;
			Assert::AreEqual<int>(Search3(test1, sizeof(test1)/sizeof(test1[0]), 1, 1, Equals, &index), NotFound);
		}
		TEST_METHOD(Search3Test5)
		{
			int index = -1;
			Assert::AreEqual<int>(Search3(test1, sizeof(test1)/sizeof(test1[0]), 1, 2, GreaterThanEquals, &index), FoundExact);
			Assert::AreEqual(index, 1);
		}
		TEST_METHOD(Search3Test6)
		{
			int index = -1;
			Assert::AreEqual<int>(Search3(test1, sizeof(test1)/sizeof(test1[0]), 1, 2, GreaterThan, &index), FoundGreater);
			Assert::AreEqual(index, 2);
		}


		TEST_METHOD(Search3Test7)
		{
			int index = -1;
			Assert::AreEqual<int>(Search3(test2, sizeof(test2)/sizeof(test2[0]), 0, -1, LessThan, &index), NotFound);
		}
		TEST_METHOD(Search3Test8)
		{
			int index = -1;
			Assert::AreEqual<int>(Search3(test2, sizeof(test2)/sizeof(test2[0]), 0, 4, LessThanEquals, &index), FoundExact);
			Assert::AreEqual(index, 2);
		}
		TEST_METHOD(Search3Test9)
		{
			int index = -1;
			Assert::AreEqual<int>(Search3(test2, sizeof(test2)/sizeof(test2[0]), 0, 8, Equals, &index), FoundExact);
			Assert::AreEqual(index, 0);
		}
		TEST_METHOD(Search3Test10)
		{
			int index = -1;
			Assert::AreEqual<int>(Search3(test2, sizeof(test2)/sizeof(test2[0]), 0, 5, GreaterThanEquals, &index), FoundGreater);
			Assert::AreEqual(index, 1);

		}
		TEST_METHOD(Search3Test11)
		{
			int index = -1;
			Assert::AreEqual<int>(Search3(test2, sizeof(test2)/sizeof(test2[0]), 0, 2, GreaterThanEquals, &index), FoundExact);
			Assert::AreEqual(index, 3);
		}
		TEST_METHOD(Search3Test12)
		{
			int index = -1;
			Assert::AreEqual<int>(Search3(test2, sizeof(test2)/sizeof(test2[0]), 0, 9, GreaterThan, &index), NotFound);
		}

	};

	TEST_CLASS(Search4Test)
	{
	public:
		
		TEST_METHOD(Search4Test1)
		{
			int index = -1;
			Assert::AreEqual<int>(Search4(test1, sizeof(test1)/sizeof(test1[0]), 1, -1, LessThanEquals, &index), NotFound);
		}
		TEST_METHOD(Search4Test2)
		{
			int index = -1;
			Assert::AreEqual<int>(Search4(test1, sizeof(test1)/sizeof(test1[0]), 1, 0, LessThan, &index), NotFound);
		}
		TEST_METHOD(Search4Test3)
		{
			int index = -1;
			Assert::AreEqual<int>(Search4(test1, sizeof(test1)/sizeof(test1[0]), 1, 0, Equals, &index), FoundExact);
			Assert::AreEqual(index, 0);
		}
		TEST_METHOD(Search4Test4)
		{
			int index = -1;
			Assert::AreEqual<int>(Search4(test1, sizeof(test1)/sizeof(test1[0]), 1, 1, Equals, &index), NotFound);
		}
		TEST_METHOD(Search4Test5)
		{
			int index = -1;
			Assert::AreEqual<int>(Search4(test1, sizeof(test1)/sizeof(test1[0]), 1, 2, GreaterThanEquals, &index), FoundExact);
			Assert::AreEqual(index, 1);
		}
		TEST_METHOD(Search4Test6)
		{
			int index = -1;
			Assert::AreEqual<int>(Search4(test1, sizeof(test1)/sizeof(test1[0]), 1, 2, GreaterThan, &index), FoundGreater);
			Assert::AreEqual(index, 2);
		}


		TEST_METHOD(Search4Test7)
		{
			int index = -1;
			Assert::AreEqual<int>(Search4(test2, sizeof(test2)/sizeof(test2[0]), 0, -1, LessThan, &index), NotFound);
		}
		TEST_METHOD(Search4Test8)
		{
			int index = -1;
			Assert::AreEqual<int>(Search4(test2, sizeof(test2)/sizeof(test2[0]), 0, 4, LessThanEquals, &index), FoundExact);
			Assert::AreEqual(index, 2);
		}
		TEST_METHOD(Search4Test9)
		{
			int index = -1;
			Assert::AreEqual<int>(Search4(test2, sizeof(test2)/sizeof(test2[0]), 0, 8, Equals, &index), FoundExact);
			Assert::AreEqual(index, 0);
		}
		TEST_METHOD(Search4Test10)
		{
			int index = -1;
			Assert::AreEqual<int>(Search4(test2, sizeof(test2)/sizeof(test2[0]), 0, 5, GreaterThanEquals, &index), FoundGreater);
			Assert::AreEqual(index, 1);

		}
		TEST_METHOD(Search4Test11)
		{
			int index = -1;
			Assert::AreEqual<int>(Search4(test2, sizeof(test2)/sizeof(test2[0]), 0, 2, GreaterThanEquals, &index), FoundExact);
			Assert::AreEqual(index, 3);
		}
		TEST_METHOD(Search4Test12)
		{
			int index = -1;
			Assert::AreEqual<int>(Search4(test2, sizeof(test2)/sizeof(test2[0]), 0, 9, GreaterThan, &index), NotFound);
		}
	};
	/*
	TEST_CLASS(Search5Test)
	{
	public:
		
		TEST_METHOD(Search5Test1)
		{
			int index = -1;
			Assert::AreEqual<int>(Search5(test1, sizeof(test1)/sizeof(test1[0]), 1, -1, LessThanEquals, &index), NotFound);
		}
		TEST_METHOD(Search5Test2)
		{
			int index = -1;
			Assert::AreEqual<int>(Search5(test1, sizeof(test1)/sizeof(test1[0]), 1, 0, LessThan, &index), NotFound);
		}
		TEST_METHOD(Search5Test3)
		{
			int index = -1;
			Assert::AreEqual<int>(Search5(test1, sizeof(test1)/sizeof(test1[0]), 1, 0, Equals, &index), FoundExact);
			Assert::AreEqual(index, 0);
		}
		TEST_METHOD(Search5Test4)
		{
			int index = -1;
			Assert::AreEqual<int>(Search5(test1, sizeof(test1)/sizeof(test1[0]), 1, 1, Equals, &index), NotFound);
		}
		TEST_METHOD(Search5Test5)
		{
			int index = -1;
			Assert::AreEqual<int>(Search5(test1, sizeof(test1)/sizeof(test1[0]), 1, 2, GreaterThanEquals, &index), FoundExact);
			Assert::AreEqual(index, 1);
		}
		TEST_METHOD(Search5Test6)
		{
			int index = -1;
			Assert::AreEqual<int>(Search5(test1, sizeof(test1)/sizeof(test1[0]), 1, 2, GreaterThan, &index), FoundGreater);
			Assert::AreEqual(index, 2);
		}


		TEST_METHOD(Search5Test7)
		{
			int index = -1;
			Assert::AreEqual<int>(Search5(test2, sizeof(test2)/sizeof(test2[0]), 0, -1, LessThan, &index), NotFound);
		}
		TEST_METHOD(Search5Test8)
		{
			int index = -1;
			Assert::AreEqual<int>(Search5(test2, sizeof(test2)/sizeof(test2[0]), 0, 4, LessThanEquals, &index), FoundExact);
			Assert::AreEqual(index, 2);
		}
		TEST_METHOD(Search5Test9)
		{
			int index = -1;
			Assert::AreEqual<int>(Search5(test2, sizeof(test2)/sizeof(test2[0]), 0, 8, Equals, &index), FoundExact);
			Assert::AreEqual(index, 0);
		}
		TEST_METHOD(Search5Test10)
		{
			int index = -1;
			Assert::AreEqual<int>(Search5(test2, sizeof(test2)/sizeof(test2[0]), 0, 5, GreaterThanEquals, &index), FoundGreater);
			Assert::AreEqual(index, 1);

		}
		TEST_METHOD(Search5Test11)
		{
			int index = -1;
			Assert::AreEqual<int>(Search5(test2, sizeof(test2)/sizeof(test2[0]), 0, 2, GreaterThanEquals, &index), FoundExact);
			Assert::AreEqual(index, 3);
		}
		TEST_METHOD(Search5Test12)
		{
			int index = -1;
			Assert::AreEqual<int>(Search5(test2, sizeof(test2)/sizeof(test2[0]), 0, 9, GreaterThan, &index), NotFound);
		}
	};*/
}