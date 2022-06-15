#include "Lab2.h"
#include <iomanip>

using namespace std;

namespace lab2
{
    void PrintIntegers(std::istream& in, std::ostream& out)
    {
        out << setw(12) << "oct" << setw(11) << "dec" << setw(9) << "hex" << endl;
        out << setw(13) << setfill('-') << ' ' << setw(11) << setfill('-') << ' ' << setw(8) << setfill('-') << '-' << endl;
        out << setfill(' ');
        char ignore[256] = { 0, };
        int num = 0;
        while (!in.eof())
        {
            in >> num;
            if (in.fail())
            {
                in.clear();
                in >> ignore;
                continue;
            }
            out << setw(12) << oct << num << setw(11) << dec << num << setw(9) << uppercase << hex << num << endl;
        }
    }

    void PrintMaxFloat(std::istream& in, std::ostream& out)
    {
        char ignore = { 0, };
        float num = 0.0f;
        float maxNum = 0.0f;
        while (!in.eof())
        {
            in >> num;
            if (in.fail())
            {
                in.clear();
                in >> ignore;
                continue;
            }
            out << setw(5) << ' ' << internal << showpos << showpoint << fixed << setprecision(3) << setw(15) << num << endl;
        }
    }
}