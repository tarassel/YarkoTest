#pragma once
#include "Common.h"

// Iterate from start to end and compare all values

SearchResult Search1(
	const int * const items,
	const int n_items,
	const int ascending,
	const int key,
	const SearchType type,
	int* const index)
{
	// Check if type is correct

	int nCounter = 0;
	int foundPos = -1;
	int i = ascending > 0 ? 0 : n_items - 1;
	int increment = ascending > 0 ? 1 : -1;
	int stopPos = ascending > 0 ? n_items : -1;
	SearchResult result = NotFound;

	while (i != stopPos)
	{
		nCounter++;
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
	printf ("Iterations taken %d.\n", nCounter);

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

