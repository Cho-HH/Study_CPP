#include "Lab2.h"
#include <cstdio>
#include <iomanip>
#include <cstring>

using namespace std;

namespace lab2
{
	const int SIZE = 256;
	const char DELIMS[] = " \t";
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		out << setw(12) << "oct";
		out << setw(11) << "dec";
		out << setw(9) << "hex" << endl;
		out << setfill('-') << setw(12) << "-";
		out << " " << setw(10) << "-";
		out << " " << setw(8) << "-" << endl;
		out << setfill(' ');

		char str[SIZE] = { 0, };
		while (true)
		{
			in.getline(str, SIZE);
			int num = 0;
			char* token = strtok(str, DELIMS);

			while (token != nullptr)
			{
				if (sscanf(token, "%d", &num) == 1)
				{
					out << setw(12) << right << oct << num;
					out << setw(11) << right << dec << num;
					out << setw(9) << right << hex << uppercase << num << endl;
				}
				token = strtok(nullptr, DELIMS);
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
		float maxNum = 0.0f;
		bool bMax = false;
		while (true)
		{
			in.getline(str, SIZE);
			float num = 0;
			char* token = strtok(str, DELIMS);
			while (token != nullptr)
			{
				if (sscanf(token, "%f", &num) == 1)
				{
					out << "     " << setw(15) << showpos << internal << showpoint << fixed << setprecision(3) << num << endl;
					if (!bMax)
					{
						maxNum = num;
						bMax = true;
					}
					else
					{
						if (maxNum < num)
						{
							maxNum = num;
						}
					}

				}
				token = strtok(nullptr, DELIMS);
			}

			if (in.eof())
			{
				break;
			}
			in.clear();
		}
		out << setw(5) << left << "max:" << setw(15) << showpos << internal << showpoint << fixed << setprecision(3) << maxNum << endl;
	}


	void test(std::istream& in, std::ostream& out)
		//다른 사람이 한거
	{
		out << setw(12) << "oct" << setw(11) << "dec" << setw(9) << "hex" << endl;

		out << setfill('-');

		out << setw(13) << ' ' << setw(11) << ' ' << setw(9) << '\n';

		out << setfill(' ');

		int num;
		string discard;

		while (true)
		{
			in >> num;

			if (!in.fail())
			{
				out << setw(12) << oct << num << setw(11) << dec << num << setw(9) << hex << uppercase << num << endl;
				continue;
			}

			if (in.eof())
			{
				break;
			}

			in.clear();
			in >> discard;
		}
	}
}