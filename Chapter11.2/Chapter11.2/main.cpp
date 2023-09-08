#include <iostream>
#include <iomanip>	
#include <vector> 
using namespace std;

class Date {
private:
	int day;
	int month;
	int year; 

public:
	int getDay() const { return day; } //getters are now const
	int getMonth() const { return month; }
	int getYear() const { return year; }

	Date& setDay(int d) { day = d; return *this; }	//setters return a reference to the object
	Date& setMonth(int m) { month = m; return *this; }
	Date& setYear(int y) { year = y; return *this; }

	Date(int d, int m, int y) : day{ d }, month{ m }, year{ y } {}

	void print() {
		cout << day << " " << month << " " << year << endl;
	}
};

class Person {
private:
	string name;
	Date birth_date;
	Person *mother_ptr;
	Person *father_ptr;
	vector<Person*> childs; //Must be a vector of pointer to track changes on the childs

public:
	Person(string n, Date bd) : name{ n }, birth_date{ bd }, mother_ptr{ 0 }, father_ptr{ 0 } {}
	void print() { 
		cout << name << " " << birth_date.getDay() << ":" << birth_date.getMonth() << ":" << birth_date.getYear() << endl;
	}
	void add_parents(Person& mother, Person& father) {
		mother_ptr = &mother; 
		father_ptr = &father; 
	}
	void print_parents() {
		if (father_ptr != 0)father_ptr->print();
		if (mother_ptr != 0)mother_ptr->print();
	}

	void add_child(Person& child) {
		childs.push_back(&child);
	}

	void print_children() {
		for (auto c : childs) {
			c->print();
		}
	}

	void print_grand_parents() {
		mother_ptr->print_parents();
		father_ptr->print_parents();
	}

	void print_grand_children() {
		for (auto c : childs) {
			c->print_children();
		}
	}
};

int main() {

	//------------------------------------------------------------------------

	Person p("Benoit", Date(17, 1, 2000));
	p.print();
	Person mother("armelle", Date(6, 7, 1959));
	Person father("pascal", Date(21, 3, 1958));
	Person grandmother_mat("solange", Date(2, 5, 1910));
	Person grandfather_mat("raymond", Date(1, 9, 1900));
	Person grandmother_pat("christiane", Date(2, 5, 1910));
	Person grandfather_pat("andre", Date(1, 9, 1900));
	Person child1("louis", Date(6, 7, 2021));
	Person child2("fanny", Date(21, 3, 2019));

	mother.add_parents(grandmother_mat, grandfather_mat); 
	father.add_parents(grandmother_pat, grandfather_pat);

	p.add_child(child1);
	p.add_child(child2);

	p.add_parents(mother, father);
	mother.add_child(p);
	father.add_child(p);

	
	
	cout << "Parents : " << endl;
	p.print_parents();
	cout << "Childrens : " << endl;
	p.print_children();
	cout << "Grand parents : " << endl;
	p.print_grand_parents();
	cout << "Grand children" << endl;
	mother.print_grand_children();

	//------------------------------------------------------------------------

	/*Date date(9, 8, 2023);
	date.setDay(10).setMonth(9).setYear(2024);
	date.print();

	vector<Date> dv;
	dv.push_back(date);
	dv.push_back(Date(2,3,2023);
	dv.push_back(Date(7,9,1999);

	for (auto d : dv) { d.print(); }*/

	//------------------------------------------------------------------------

	/*int a = 2;
	int* ptr = &a;
	int b = *ptr;
	int &aa = a; 
	int *x_ptr = new int;
	*x_ptr = 4;
	int& x = *x_ptr;
	int **ptrptr = &ptr;
	**ptrptr = 8; // a is changed to 8
	*ptrptr = x_ptr; //ptrptr now holds adress of x


	cout << setw(30) << "name" << setw(30) << "address" << setw(30) << "value" << endl;
	cout << setw(30) << "a" << setw(30) << &a << setw(30) << a << endl;
	cout << setw(30) << "ptr" << setw(30) << &ptr << setw(30) << ptr << endl;
	cout << setw(30) << "b" << setw(30) << &b << setw(30) << b << endl;
	cout << setw(30) << "&aa" << setw(30) << &aa << setw(30) << aa << endl;
	cout << setw(30) << "x_ptr" << setw(30) << &x_ptr << setw(30) << x_ptr << endl; //&x_ptr is close, x_ptr is far away
	cout << setw(30) << "&x" << setw(30) << &x << setw(30) << x << endl;
	cout << setw(30) << "ptrptr" << setw(30) << &ptrptr << setw(30) << ptrptr << endl;

	delete x_ptr; */

	return 0;
}