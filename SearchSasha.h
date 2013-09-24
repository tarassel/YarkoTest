#pragma once
#include "Common.h"

const int* lower_bound(const int* begin, const int* end, int step, int val)
{
	int nCounter = 0;
	for (const int* i = begin; i != end; i += step)
	{
		++nCounter;
		if (!(*i < val)) 
		{
			printf ("Iterations taken by Sasha %d.\n", nCounter);
			return i;
		}
	}

	printf ("Iterations taken by Sasha %d.\n", nCounter);

	return end;
}

SearchResult Search6(
	const int * const items,
	const int n_items,
	const int ascending,
	const int key,
	const SearchType type,
	int* const index)
{
	const int* begin;
	const int* end;
	int step;
	if (ascending)
	{
		begin = items;
		end = items + n_items;
		step = 1;
	}
	else
	{
		begin = items - 1;
		end = items + n_items - 1;
		step = -1;
	}

	const int* pos = lower_bound(begin, end, step, key);

	switch (type)
	{
	case LessThan:
		if (pos == begin)
			pos = end;
		else 
			pos -= step;
		break;
	case LessThanEquals:
		if (pos == end || *pos != key)
		{
			if (pos == begin)
				pos = end;
			else
				pos -= step;
		}
		break;
	case Equals:
		if (pos != end && *pos != key)
			pos = end;
		break;
	case GreaterThanEquals:
		// empty
		break;
	case GreaterThan:
		if (pos != end && *pos == key)
		{
			pos += step;
		}
		break;
	}

	*index = pos - items;

	if (pos == end)
		return NotFound;
	if (*pos == key)
		return FoundExact;
	if (type == LessThan || type == LessThanEquals)
		return FoundLess;
	return FoundGreater;
}