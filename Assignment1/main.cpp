#include <iostream>
#include "MyString.h"

using namespace assignment1;
using namespace std;
int main()
{
	/*MyString s("Hello");
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
	cout << str.GetCString() << endl;*/

	cout << "-----------------------"  << "ToLower()" << endl;
	MyString s131("HEllo 123K");
	MyString s132("A To z");
	s131.ToLower();   // "hello 123k"
	s132.ToLower();   // "a to z"
	cout << s131.GetCString() << endl;
	cout << s132.GetCString() << endl;

	/* ToUpper() Ex */
	cout << "-----------------------" << endl;
	cout << "ToUpper()" << endl;
	MyString s141("HEllo 123K");
	MyString s142("A To z");
	s141.ToUpper();   // "HELLO 123K"
	s142.ToUpper();   // "A TO Z"
	cout << s141.GetCString() << endl;
	cout << s142.GetCString() << endl;

	return 0;
}