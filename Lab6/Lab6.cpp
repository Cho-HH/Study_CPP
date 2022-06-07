#include "Lab6.h"
#include <map>
#include <climits>

namespace lab6
{
	int Sum(const std::vector<int>& v)
	{
		int sum = 0;
		for (std::vector<int>::const_iterator iter = v.begin(); iter != v.end(); ++iter)
		{
			sum += *iter;
		}
		return sum;
	}

	int Min(const std::vector<int>& v)
	{
		if (v.empty())
		{
			return INT_MAX;
		}

		int minVal = INT_MAX;
		for (std::vector<int>::const_iterator iter = v.begin(); iter != v.end(); ++iter)
		{
			if (minVal > *iter)
			{
				minVal = *iter;
			}
		}
		return minVal;
	}

	int Max(const std::vector<int>& v)
	{
		if (v.empty())
		{
			return INT_MIN;
		}

		int maxVal = INT_MIN;
		for (std::vector<int>::const_iterator iter = v.begin(); iter != v.end(); ++iter)
		{
			if (maxVal < *iter)
			{
				maxVal = *iter;
			}
		}
		return maxVal;
	}

	float Average(const std::vector<int>& v)
	{
		if (v.empty())
		{
			return 0.0f;
		}

		int total = 0;
		for (std::vector<int>::const_iterator iter = v.begin(); iter != v.end(); ++iter)
		{
			total += *iter;
		}
		return static_cast<float>(total) / static_cast<float>(v.size());
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		if (v.empty())
		{
			return 0;
		}

		std::map<int, int> map;
		std::pair<std::map<int, int>::iterator, bool> pr;

		for (std::vector<int>::const_iterator iter = v.begin(); iter != v.end(); ++iter)
		{
			pr = map.insert(std::pair<int, int>(*iter, 1));
			if (!pr.second)
			{
				map[*iter]++;
			}
		}

		int maxCnt = 0;
		int maxVal = 0;
		for (std::map<int, int>::iterator iter = map.begin(); iter != map.end(); ++iter)
		{
			if (maxCnt < iter->second)
			{
				maxCnt = iter->second;
				maxVal = iter->first;
			}
		}
		return maxVal;
	}

	void SortDescending(std::vector<int>& v)
	{
		QuickSortRecursive(v, 0, v.size() - 1);
	}

	void QuickSortRecursive(std::vector<int>& v, int left, int right)
	{
		if (left >= right)
		{
			return;
		}

		int pivotPos = Partition(v, left, right);
		QuickSortRecursive(v, left, pivotPos - 1);
		QuickSortRecursive(v, pivotPos + 1, right);
	}
	int Partition(std::vector<int>& v, int left, int right)
	{
		int pivot = v[right];

		int i = left;
		for (int j = left; j < right; j++)
		{
			if (v[j] > pivot)
			{
				int tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
				i++;
			}
		}

		int tmp = v[right];
		v[right] = v[i];
		v[i] = tmp;
		return i;
	}
}