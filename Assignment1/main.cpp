#include <iostream>
#include <string>
#include <cassert>

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

	assignment1::MyString my1("pope pope");
	std::string s1("pope pope");

	const char* cString = my1.GetCString();
	assignment1::MyString copied(my1);

	// E0, E1
	assert(my1.IndexOf("p") == s1.find("p"));
	assert(my1.LastIndexOf("p") == s1.rfind("p"));

	assert(my1.IndexOf("pop") == s1.find("pop"));
	my1.LastIndexOf("sop");
	assert(my1.LastIndexOf("pop") == s1.rfind("pop"));

	assert(my1.IndexOf("popen") == s1.find("popen"));

	assert(my1.LastIndexOf("popen") == s1.rfind("popen"));

	assert(my1.IndexOf("pope pope love") == s1.find("pope pope love"));
	assert(my1.LastIndexOf("pope pope love") == s1.rfind("pope pope love"));

	assert(my1.IndexOf(" pope") == s1.find(" pope"));
	assert(my1.LastIndexOf("pope ") == s1.rfind("pope "));

	cout << s1.find("") << endl;
	cout << s1.rfind("") << endl;
	cout << my1.LastIndexOf("") << endl;
	// E2, E3
	assert(my1.IndexOf("") == s1.find(""));
	assert(my1.LastIndexOf("") == s1.rfind(""));


	/* PadRight() Ex */
	cout << "-----------------------" << endl;
	cout << "PadRight()" << endl;
	MyString s10("Hello");
	s10.PadRight(2);  // "Hello"
	cout << s10.GetCString() << endl;
	s10.PadRight(8);  // "Hello   "
	cout << s10.GetLength() << endl;
	cout << s10.GetCString() << '|' << endl;// 공백 확인 위한 |

	MyString s102("World");
	s102.PadRight(3, '-');  // "World"
	cout << s102.GetCString() << endl;
	s102.PadRight(7, '-');  // "World--"
	cout << s102.GetCString() << endl;


	/* PadLeft() Ex */
	cout << "-----------------------" << endl;
	cout << "PadLeft()" << endl;
	MyString s9("Hello");
	s9.PadLeft(2);  // "Hello"
	cout << s9.GetCString() << endl;
	s9.PadLeft(8);  // "   Hello"
	cout << s9.GetCString() << endl;

	MyString s92("World");
	s92.PadLeft(3, '-');  // "World"
	cout << s92.GetCString() << endl;
	s92.PadLeft(7, '-');  // "--World"
	cout << s92.GetCString() << endl;


	/* RemoveAt() Ex */
	cout << "-----------------------" << endl;
	cout << "RemoveAt()" << endl;
	MyString s8("Hello");
	cout << boolalpha << s8.RemoveAt(0) << ", ";   // true,
	cout << s8.GetCString() << endl;               // ello
	cout << boolalpha << s8.RemoveAt(2) << ", ";   // true,
	cout << s8.GetCString() << endl;               // elo
	cout << boolalpha << s8.RemoveAt(4) << ", ";   // false,
	cout << s8.GetCString() << endl;               // elo


	/* operator+ Ex */
	cout << "-----------------------" << endl;
	cout << "operator+" << endl;
	MyString s41("Hello");
	MyString s42(" World");
	MyString s43 = s41 + s42;
	//s2 = s2 + s1;  소멸자 오류(이번 과제에서는 체크하지 않음)
	cout << s43.GetCString() << endl;   //Hello World
	cout << s41.GetCString() << endl;
	cout << s42.GetCString() << endl;

	MyString s44("Flurry");
	MyString s45("");
	MyString s46 = s44 + s45;
	cout << s44.GetCString() << endl;
	cout << s45.GetCString() << endl;
	cout << s46.GetCString() << endl;


	/* Append() Ex */
	cout << "-----------------------" << endl;
	cout << "Append()" << endl;
	MyString s3("Hello");
	s3.Append(" World");
	cout << s3.GetCString() << endl;  // Hello World
	s3.Append("\n\tWorld\n");
	cout << s3.GetCString() << endl;


	cout << "-----------------------" << endl;
	cout << "Interleave()" << endl;
	MyString s7("Hello");
	s7.Interleave(" World");
	cout << s7.GetCString() << endl;  //H eWlolrold

	MyString s72("A");
	s72.Interleave("BCDEF");
	cout << s72.GetCString() << endl;  // ABCDEF

	MyString s73("bcdef");
	s73.Interleave("a");
	cout << s73.GetCString() << endl;  // bacdef

	MyString s74("");
	s74.Interleave("asd");
	cout << s74.GetCString() << endl;

	MyString s75("asd");
	s75.Interleave("");
	cout << s75.GetCString() << endl;


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