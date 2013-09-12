// YarkoTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>
typedef enum {
    LessThan = 0,
    LessThanEquals = 1,
    Equals = 2,
    GreaterThanEquals = 3,
    GreaterThan = 4
} SearchType;
 
typedef enum {
    NotFound,
    FoundExact,
    FoundGreater,
    FoundLess
} SearchResult;

SearchResult Search(
    const int * const items,
    const int n_items,
    const int ascending,
    const int key,
    const SearchType type,
    int* const index)
{
	// Check if type is correct

	int foundPos = -1;
	int i = ascending > 0 ? 0 : n_items - 1;
	int increment = ascending > 0 ? 1 : -1;
	int stopPos = ascending > 0 ? n_items : -1;
	SearchResult result = NotFound;

	while (i != stopPos)
	{
		switch (type)
		{
			case LessThan:
			{
				if (items[i] < key && ( foundPos == -1 || items[i] > items[foundPos]))
					foundPos = i;
				break;
			}
			case LessThanEquals:
			{
				if (items[i] == key)
				{
					foundPos = i;
					result = FoundExact;
					goto exit;
				}
				if (items[i] < key && ( foundPos == -1 || items[i] > items[foundPos]))
					foundPos = i;
				break;
			}
			case Equals:
			{
				if (items[i] == key)
				{
					foundPos = i;
					result = FoundExact;
					goto exit;
				}
				break;
			}
			case GreaterThan:
			{
				if (items[i] > key && ( foundPos == -1 || items[i] < items[foundPos]))
					foundPos = i;
				break;
			}
			case GreaterThanEquals:
			{
				if (items[i] == key)
				{
					foundPos = i;
					result = FoundExact;
					goto exit;
				}
				if (items[i] > key && ( foundPos == -1 || items[i] < items[foundPos]))
					foundPos = i;
				break;
			}
		}

		i += increment;
	}

exit:
	if ( foundPos == -1)
	    return NotFound;

	*index = foundPos;

	if ( result == FoundExact )
		return result;
	else if ( type == LessThan || type == LessThanEquals )
		return FoundLess;
	else
		return FoundGreater;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int test1[] = {0, 2, 4, 6, 8};
	int test2[] = {8, 6, 4, 2, 0};

	int index = -1;

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

	return 0;
}

