#pragma once
#include "Common.h"

// Function pointers

bool LessThanCmp(int item, int key, SearchType type, SearchResult& result, bool& bStop)
{
	bool bRes = false;

	if (item < key)
	{
		bRes = true;
		result = FoundLess;
	}
	else
		bStop = true;

	return bRes;
}

bool LessThanEqualsCmp(int item, int key, SearchType type, SearchResult& result, bool& bStop)
{
	bool bRes = false;

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

	return bRes;
}

bool EqualsCmp(int item, int key, SearchType type, SearchResult& result, bool& bStop)
{
	bool bRes = false;

	if (item == key)
	{
		bRes = true;
		result = FoundExact;
		bStop = true;
	}
	else
		result = NotFound;

	return bRes;
}

bool GreaterThanCmp(int item, int key, SearchType type, SearchResult& result, bool& bStop)
{
	bool bRes = false;

	if (item > key)
	{
		bRes = true;
		result = FoundGreater;
	}
	else
		bStop = true;

	return bRes;
}

bool GreaterThanEqualsCmp(int item, int key, SearchType type, SearchResult& result, bool& bStop)
{
	bool bRes = false;

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

	return bRes;
}

// If ( asc and < ) or (des and > ) then go forward and stop at first non true
// Else go backward, ( asc and > ) or (des and < )
SearchResult Search4(
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

	bool (*Compare)(int, int, SearchType, SearchResult&, bool&);

	switch (type)
	{
	case LessThan:
		Compare = &LessThanCmp;
		break;
	case LessThanEquals:
		Compare = &LessThanEqualsCmp;
		break;
	case Equals:
		Compare = &EqualsCmp;
		break;
	case GreaterThan:
		Compare = &GreaterThanCmp;
		break;
	case GreaterThanEquals:
		Compare = &GreaterThanEqualsCmp;
		break;
	default:
		return NotFound;
	}

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
	SearchResult result = NotFound;

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
