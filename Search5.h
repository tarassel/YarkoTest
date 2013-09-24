#pragma once
#include "Common.h"
#include <set>
#include <functional>

// Sasha type

int gnShift = 0;

const int GetElement(const int * const items, const int nPos)
{
	if (gnShift != 0)
		return items[gnShift - nPos];
	else
		return items[nPos];
}

// Operates with ascending array
// Return best <= for searched key (-1 or last element position)
int SearchLowerBound(const int * const items, const int stopPos, const int key)
{
	int i = 0, nCounter = 0;
	while ( (i != stopPos) && (GetElement(items, i) <= key) )
	{
		i += 1;
		++nCounter;
	}

	printf ("Iterations taken %d.\n", nCounter);

	return i - 1;
}

SearchResult Search5(
	const int * const items,
	const int n_items,
	const int ascending,
	const int key,
	const SearchType type,
	int* const index)
{
	// Check if type is correct

	SearchResult result = NotFound;

	if ( ascending > 0 )
		gnShift = 0;
	else
		gnShift = n_items - 1;

	int nLowerBoundPos = SearchLowerBound(items, n_items, key);


	switch (type)
	{
	case LessThan:
		{
			if (nLowerBoundPos > 0)
			{
				*index = GetElement(items, nLowerBoundPos) < key ? nLowerBoundPos : nLowerBoundPos - 1;
				result = FoundLess;
			}
			else if (nLowerBoundPos == 0 && GetElement(items, nLowerBoundPos) < key)
			{
				*index = nLowerBoundPos;
				result = FoundLess;
			}
			break;
		}
	case LessThanEquals:
		{
			if (nLowerBoundPos >= 0)
			{
				*index = nLowerBoundPos;
				result = GetElement(items, nLowerBoundPos) == key ? FoundExact : FoundLess;
			}
			break;
		}
	case Equals:
		{
			if (nLowerBoundPos >= 0 && GetElement(items, nLowerBoundPos) == key)
			{
				*index = nLowerBoundPos;
				result = FoundExact;
			}
			break;
		}
	case GreaterThan:
		{
			if (nLowerBoundPos >= 0 && nLowerBoundPos < n_items - 1)
			{
				*index = nLowerBoundPos + 1;
				result = FoundGreater;
			}
			break;
		}
	case GreaterThanEquals:
		{
			if (nLowerBoundPos >= 0 && nLowerBoundPos < n_items - 1)
			{
				if (GetElement(items, nLowerBoundPos) == key)
				{
					*index = nLowerBoundPos;
					result = FoundExact;
				}
				else
				{
					*index = nLowerBoundPos + 1;
					result = FoundGreater;
				}
			}
			else if (nLowerBoundPos == n_items - 1 && GetElement(items, nLowerBoundPos) == key)
			{
				*index = nLowerBoundPos;
				result = FoundExact;
			}
			break;
		}
	}

	if (gnShift != 0)
		*index = gnShift - *index;
	
	return result;
}
