// YarkoTest.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <assert.h>
#include <time.h>
#include "Search1.h"
#include "Search2.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int test1[] = {0, 2, 4, 6, 8};
	int test2[] = {8, 6, 4, 2, 0};

	int index = -1;

/*
	assert(Search(test1, sizeof(test1)/sizeof(test1[0]), 1, -1, LessThanEquals, &index) == NotFound);
	assert(Search(test1, sizeof(test1)/sizeof(test1[0]), 1, 0, LessThan, &index) == NotFound);
	assert(Search(test1, sizeof(test1)/sizeof(test1[0]), 1, 0, Equals, &index) == FoundExact && index == 0);
	assert(Search(test1, sizeof(test1)/sizeof(test1[0]), 1, 1, Equals, &index) == NotFound);
	assert(Search(test1, sizeof(test1)/sizeof(test1[0]), 1, 2, GreaterThanEquals, &index) == FoundExact && index == 1);
	assert(Search(test1, sizeof(test1)/sizeof(test1[0]), 1, 2, GreaterThan, &index) == FoundGreater && index == 2);

	assert(Search(test2, sizeof(test2)/sizeof(test2[0]), 0, -1, LessThan, &index) == NotFound);
	assert(Search(test2, sizeof(test2)/sizeof(test2[0]), 0, 4, LessThanEquals, &index) == FoundExact && index == 2);
	assert(Search(test2, sizeof(test2)/sizeof(test2[0]), 0, 8, Equals, &index) == FoundExact && index == 0);
	assert(Search(test2, sizeof(test2)/sizeof(test2[0]), 0, 5, GreaterThanEquals, &index) == FoundGreater && index == 1);
	assert(Search(test2, sizeof(test2)/sizeof(test2[0]), 0, 2, GreaterThanEquals, &index) == FoundExact && index == 3);
	assert(Search(test2, sizeof(test2)/sizeof(test2[0]), 0, 9, GreaterThan, &index) == NotFound);
*/

	const int cnCount = 10000000;
	int* test3 = new int[cnCount];
	for (int i=0; i<cnCount; i++)
		test3[i] = i;

	clock_t t, tsum = 0;
	int tmp;

	const int cnIter = 1;
	for (int i=0; i<cnIter; i++)
	{
		t = clock();
// 		for (int i=0; i<cnCount/2; i++)
// 		{
// 			if ( test3[i] == 0 )
// 				tmp = 1;
// 			else 
// 				tmp = 2;
// 		}
// 		assert(Search(test3, cnCount, 1, 5000000, GreaterThan, &index) == FoundGreater && index == 5000001);
// 		assert(Search(test3, cnCount, 1, 5000000, GreaterThanEquals, &index) == FoundExact && index == 5000000);
// 		assert(Search(test3, cnCount, 1, 5000000, LessThan, &index) == FoundLess && index == 4999999);
 		Search1(test3, cnCount, 1, 5000000, GreaterThan, &index);
// 		Search1(test3, cnCount, 1, 5000000, GreaterThanEquals, &index);
// 		Search1(test3, cnCount, 1, 5000000, LessThan, &index);
		t = clock() - t;
		tsum += t;
		printf ("Search1 took %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);

		t = clock();
		Search2(test3, cnCount, 1, 5000000, GreaterThan, &index);
// 		Search2(test3, cnCount, 1, 5000000, GreaterThanEquals, &index);
// 		Search2(test3, cnCount, 1, 5000000, LessThan, &index);
		t = clock() - t;
		tsum += t;
		printf ("Search2 took %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
	}
	delete[] test3;
//	printf ("Average for %d iterations is %f clicks (%f seconds).\n",cnIter, (float)tsum/cnIter, ((float)tsum/cnIter)/CLOCKS_PER_SEC);

	printf("OK\n");

	return 0;
}