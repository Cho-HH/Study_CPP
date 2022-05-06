#include <iostream>
#include "MyString.h"

using namespace assignment1;
using namespace std;
int main()
{
	MyString s("Hello");
	int len = s.GetLength();
	cout << len << endl;
	s.Append("QQQ");
	cout << s.GetCString() << endl;
	MyString st = "hello World";
	MyString str = "FLURRY GaEMOTAE";
	str.ToLower();
	st.ToUpper();
	cout << str.GetCString() << endl;
	cout << st.GetCString() << endl;
	str.Reverse();
	cout << str.GetCString() << endl;
	return 0;
}