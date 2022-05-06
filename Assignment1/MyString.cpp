#include "MyString.h"
#include <stdio.h>

namespace assignment1
{
    MyString::MyString(const char* s)
    {
        size_t len = 0;
        const char* c = s;
        while (*c++ != '\0') {
            len++;
        }
        mStr = new char[len + 1];
        sprintf(mStr, "%s", s);       
    }

    MyString::MyString(const MyString& other)
    {
        size_t len = other.GetLength();
        mStr = new char[len + 1];
        int i = 0;
        sprintf(mStr, "%s", other.GetCString());
    }

    MyString::~MyString()
    {
        delete mStr;
        mStr = nullptr;
    }

    unsigned int MyString::GetLength() const
    {
        const char* ch = this->mStr;
        size_t len = 0;
        while (*ch++ != '\0') {
            len++;
        }

        return len;
    }

    const char* MyString::GetCString() const
    {
        return mStr;
    }

    void MyString::Append(const char* s)
    {
        /*const char* ch = s;
        size_t len = 0;
        while (*ch++ != '\0') {
            len++;
        }
        
        int newLen = this->GetLength() + len + 1;
        int thisLen = this->GetLength();
        char* tmp = new char[newLen];       

        int idx = 0;
        for (int i = 0; i < thisLen; i++) {
            this->str[idx++] = tmp[i];
        }
        for (int i = 0; i < len; i++) {
            this->str[idx++] = s[i];
        }
        this->str[newLen - 1] = '\0';
        */
    }

    MyString MyString::operator+(const MyString& other) const
    {
        return MyString("temporary");
    }

    int MyString::IndexOf(const char* s)
    {
        const char* idx = this->mStr;
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
        const char* ch = s;
        size_t len = 0;
        while (*ch++ != '\0') {
            len++;
        }
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
        char* s = mStr;
        char* n = &(mStr[this->GetLength() - 1]);
        while (s < n) {
            char tmp = *s;
            *s = *n;
            *n = tmp;
            s++;
            n--;
        }
    }

    bool MyString::operator==(const MyString& rhs) const
    {
        const char* s = mStr;
        const char* n = rhs.GetCString();
        while (*s == '\0') {
            if (*s++ != *n++) {
                return false;
            }
        }
        return true;
    }

    MyString& MyString::operator=(const MyString& rhs)
    {
        return *this;
    }

    void MyString::ToLower()
    {
        char* s = mStr;       
        while (*s != '\0') {
            if (65 <= *s && 90 >= *s) {
                *s |= 0x20;               
            }     
            s++;
        }
    }

    void MyString::ToUpper()
    {
        char* s = mStr;
        while (*s != '\0') {
            if (97 <= *s && 122 >= *s) {
                *s &= ~0x20;               
            }     
            s++;
        }
    }
}