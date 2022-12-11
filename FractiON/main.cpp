#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using  namespace std;
using std::cin;
using std::cout;


//1. В классе Fraction написать метод ? ? ? reduce(? ? ? ) который сокращает дробь;
//2. Для класса Fraction перегрузить;
//-Арифметические операторы : +, -, *, / ;
//-Increment / Decrement(++ / --);
//-Оператор присваивания;
//-Составные присваивания : +=, -=, *=, /=;
//-Операторы сравнения : == , != , > , < , >= , <= ;


#define WIDTH 26
class Fraction;
Fraction operator *(Fraction left, Fraction right);
Fraction operator /(const Fraction& l, const Fraction& r);
Fraction operator +(const Fraction& l, const Fraction& r);
Fraction operator -(const Fraction& l, const Fraction& r);

class Fraction
{
	int integer;
	int num;
	int den;
public:
	int getInt()const
	{
		return integer;
	}
	int getNum()const
	{
		return num;
	}
	int getDen()const
	{
		return den;
	}

	void setInt(int integer)
	{
		this->integer = integer;
	}
	void setNum(int num)
	{
		this->num = num;
	}
	void setDen(int den)
	{
		if (den == 0)
			den = 1;
		this->den = den;
	}


	////Конструктор копирования
	////Fraction(const Fraction& other):
	// Fraction( Fraction& other)//:
	//	/*integer{other.integer},
	//	num{other.num},
	//	den{other.den}*/
	//{
	//	// other.integer += other.integer;
	//	 integer = other.integer;
	//	 num = other.num;
	//	 den = other.den;
	//	cout.width(WIDTH);
	//	cout << left << "Конструктор копирования:" << this << endl;
	//}

	Fraction()
	{
		this->integer = 0;
		this->num = 0;
		setDen(den);
		cout.width(WIDTH);
		cout << left << "Конструктор без пар:" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->num = 0;
		setDen(den);
		cout.width(WIDTH);
		cout << left << "Конструктор с 1 пар:" << this << endl;
	}

	Fraction(int num, int den)
	{
		integer = 0;
		this->num = num;
		this->den = den;
		cout.width(WIDTH);
		cout << left << "Конструктор с 2 пар:" << this << endl;
	}
	Fraction(int integer, int num, int den)
	{
		this->integer = integer;
		this->num = num;
		this->den = den;
		cout.width(WIDTH);
		cout << left << "Конструктор с 3 пар:" << this << endl;
	}
	~Fraction()
	{
		cout.width(WIDTH);
		cout << left << "Деструктор:" << this << endl;
	}
	Fraction& toProper()
	{
		integer += num / den;
		num %= den;
		return *this;
	}
	Fraction& toInProper()
	{
		num += integer * den;
		integer = 0;
		return *this;
	}

	Fraction& reduce()	//Сокращение дроби
	{
		if (num == 0)
			return *this;
		int more, less, remainder;

		if (num > den)
		{
			more = num;
			less = den;
		}
		else
		{
			less = num;
			more = den;
		}
		do
		{
			remainder = more % less;
			more = less;
			less = remainder;
		} while (remainder);
		int NOD = more;
		num /= NOD;
		den /= NOD;
		return *this;
	}

	Fraction inverted()const	//Обращение дроби
	{
		Fraction inv = *this;
		inv.toInProper();
		swap(inv.num, inv.den);
		return inv;
		//return Fraction(den, num);

	}

	Fraction& operator()(int integer, int num, int den)
	{
		setInt(integer);
		setNum(num);
		setDen(den);
		return *this;
	}

	Fraction& operator =(const Fraction& other)
	{
		this->integer = other.integer;
		this->num = other.num;
		this->den = other.den;
		cout.width(WIDTH);
		cout << left << "Copy:" << this << endl;
		return *this;
	}
	Fraction& operator *=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}
	Fraction& operator +=(const Fraction& other)
	{
		return *this = *this + other;
	}
	Fraction& operator -=(const Fraction& other)
	{
		return *this = *this - other;
	}
	bool operator==(const Fraction& other)
	{
		return this->integer == other.integer && this->num == other.num && this->den == other.den;
	}
	bool operator!=(const Fraction& other)
	{
		return !(this->integer == other.integer && this->num == other.num && this->den == other.den);
	}

	//INCREMENT/DECREMENT
	Fraction& operator ++() //Prefix
	{
		integer++;
		return *this;
	}
	Fraction& operator --()
	{
		integer--;
		return *this;
	}
	Fraction operator ++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction operator --(int)
	{
		Fraction old = *this;
		integer--;
		return old;
	}

	void print()const
	{
		if (integer)
			cout << integer << " ";
		if (num)
			cout << num << "/" << den << endl;
		else if (integer == 0)
			cout << 0;
		cout << "\n";
	}

	//				Type-cast operators
	explicit operator int()const
	{
		return integer;
	}
	explicit operator double()const
	{
		//return ((double)integer * (double)den + (double)num) / (double)den;
		return (integer * (double)den + num) / den;
		
	}

};

bool operator <(Fraction l, Fraction r)
{
	return (l.toInProper().getNum() * r.toInProper().getDen() <
		r.toInProper().getNum() * l.toInProper().getDen());
}

bool operator >(Fraction l, Fraction r)
{
	return (l.toInProper().getNum() * r.toInProper().getDen() >
		r.toInProper().getNum() * l.toInProper().getDen());
}
bool operator >=(Fraction l, Fraction r)
{
	return l > r || l == r;
}
bool operator <=(Fraction& l, Fraction& r)
{
	return l < r || l == r;
}
//Перегрузка (*):
Fraction operator *(Fraction left, Fraction right)
{
	left.toInProper();
	right.toInProper();
	/*Fraction res;
	res.setNum(left.getNum() * right.getNum());
	res.setDen(left.getDen() * right.getDen());
	res.toProper();
	return res;*/

	/*Fraction res(left.getNum() * right.getNum(), //Через конструктор
		left.getDen() * right.getDen());
	res.toProper();
	return res;*/

	return Fraction(left.getNum() * right.getNum(), //Через временный безымянный объект
		left.getDen() * right.getDen()).toProper().reduce();
}
//Перегрузка(/)
Fraction operator /(const Fraction& l, const Fraction& r)
{
	/*l.toInProper();
	r.toInProper();
	return Fraction(l.getNum() * r.getDen(),
		l.getDen() * r.getNum()).toProper();*/
	return l * r.inverted();
}

Fraction operator +(const Fraction& l, const Fraction& r)
{
	return Fraction
	(l.getInt() + r.getInt(),
		l.getNum() * r.getDen() + r.getNum() * l.getDen(),
		l.getDen() * r.getDen()
	).reduce().toProper();
}

Fraction operator -(const Fraction& l, const Fraction& r)
{
	return Fraction
	(l.getInt() - r.getInt(),
		l.getNum() * r.getDen() - r.getNum() * l.getDen(),
		l.getDen() * r.getDen()
	).reduce().toProper().toInProper();
}
istream& operator >>(istream& input, Fraction& other)
{
	other = Fraction();
	//int integer, num, den;
	//input >> integer >> num >> den;
	/*other.setInt(integer);
	other.setNum(num);
	other.setDen(den);*/
	//other(integer, num, den);
	int number[3] = {};//В этом массиве будут храниться числовые значения полученные из строки
	char delimiters[] = " /()";
	const int SIZE = 256;
	char buf[SIZE]{};
	int n = 0;// Счетчик полученных чисел
	input.getline(buf, SIZE);
	//Функция strtok делит строку на подстроки ,используя разделители,каждый ражделитель заменяется нулем
	for (char* pch = strtok(buf, delimiters); pch; pch = strtok(NULL, delimiters))
	{
		number[n++] = atoi(pch);// atoi()- функция Принимает строку и если строка явлчется числом то возвращает интовый
		// эквивалент этого числа
	}
	//cout << buf << endl;
	/*for (int i = 0; i < n; i++)
		cout << number[i] << "\t";
	cout << endl;*/
	switch (n)
	{
	case 1: other.setInt(number[0]);
		break;
	case 2:
		other.setNum(number[0]);
		other.setDen(number[1]);
		break;
	case 3:
		other.setInt(number[0]);
		other.setNum(number[1]);
		other.setDen(number[2]);

	}
	return input;

}

ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.getInt())
		os << obj.getInt() << " ";
	if (obj.getNum())
	{
		os << obj.getNum() << "/" << obj.getDen();
	}
	else if (obj.getInt()==0)
		os<<0;
	cout << endl;
	return os;
}

//#define CONSTRUCTORS_CHECK
//#define ARIPHMETICAL_OPERATORS_CHECK
//#define INCREMENT_CHECK
//#define COMPARISON_OPERATORS
//#define ISTREAM_OPERATOR_CHECK

void main()
{
	setlocale(0, "");
	cout << "Простая дробь:" << endl;
#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	cout << "Дробь : "; A.print();

	Fraction B{ 5 };
	cout << "Дробь : "; B.print();

	Fraction C{ 1,2 };
	cout << "Дробь : "; C.print();

	Fraction D{ 2,3,4 };
	cout << "Дробь : "; D.print();

	cout << "Перевод в неправильную:"; D.toInProper(); D.print();
	cout << "Перевод в правильную:"; D.toProper(); D.print();

	Fraction E{ D }; E.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ISTREAM_OPERATOR_CHECK
	Fraction A{ 50,75,80 };
	//Fraction B{ 1,1,7 };
	//Fraction A;
	cin >> A;
	cout << A << endl;
#endif // ISTREAM_OPERATOR_CHECK


#ifdef ARIPHMETICAL_OPERATORS_CHECK
	//Fraction C = A - B;
	//C.print();
	/*A *= B;
	A.print();
	A /= B;
	A.print();*/
#endif // ARIPHMETICAL_OPERATORS_CHECK

#ifdef COMPARISON_OPERATORS
	/*bool res = A == B;
if (res)
	cout << "Равны" << endl;
else
	cout << "Не равны" << endl;
bool res = A != B;
if (res)
	cout << " Не равны" << endl;
else
	cout << "Равны" << endl;
bool res = A < B;
if (res)
	cout << "A<B " << endl;
else
	cout << "A>B " << endl;
bool res = A > B;
if (res)
	cout << "A>B " << endl
else
cout << "A<B " << endl;*/
/*bool res = A >= B;
if (res)
	cout << "A>=B" << endl;
else
cout << "A<B" << endl;*/
/*bool res = A <= B;
if (res)
	cout << "A<=B" << endl;
else
cout << "A>B" << endl;*/
/*bool res = A == B;
cout << res << endl;*/
#endif // COMPARISON_OPERATORS


#ifdef INCREMENT_CHECK
					/*for (Fraction i(1, 2); i.getInt() < 10; i++)
					{
						i.print();
					}*/
	for (Fraction i(10, 1, 2); i.getInt() > 0; i--)
	{
		i.print();
	}

#endif // INCREMENT_CHECK

	
	//Fraction A{ 2,3,4 };
	////int a = A;
	//cout << A << endl << endl;
	//double b =(double) A;
	//cout <<b << endl;


	/*Fraction A=2.75;
	
	cout <<A << endl;*/


	
}
