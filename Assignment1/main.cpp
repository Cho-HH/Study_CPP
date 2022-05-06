#include <iostream>
#include "MyString.h"

using namespace assignment1;
using namespace std;
int main()
{
	MyString s("Hello");
	int len = s.GetLength();
	cout << len << endl;
	const char* str = s.GetCString();
	s.Append("QQQ");
	cout << s.GetCString() << endl;
	return 0;
}