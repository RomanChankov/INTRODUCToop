#include<iostream>
using  namespace std;

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
	Fraction(int integer)
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

};

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

ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.getInt())
		os << obj.getInt() << " ";
	if (obj.getNum())
	{
		os << obj.getNum() << "/" << obj.getDen();
	}
	else os << 0;
	cout << endl;
	return os;
}
istream& operator >>(istream& input, Fraction& other)
{
	int integer, num, den;
	input >> integer >> num >> den;
	other.setInt(integer);
	other.setNum(num);
	other.setDen(den);
	return input;
}

//#define CONSTRUCTORS_CHECK
//#define ARIPHMETICAL_OPERATORS_CHECK
//#define INCREMENT_CHECK

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

#ifdef ARIPHMETICAL_OPERATORS_CHECK
	Fraction A{ 2,3,4 };
	Fraction B{ 3,4,5 };
	Fraction C = A / B;
	C.print();

	A *= B;
	A.print();
	A /= B;
	A.print();
#endif // ARIPHMETICAL_OPERATORS_CHECK

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

	Fraction A;
	cout << "Введите обыкновенную дробь: ";
	cin >> A;
	cout << A << endl;

}
