#include <iostream>
#include <math.h>
using namespace std;

//2. ����������� ����� ? ? ? distance(? ? ? ), ������� ���������� ���������� �� ��������� �����;
//3. �������� ������� ? ? ? distance(? ? ? ), ������� ���������� ���������� ����� ����� �������;
//2.3.1 �������������� ����� � ������� distance() ����� �������, ����� ��� �� ��������� ������ ��������;

//��� �� ����� � ������� �� ��������� ������ �������� , �����������
//�������� �� ������ ���� �������� �� ��� ��������� �������

class Point {

	double x;
	double y;

public:

	double getX()const
	{
		return x;
	}
	double getY()const
	{
		return y;
	}
	void setX(double x)
	{
		this->x = x;
	}
	void setY(double y)
	{
		this->y = y;
	}

	//Point()  
	//{
	//	//this ->x = 0;   //����������� �� ���������
	//	//this ->y = 0;	//�������������� ���������� �������� ���������� 
	//	x = y = double(); // ����� � ���,��� ��� �������� �� ��������� ��� ���������� ���� double = 0;
	//	cout << "Constructor1:\t" << this << endl;
	//}
	//Point(double x)  //����������� � 1 ����������
	//{
	//	this->x = x;
	//	this->y = 0;
	//	cout << "1argConstructor:" << this << endl;
	//}
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:" << this << endl;
	}

	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	double Distance(Point& other)const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(pow((x_distance), 2) + pow((y_distance), 2));
		return distance;
	}
	void Print()
	{
		cout << " X = " << x << "\t" << " Y = " << y << endl;
	}

};

double Distance(const Point& a, const Point& b)
{
	double x_distance = a.getX() - b.getX();
	double y_distance = a.getY() - b.getY();
	double distance = sqrt(pow(x_distance, 2) + pow(y_distance, 2));
	return distance;
}

#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(0, "");

#ifdef DISTANCE_CHECK
	Point A;
	A.setX(2);
	A.setY(3);
	cout << A.getX() << "\t" << A.getY() << endl;

	Point B = A;
	/*B.setX(7);
	B.setY(8);*/
	cout << B.getX() << "\t" << B.getY() << endl;

	cout << "���������� �� �����: � �� ����� �:\t " << A.Distance(B) << endl;
	cout << "���������� �� �����: � �� ����� �:\t " << B.Distance(A) << endl;
	cout << "���������� ����� ������� � � �:\t\t " << Distance(A, B) << endl;
	cout << "����������  ����� ������� � � �:\t " << Distance(B, A) << endl;

#endif // DISTANCE_CHECK

#ifdef CONSTRUCTORS_CHECK
	Point A;
	A.Print();

	Point B{ 5 };
	B.Print();

	Point C(8);
	C.Print();

	Point D(5, 8);
	D.Print();

	Point E = D;
	E.Print(); //����������� �����������

#endif // CONSTRUCTORS_CHECK
}