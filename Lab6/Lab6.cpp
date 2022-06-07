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
		/*for (std::vector<int>::iterator iter = v.begin(); iter != v.end() - 1; ++iter)
		{
			std::vector<int>::iterator maxValIter = iter;
			int maxVal = *iter;
			for (std::vector<int>::iterator iter2 = iter + 1; iter2 != v.end(); ++iter2)
			{
				if (maxVal < *iter2)
				{
					maxValIter = iter2;
					maxVal = *iter2;
				}
			}
			int tmp = *iter;
			*iter = maxVal;
			*maxValIter = tmp;			
		}*/
	}
}