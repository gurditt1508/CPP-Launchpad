#include<iostream>
#include<cstring>

using namespace std;

class Customer{

public: 

	char* name;
	int age;
	char gender;
	double credits;

	Customer(char* n, int a, char g, double c){
		cout << "i am inside parameterised constructor. " << endl;
		name = new char[100];
		strcpy(name, n);
		age = a;
		gender = g;
		credits = c;
	}

	Customer(){
		cout << "inside default constructor" << endl;
	}

	void printCustomerInfo(){

		cout << "Customer Information " << endl
		<< "Name: " << name << endl
		<< "Age: " << age << endl
		<< "Gender: " << gender << endl
		<< "Credits: " << credits << endl
		<< endl;
	}

	// Customer(Customer& c){ //this is taking argument because we need c1's information
	// 	cout << "inside copy constructor. " << endl;
	// 	strcpy(name, c.name);
	// 	age = c.age;
	// 	gender = c.gender;
	// 	credits = c.credits;
	// }



};

int main(){

	Customer c1("Pranav", 20, 'M', 100); //parameterised constructor
	c1.printCustomerInfo();

	Customer c2 = c1; //default copy constructor - shallow copy
	c2.printCustomerInfo();

	strcpy(c2.name, "Sourav");
	cout << "c2.name: " << c2.name << endl;
	cout << "c1.name: " << c1.name << endl;

	return 0;
}