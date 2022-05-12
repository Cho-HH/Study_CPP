#include "Lab2.h"
#include <cstdio>
#include <iomanip>
#include <cfloat>
#include <cstring>

using namespace std;

namespace lab2
{
	const int SIZE = 256;
	const char delims[] = " \t";
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		out << setw(12) << "oct";
		out << setw(11) << "dec";
		out << setw(9) << "hex" << endl;
		out << setfill('-') << setw(12) << "-";
		out << " " << setw(10) << "-";
		out << " " << setw(8) <<  "-" << endl;
		out << setfill(' ');

		char str[SIZE] = { 0, };	
		while (true)
		{
			in.getline(str, SIZE);
			int num = 0;			
			char* token = strtok(str, delims);
			
			while (token != nullptr)
			{
				if (sscanf(token, "%d", &num) == 1)
				{
					out << setw(12) << right << oct << num;
					out << setw(11) << right << dec << num;
					out << setw(9) << right << hex << uppercase << num << endl;
				}
				token = strtok(nullptr, delims);
			}
			
			if (in.eof())
			{
				break;
			}
			in.clear();
		}
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		char str[SIZE] = { 0, };
		float maxNum = -FLT_MIN;
		while (true)
		{
			in.getline(str, SIZE);
			float num = 0;
			char* token = strtok(str, delims);
			while (token != nullptr)
			{
				if (sscanf(str, "%f", &num) == 1)
				{
					out << "     " << setw(15) << showpos << internal << showpoint << fixed << setprecision(3) << num << endl;
					if (maxNum < num)
					{
						maxNum = num;
					}
				}
				token = strtok(nullptr, delims);
			}
			
			if (in.eof())
			{
				break;
			}
			in.clear();
		}
		out << setw(5) << left << "max:" << setw(15) << showpos << internal << showpoint << fixed << setprecision(3) << maxNum << endl;
	}
}