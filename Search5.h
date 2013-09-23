#pragma once
#include "Common.h"
#include <set>
#include <functional>

// Iterate up to where needed

// 
SearchResult Search5(
	const int * const items,
	const int n_items,
	const int ascending,
	const int key,
	const SearchType type,
	int* const index)
{
	// Check if type is correct

	std::less<int>;


	std::set<int> coll;

	for (int i=0; i<n_items; i++)
		coll.insert(items[i]);

	bool bContinue = true;
	std::set<int>::const_iterator pos = coll.begin();

	while (bContinue && pos != coll.end())
	{
		bContinue = iterate();
		pos++;
	}




	int nCounter = 0;
	bool bStop = false;
	int foundPosLast = -1;
	int i, increment, stopPos;

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
		switch (type)
		{
		case LessThan:
			{
				if (items[i] < key)
				{
					foundPosLast = i;
					result = FoundLess;
				}
				else
					bStop = true;
				break;
			}
		case LessThanEquals:
			{
				if (items[i] < key)
				{
					foundPosLast = i;
					result = FoundLess;
				}
				else if (items[i] == key)
				{
					foundPosLast = i;
					result = FoundExact;
					bStop = true;
				}
				else
					bStop = true;
				break;
			}
		case Equals:
			{
				if (items[i] == key)
				{
					foundPosLast = i;
					result = FoundExact;
					bStop = true;
				}
				else
					result = NotFound;
				break;
			}
		case GreaterThan:
			{
				if (items[i] > key)
				{
					foundPosLast = i;
					result = FoundGreater;
				}
				else
					bStop = true;
				break;
			}
		case GreaterThanEquals:
			{
				if (items[i] > key)
				{
					foundPosLast = i;
					result = FoundGreater;
				}
				else if (items[i] == key)
				{
					foundPosLast = i;
					result = FoundExact;
					bStop = true;
				}
				else
					bStop = true;
				break;
			}
		}

		i += increment;
	}

	printf ("Iterations taken %d.\n", nCounter);

	if ( foundPosLast != -1)
		*index = foundPosLast;
	
	return result;
}
