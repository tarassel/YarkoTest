#pragma once
#include "Common.h"

// Iterate up to where needed

// If ( asc and < ) or (des and > ) then go forward and stop at first non true
// Else go backward, ( asc and > ) or (des and < )
SearchResult Search2(
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
