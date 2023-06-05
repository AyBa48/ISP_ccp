// including cpp library files to use internal functions like printing, or datatypes like string
#include <iostream>
#include <string>

// some magical object that allows you to write cout instead of std::cout
using namespace std;

/* (4) Function for the Hello-World message
	note that we return a value, that we need to catch in the main function
	note that the head of the function: int myHello()
	and the body of the function: the rest, are not seperated! */
int myHello() {
	cout << "Hello world from function!\n";
	return 0;
}

/* (5) Function for the Hello message with an input argument
	note that here only the head of the function is declared!
	the body follows below */
void myPersonalHello(string fname);

int main()
{
	// (1) Standard Hello world
	cout << "Hello world!" << endl;
	// (2) Saying Hello world from a function and checking the functions return value
	int val = myHello();
	if (val == 0) {
		cout << "Function executed successfully...\n";
	}
	// (3) Personalize the Hello world message
	myPersonalHello("John");
	string uName; cout << "Who are you? ";
	cin >> uName;
	myPersonalHello(uName);

	return 0;
}

// Here is the body for the previously declared head of the function
void myPersonalHello(string fname) {
	cout << "Hello " + fname + "!\n";
	// no return because "void function type" does not require any
}