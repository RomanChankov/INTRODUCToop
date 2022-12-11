#include<iostream>
using namespace std;

class String
{
	size_t  size;
	char* str;	//Адрес строки в динамической памяти
public:
	

	explicit String(size_t size=80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "Конструктор:" << this << endl;
	}

	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i=0;i<size;i++)
		{
			this->str[i] = str[i];
		}
		cout << "Конструктор:\t" << this << endl;
	}
	
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "Copy\t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Деструктор:\t" << this << endl;
	}

	

	//		Methods
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};


void main()
{
	setlocale(0, "");

	String str1 = "Hello";
	str1.print();

	String str2 = "World";
	str1.print();

	//ring str3 = str2;
	//r3.print();


	/*String str3;
	str3 = str1 + str2;
	cout << str3 << endl;*/
}


