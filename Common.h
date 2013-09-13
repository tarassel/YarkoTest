#pragma once
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
