#include <iostream>
#include <vector>
using namespace std;

class Shape
{
public:
	Shape(double ax, double ay) : anchor_x(ax), anchor_y(ay) {}
	virtual void print(void) {
		cout << "anchor x " << anchor_x << " anchor y " << anchor_y;
	}
	void move(double dx, double dy) { anchor_x += dx; anchor_y += dy; }
	virtual double getArea() = 0;

private:
	double anchor_x, anchor_y;
};

class Rectangle : public Shape
{
public:
	Rectangle(double ax, double ay, double l, double w) : Shape(ax, ay), length(l), width(w) {}
	void print(void) {
		Shape::print(); cout << " length: " << length << " width: " << width; // /!\ Shadow effect, use '::' to call Shape::print(), otherwise, it will call Rectangle::print()
	}
	double getArea(void) { return length * width; }

private:
	double length, width;
};

class Square : public Shape
{
public:
	Square(double ax, double ay, double l) : Shape(ax, ay), length(l) {}
	void print(void) {
		Shape::print(); cout << " length: " << length; // /!\ Shadow effect, use '::' to call Shape::print(), otherwise, it will call Rectangle::print()
	}
	double getArea(void) { return length * length; }
private:
	double length;
};

//==========================================================================================



//==========================================================================================

int main2() {
	Rectangle r(5.0,6.0, 18, 78);
	r.print(); cout << endl;
	r.move(10, 10);
	r.print(); cout << endl;

	Square s(5.0, 6.0, 15);
	s.print(); cout << endl;
	s.move(10, 10);
	s.print(); cout << endl;

	//vector<Shape> sv = { r,s}; //print() is the one from Shape, it doesn't work
	//for (Shape s : sv) { s.print(); }

	//vector<Shape*> sv = { &r,&s }; //Same, doesn't work
	//for (Shape* s : sv) { s->print(); } 

	//If we add virtual in front of print in Box IT WORKS
	vector<Shape*> sv = { &r,&s }; //Same, doesn't work
	for (Shape* s : sv) {
		s->print();
		cout << "area : " << s->getArea();
	}

	return 0;
}

