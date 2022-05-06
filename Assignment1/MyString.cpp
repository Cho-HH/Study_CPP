#include "MyString.h"

namespace assignment1
{
    MyString::MyString(const char* s)
    {
        this->str = s;
    }

    MyString::MyString(const MyString& other)
    {
    }

    MyString::~MyString()
    {

    }

    unsigned int MyString::GetLength() const
    {
        const char* ch = this->str;
        size_t len = 0;
        while (*ch++ != '\0') {
            len++;
        }

        return len;
    }

    const char* MyString::GetCString() const
    {
        return this->str;
    }

    void MyString::Append(const char* s)
    {
        const char* ch = s;
        size_t len = 0;
        while (*ch++ != '\0') {
            len++;
        }

        int newLen = this->GetLength() + len + 1;
        char* newStr = new char[newLen];
        int idx = 0;
        for (int i = 0; i < this->GetLength(); i++) {
            newStr[idx++] = this->GetCString()[i];
        }
        for (int i = 0; i < len; i++) {
            newStr[idx++] = s[i];
        }
        newStr[newLen - 1] = '\0';
        this->str = newStr;
        delete newStr;
    }

    MyString MyString::operator+(const MyString& other) const
    {
        return MyString("temporary");
    }

    int MyString::IndexOf(const char* s)
    {
        const char* idx = this->str;
        while (*idx++ != '\0') {

        }
        return -1;
    }

    int MyString::LastIndexOf(const char* s)
    {
        return 0;
    }

    void MyString::Interleave(const char* s)
    {
    }

    bool MyString::RemoveAt(unsigned int i)
    {
        return false;
    }

    void MyString::PadLeft(unsigned int totalLength)
    {
    }

    void MyString::PadLeft(unsigned int totalLength, const char c)
    {
    }

    void MyString::PadRight(unsigned int totalLength)
    {
    }

    void MyString::PadRight(unsigned int totalLength, const char c)
    {
    }

    void MyString::Reverse()
    {
    }

    bool MyString::operator==(const MyString& rhs) const
    {
        return false;
    }

    MyString& MyString::operator=(const MyString& rhs)
    {
        return *this;
    }

    void MyString::ToLower()
    {
        const char* s = this->str;
        while (*s++ != '\0') {

        }
    }

    void MyString::ToUpper()
    {
    }
}