#pragma once
#include "Common.h"

// Switch in separate function

// Return true is compare is positive
bool Compare(int item, int key, SearchType type, SearchResult& result, bool& bStop)
{
	bool bRes = false;

	switch (type)
	{
	case LessThan:
		{
			if (item < key)
			{
				bRes = true;
				result = FoundLess;
			}
			else
				bStop = true;
			break;
		}
	case LessThanEquals:
		{
			if (item < key)
			{
				bRes = true;
				result = FoundLess;
			}
			else if (item == key)
			{
				bRes = true;
				result = FoundExact;
				bStop = true;
			}
			else
				bStop = true;
			break;
		}
	case Equals:
		{
			if (item == key)
			{
				bRes = true;
				result = FoundExact;
				bStop = true;
			}
			else
				result = NotFound;
			break;
		}
	case GreaterThan:
		{
			if (item > key)
			{
				bRes = true;
				result = FoundGreater;
			}
			else
				bStop = true;
			break;
		}
	case GreaterThanEquals:
		{
			if (item > key)
			{
				bRes = true;
				result = FoundGreater;
			}
			else if (item == key)
			{
				bRes = true;
				result = FoundExact;
				bStop = true;
			}
			else
				bStop = true;
			break;
		}
	}

	return bRes;
}

void SetStartingPosition(int ascending, SearchType type, int n_items, int& i, int& increment, int& stopPos)
{
	if ( ( ( ascending > 0 ) && (type == LessThan || type == LessThanEquals) ) ||
		 ( ( ascending == 0 ) && (type == GreaterThan || type == GreaterThanEquals) ) )
	{
		i = 0;
		increment = 1;
		stopPos = n_items;
	}
	else
	{
		i = n_items - 1;
		increment = -1;
		stopPos = -1;
	}
}

// If ( asc and < ) or (des and > ) then go forward and stop at first non true
// Else go backward, ( asc and > ) or (des and < )
SearchResult Search3(
	const int * const items,
	const int n_items,
	const int ascending,
	const int key,
	const SearchType type,
	int* const index)
{
	// Check if type is correct

	int nCounter = 0;
	bool bStop = false;
	int foundPosLast = -1;
	int i, increment, stopPos;
	SearchResult result = NotFound;

	SetStartingPosition(ascending, type, n_items, i, increment, stopPos);

	while (i != stopPos && !bStop)
	{
		nCounter++;

		if (Compare(items[i], key, type, result, bStop))
			foundPosLast = i;

		i += increment;
	}

	printf ("Iterations taken %d.\n", nCounter);

	if ( foundPosLast != -1)
		*index = foundPosLast;

	return result;
}
