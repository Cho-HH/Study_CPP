#include "MyString.h"

namespace assignment1
{
	MyString::MyString(const char* s)
	{
		mStr = new char[getLength(s) + 1];
		const char* c = s;
		int i = 0;
		while (*c != '\0')
		{
			mStr[i++] = *c++;
		}
		mStr[i] = '\0';
	}

	MyString::MyString(const MyString& other)
	{
		mStr = new char[other.GetLength() + 1];
		const char* c = other.GetCString();
		int i = 0;
		while (*c != '\0')
		{
			mStr[i++] = *c++;
		}
		mStr[i] = '\0';
	}

	MyString::~MyString()
	{
		delete[] mStr;
		mStr = nullptr;
	}

	unsigned int MyString::GetLength() const
	{
		const char* ch = mStr;
		size_t len = 0;
		while (*ch++ != '\0')
		{
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
		if (*s == '\0') 
		{
			return;
		}
		size_t len = this->GetLength() + getLength(s);
		char* tmp = new char[len + 1];
		const char* c = mStr;
		const char* ns = s;
		size_t i = 0;
		for (; i < len; i++)
		{
			if (*c != '\0')
			{
				tmp[i] = *c++;
				continue;
			}
			tmp[i] = *ns++;
		}
		tmp[i] = '\0';
		delete[] mStr;
		mStr = tmp;
	}

	MyString MyString::operator+(const MyString& other) const
	{
		if (other.GetLength() == 0)
		{
			return MyString(this->GetCString());
		}

		size_t len = this->GetLength() + other.GetLength();
		char* tmp = new char[len + 1];
		 const char* c = mStr;
		const char* nc = other.GetCString();
		size_t i = 0;
		while (*c != '\0')
		{
			tmp[i++] = *c++;
		}
		while (*nc != '\0')
		{
			tmp[i++] = *nc++;
		}
		tmp[i] = '\0';		
		MyString newStr = MyString(tmp);
		delete[] tmp;
		return newStr;
	}

	int MyString::IndexOf(const char* s)
	{
		if (getLength(s) == 0)
		{
			return 0;
		}

		const char* c = nullptr;
		const char* check = s;
		for (size_t i = 0; i < this->GetLength(); i++)
		{
			if (mStr[i] == *check)
			{
				c = mStr + i;
				while (*check != '\0') 
				{
					if (*c != *check) 
					{
						goto outer;
					}
					c++;
					check++;
				}
				return static_cast<int>(i);
			outer:
				check = s;
			}			
		}
		return -1;
	}

	int MyString::LastIndexOf(const char* s)
	{
		if (getLength(s) == 0)
		{
			return this->GetLength();
		}

		const char* c = nullptr;
		const char* check = s + getLength(s) - 1;
		for (int i = this->GetLength() - 1; i >= 0; i--)
		{
			if (mStr[i] == *check)
			{
				c = mStr + i;
				while (check != s)
				{
					if (*c != *check)
					{
						goto outer;
					}
					c--;
					check--;
				}
				if (*check == *c) 
				{
					return i - (getLength(s) - 1);
				}				
			outer:
				check = s + getLength(s) - 1;
			}
		}
		return -1;
	}

	void MyString::Interleave(const char* s)
	{
		if (getLength(s) == 0)
		{
			return;
		}
		size_t len = this->GetLength() + getLength(s);
		char* tmp = new char[len + 1];
		const char* c1 = mStr;
		const char* c2 = s;
		bool bCheck = true;
		size_t i = 0;
		for (; i < len; i++)
		{
			if (*c2 == '\0')
			{
				bCheck = true;
			}
			else if (*c1 == '\0')
			{
				bCheck = false;
			}


			if (bCheck)
			{
				tmp[i] = *c1++;
				bCheck = false;
			}
			else
			{
				tmp[i] = *c2++;
				bCheck = true;
			}
		}
		tmp[i] = '\0';
		delete[] mStr;
		mStr = tmp;
	}

	bool MyString::RemoveAt(unsigned int i)
	{
		size_t len = this->GetLength();
		if (i >= len) 
		{
			return false;
		}

		char* tmp = new char[len];
		size_t idx = 0;
		for (size_t j = 0; j < len; j++)
		{
			if (j == i)
			{
				continue;
			}
			tmp[idx++] = mStr[j];
		}
		tmp[idx] = '\0';
		delete[] mStr;
		mStr = tmp;
		return true;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
		if (totalLength <= this->GetLength())
		{
			return;
		}

		char* tmp = new char[totalLength + 1];
		size_t j = totalLength - this->GetLength();
		size_t i = 0;
		size_t idx = 0;
		for (; i < totalLength; i++)
		{
			if (i < j)
			{
				tmp[i] = ' ';
				continue;
			}
			tmp[i] = this->GetCString()[idx++];
		}
		tmp[i] = '\0';
		delete[] mStr;
		mStr = tmp;
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		if (totalLength <= this->GetLength())
		{
			return;
		}

		char* tmp = new char[totalLength + 1];
		size_t j = totalLength - this->GetLength();
		size_t i = 0;
		size_t idx = 0;
		for (; i < totalLength; i++)
		{
			if (i < j)
			{
				tmp[i] = c;
				continue;
			}
			tmp[i] = this->GetCString()[idx++];
		}
		tmp[i] = '\0';
		delete[] mStr;
		mStr = tmp;
	}

	void MyString::PadRight(unsigned int totalLength)
	{
		if (totalLength <= this->GetLength())
		{
			return;
		}

		char* tmp = new char[totalLength + 1];
		size_t j = this->GetLength();
		size_t i = 0;
		for (; i < totalLength; i++)
		{
			if (i < j)
			{
				tmp[i] = this->GetCString()[i];
				continue;
			}
			tmp[i] = ' ';
		}
		tmp[i] = '\0';
		delete[] mStr;
		mStr = tmp;
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		if (totalLength <= this->GetLength())
		{
			return;
		}

		char* tmp = new char[totalLength + 1];
		size_t j = this->GetLength();
		size_t i = 0;
		for (; i < totalLength; i++)
		{
			if (i < j)
			{
				tmp[i] = this->GetCString()[i];
				continue;
			}
			tmp[i] = c;
		}
		tmp[i] = '\0';
		delete[] mStr;
		mStr = tmp;
	}

	void MyString::Reverse()
	{
		char* s = mStr;
		char* n = &(mStr[this->GetLength() - 1]);
		while (s < n)
		{
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
		while (*s != '\0')
		{
			if (*s++ != *n++) 
			{
				return false;
			}
		}

		if (*n == '\0')
		{
			return true;
		}
		return false;
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		if (rhs == *this)
		{
			return *this;
		}
	
		delete[] mStr;
		mStr = new char[rhs.GetLength() + 1];	
		const char* c = rhs.GetCString();
		int i = 0;
		while (*c != '\0')
		{
			mStr[i++] = *c++;
		}
		mStr[i] = '\0';
		return *this;
	}

	void MyString::ToLower()
	{
		char* s = mStr;
		while (*s != '\0')
		{
			if (65 <= *s && 90 >= *s)
			{
				*s |= 0x20;
			}
			s++;
		}
	}

	void MyString::ToUpper()
	{
		char* s = mStr;
		while (*s != '\0')
		{
			if (97 <= *s && 122 >= *s)
			{
				*s &= ~0x20;
			}
			s++;
		}
	}

	size_t MyString::getLength(const char* s) const
	{
		size_t len = 0;
		const char* c = s;
		while (*c++ != '\0')
		{
			len++;
		}
		return len;
	}
}