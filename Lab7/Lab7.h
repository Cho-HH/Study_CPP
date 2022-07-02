#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <string>
#include <cuchar>

namespace lab7
{
	template <typename K, class V>
	std::map<K, V> ConvertVectorsToMap(const std::vector<K>& keys, const std::vector<V>& values)
	{
		std::map<K, V> m;
		unsigned int len = std::min(keys.size(), values.size());
		auto keysIter = keys.begin();
		auto valuesIter = values.begin();
		for (unsigned int i = 0; i < len; i++)
		{
			m.insert(std::pair<K, V>(*keysIter++, *valuesIter++));
		}
		
		return m;
	}

	template <typename K, class V>
	std::vector<K> GetKeys(const std::map<K, V>& m)
	{
		std::vector<K> v;
		v.reserve(m.size());
		for (auto iter = m.begin(); iter != m.end(); iter++)
		{
			v.push_back(iter->first);
		}
		return v;
	}

	template <typename K, class V>
	std::vector<V> GetValues(const std::map<K, V>& m)
	{
		std::vector<V> v;
		v.reserve(m.size());
		for (auto iter = m.begin(); iter != m.end(); iter++)
		{
			v.push_back(iter->second);
		}
		return v;
	}

	template <typename T>
	std::vector<T> Reverse(const std::vector<T>& v)
	{
		std::vector<T> rv;
		rv.reserve(v.size());
		for (auto iter = v.rbegin(); iter != v.rend(); iter++)
		{
			rv.push_back(*iter);
		}
		return rv;
	}

	template <typename T>
	std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2)
	{
		std::vector<T> combined;
		std::set<T> s;
		for (auto iter = v1.begin(); iter != v1.end(); iter++)
		{			
			if (s.find(*iter) == s.end())
			{
				combined.push_back(*iter);
			}
			s.insert(*iter);
		}
		for (auto iter = v2.begin(); iter != v2.end(); iter++)
		{
			if (s.find(*iter) == s.end())
			{
				combined.push_back(*iter);
			}
			s.insert(*iter);
		}
		return combined;
	}

	template <typename K, class V>
	std::map<K, V> operator+(const std::map<K, V>& m1, const std::map<K, V>& m2)
	{
		std::map<K, V> combined;
		for (auto iter = m1.begin(); iter != m1.end(); iter++)
		{
			combined.insert(std::pair<K, V>(iter->first, iter->second));
		}
		for (auto iter = m2.begin(); iter != m2.end(); iter++)
		{
			combined.insert(std::pair<K, V>(iter->first, iter->second));
		}
		return combined;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
	{
		for (auto iter = v.begin(); iter != v.end(); iter++)
		{
			if (iter != v.begin())
			{ 
				os << ", ";
			}
			os << *iter;
		}
		return os;
	}

	template <typename K, class V>
	std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m)
	{
		const char16_t str[] = u"\u2936";
		mbstate_t state = { 0, };
		char tmp[64];
		char* p = tmp;
		for (int i = 0; i < 2; i++)
		{
			int num = c16rtomb(p, str[i], &state);
			p += num;
		}
		for (auto iter = m.begin(); iter != m.end(); iter++)
		{
			os << "{ " << iter->first << ", " << iter->second << " }" << tmp << std::endl;
		}
		return os;
	}
}