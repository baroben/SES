#include <iostream>
using namespace std;

class Date {
private:
	int day;
	int month;
	int year;
public:
	Date(int m, int d, int y) : month{ m }, day{ d }, year{ y } {}
	Date(int m, int d) : month{ m }, day{ d }, year{ 2023 } {}
	void print(void) { cout << "(" << month << "-" << day << "-" << year << ")"; }
};


class Period {
private:
	Date dateStart;
	Date dateEnd;
public:
	Period(Date s, Date e) : dateStart{ s }, dateEnd{ e } {}
	void print() {
		dateStart.print();
		cout << '-';
		dateEnd.print();
	}
};


class Counter {
private:
	int counter_value;
public:
	Counter() : counter_value{ 0 } {
		
	}
	void tick() {
		++counter_value;
	}
	void reset() {
		counter_value = 0; 
	}
	int get() {
		return counter_value;
	}
};

class Adder {
private:
	int sum;
public:
	Adder() : sum{ 0 } {}
	void add(int n) { sum += n; }
	void reset_sum() { sum = 0; }
	int get_sum() { return sum; }
};


class Account {
private:
	double saldo;
	static double interest_rate;

public:
	Account() : saldo{ 0 } {}
	Account(double s) : saldo{ s } {}
	void deposit(double value) { saldo += value; }
	void withdraw(double value) { saldo -= value; }
	void add_interest(double value) { interest_rate += value; }
	double get_saldo() { return saldo; }
};

double Account::interest_rate = 1;

class Point {
private:
	int x;
	int y;
public:
	Point(int x, int y) : x{ x }, y{ y } {}
	Point() : x{ 0 }, y{ 0 } {}
	int get_x() { return x; }
	int get_y() { return y; }
	void print() { cout << '(' << x << ',' << y << ')'; }
	void move(int x_displacement, int y_displacement) { x += x_displacement; y += y_displacement; }
	double distance_to_0() { return sqrt(pow(x,2) + pow(y,2));}
	double distance_to_point(Point p) { return sqrt(pow(p.x - x,2) + pow(p.y - y,2)); }
};

class Rectangle {
private:
	Point anchor; //top right corner
	double length;
	double width;
public:
	Rectangle(Point anch, double len, double wid) : anchor(anch), length(len), width(wid) {}
	Rectangle(Point topLeft, Point topRight, Point botRight, Point botLeft) : anchor(topLeft), length(topLeft.distance_to_point(botLeft)), width(topLeft.distance_to_point(topRight)) {}

	double area() {
		return length * width;
	}
	double circumference() {
		return length * 2 + width * 2;
	}
	void print_corners() {
		cout << "point 1 : (" << anchor.get_x() << "," << anchor.get_y() << ")" << endl;
		cout << "point 2 : (" << anchor.get_x() + width << "," << anchor.get_y() << ")" << endl;
		cout << "point 3 : (" << anchor.get_x() + width << "," << anchor.get_y() - length << ")" << endl;
		cout << "point 4 : (" << anchor.get_x() << "," << anchor.get_y() - length << ")" << endl;
	}
};

int main(void) {
	/*Date today(9, 1), tomorrow(9, 2);
	today.print();
	cout << endl;
	tomorrow.print();
	cout << endl;*/

	/*Counter c1, c2;
	cout << "C1 value : " << c1.get() << endl;
	c2.tick();
	cout << "C2 value : " << c2.get() << endl;
	c2.reset();
	cout << "C2 value after reset : " << c2.get() << endl;*/

	/*Adder a1;
	a1.add(6);
	a1.add(4);
	cout << "A1 value : " << a1.get_sum() << endl;
	a1.reset_sum();
	cout << "A1 value : " << a1.get_sum() << endl;
	Account acc1(110.0), acc2(90.0);
	acc1.add_interest(7.0);*/

	double value;
	cin >> value;
	Account a1(value), a2(400);
	a1.add_interest(3);
	cout << a1.get_saldo() << endl;

	/*Point p1(0, 1), p2(1, 2);
	cout << "P1 coord. : ";
	p1.print();
	cout << endl;
	cout << "P2 coord. : ";
	p2.print();
	cout << endl;
	cout << "Distance between P1 and P2 : " << p1.distance_to_point(p2) << endl;

	Rectangle rec(p1, 2, 4);
	rec.print_corners();*/

	return 0;
}
