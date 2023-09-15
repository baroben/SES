#include<iostream>
#include<string>
#include<vector>
#include <sstream>
using namespace std;


// common interface for Coyota dealer affiliated classes
class Coyota_dealer_affiliated
{
public:
	virtual string write_letter_to(string text) = 0;// pure virtual
};


class Person : public Coyota_dealer_affiliated
{
public:
	Person(string n, string adr) : name(n), address(adr) {}
	void print(void) const { cout << "name: " << name << " adress: " << address; }
	virtual string write_letter_to(string text) {
		ostringstream oss;
		oss << name << ", residing " << address << "," << endl;
		oss << text;
		return oss.str();
	}
private:
	string name, address;
};

class Customer : public Person
{
public:
	Customer(string n, string a, int c, double ac) : Person(n, a), customer_number(c), account(ac) {}
	void print(void) const {
		Person::print(); cout << " customer_number: " << customer_number
			<< " account: " << account;
	}
	string write_letter_to(string text) {
		ostringstream oss;
		oss << "Dear customer " << Person::write_letter_to(text);
		return oss.str();
	}
private:
	int customer_number;
	double account;
};


class Employee : public Person
{
public:
	Employee(string n, string a, int en) : Person(n,a), employee_number(en) {}
	virtual void print(void) const {
		Person::print(); 
		cout << "employee number" << employee_number; 
	}
	virtual double calculate_salary() = 0; 
private:
	int employee_number;
};


class Mechanic : public Employee
{
public:
	Mechanic(string n, string a, int en) : Employee(n,a,en), hours(0), hourly_salary(10){}
	void set_hourly_salary(double s) { hourly_salary = s; }
	void set_hours(int h) { hours = h; }
	void print(void) const {
		Employee::print();
		cout << " hours: " << hours << " hourly salary: " << hourly_salary;
	}
	double calculate_salary() { return hourly_salary * hours; }
	string write_letter_to(string text) {
		ostringstream oss;
		oss << "Dear mechanic " << Person::write_letter_to(text);
		return oss.str();
	}
private:
	int hours;
	double hourly_salary;
};

class Secretary : public Employee
{
public:
	Secretary(string n, string a, int en) : Employee(n,a,en), monthly_salary(1350) {}
	void set_monthly_salary(double s) { monthly_salary = s; }
	void print(void) const {
		Employee::print();
		cout << " monthly salary: " << monthly_salary;
	}
	double calculate_salary() { return monthly_salary; }
	string write_letter_to(string text) {
		ostringstream oss;
		oss << "Dear secretray " << Person::write_letter_to(text);
		return oss.str();
	}
private:
	double monthly_salary;
};

class Salesman : public Employee
{
public:
	Salesman(string n, string a, int en) : Employee(n, a, en), sale(0), provision(0){}
	void set_provision(double p) { provision = p; }
	void set_sale(double s) { sale = s; }
	void print(void) const { 
		Employee::print();
		cout << " sale: " << sale << " provision: " << provision;
	}
	double calculate_salary() { return provision + sale; }
	string write_letter_to(string text) {
		ostringstream oss;
		oss << "Dear salesman " << Person::write_letter_to(text);
		return oss.str();
	}

private:
	double sale, provision;
};

class Director : public Employee
{
public:
	Director(string n, string a, string fc, int en) : Employee(n, a, en), free_car(fc), monthly_salary(15000){}
	void set_monthly_salary(double s) { monthly_salary = s; }
	void set_free_car(string c) { free_car = c; }
	void print(void) const { Employee::print(); cout << "monthly salary: " << monthly_salary << " free car " << free_car; }
	double calculate_salary() { return monthly_salary; }
	string write_letter_to(string text) {
		ostringstream oss;
		oss << "Dear director " << Person::write_letter_to(text);
		return oss.str();
	}
private:
	double monthly_salary;
	string free_car;
};

vector<Employee*> employees;
vector<Customer*> customers;

int main(void)
{
	Customer p1 = Customer("benoit", "2 rue du chat", 0, 1000);
	Customer p2 = Customer("Colin", "3 rue du chat",1, 200);
	Customer p3 = Customer("Dam", "4 rue du chat",2, 4000);
	vector<Customer*> vp = { &p1,&p2,&p3 };
	for (auto c : vp) {
		c->print(); cout << endl;
		cout << c->write_letter_to("Je vous informe de nos offres promotionnelles de ce 16 aout.\nCordialement, merci.") << endl;
		cout << endl;
	}
	
	Mechanic m = Mechanic("denis", "3 rue de Paris", 0);
	Secretary s = Secretary("booris", "18 rue de Paris", 0);
	Salesman sa = Salesman("joh", "3 rue de Toulouse", 0);
	Director d = Director("rene", "9 rue de Paris","maclaren 520 spider", 0);

	employees.push_back(&m);
	employees.push_back(&s);
	employees.push_back(&sa);
	employees.push_back(&d);

	for (auto e : employees) { //We get all the informations if the print is virtual in the Employee class
		e->print(); 
		cout << " monthly salary: " << e->calculate_salary() << " " << endl;
		cout << e->write_letter_to("Je vous informe du changement de menu a la cantine ce midi.\nCordialement, merci.") << endl;
		cout << endl;
	}

	//int kk; cin >> kk;// if you want to make sure that the output screen stays
	return 0;
}