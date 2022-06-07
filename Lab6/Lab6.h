#pragma once

#include <vector>

namespace lab6
{
	int Sum(const std::vector<int>& v);
	int Min(const std::vector<int>& v);
	int Max(const std::vector<int>& v);
	float Average(const std::vector<int>& v);
	int NumberWithMaxOccurrence(const std::vector<int>& v);
	void SortDescending(std::vector<int>& v);

	void QuickSort(std::vector<int>& v);
	void QuickSortRecursive(std::vector<int>& v, int left, int right);
	int Partition(std::vector<int>& v, int left, int right);
}