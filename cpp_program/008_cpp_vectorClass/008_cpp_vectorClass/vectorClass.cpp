#include <iostream>
#include <vector>

using namespace std;


// https://www.codeguru.com/cpp/cpp/cpp_mfc/stl/article.php/c4027/C-Tutorial-A-Beginners-Guide-to-stdvector-Part-1.htm
int main()
{
	// static array
	  // static array declaration
	int sarray[10]; // creates 10 variables of type int(eger)
	// static array definition
	for (int i = 0; i < 10; i++) {
		sarray[i] = i;
	}
	// showing the values
	for (int i = 0; i < 10; i++) {
		cout << sarray[i] << " ";
	}; cout << "\n";

	// dynamic array
	int my_size;
	cout << "Pick a not too big size number: "; cin >> my_size;
	// dynamic array declaration
	int* darray = new int[my_size]; // dynamic meaning, that the size need not to be known in advance of compilation
	// static array definition
	for (int i = 0; i < my_size; i++) {
		darray[i] = my_size - i;
	}
	// showing the values
	for (int i = 0; i < my_size; i++) {
		cout << darray[i] << " ";
	}; cout << "\n";

	// vector
	  // vector construction: vec_a() calls a function from the vector class, that creates and instance/object of said class
	vector<double> vec_a(my_size);
	// (1) vector values
	for (int i = 0; i < my_size; i++) {
		vec_a[i] = i * i;
	}
	// (1) showing values
	for (int i = 0; i < my_size; i++) {
		cout << vec_a[i] << " ";
	}; cout << "\n";
	// A different way of producing the same result, by using the vector classes properties and methods
	// (2) vector values
	int i = 0;
	for (vector<double>::iterator it = vec_a.begin(); it != vec_a.end(); it++) {
		*it = i * i * i; i++;
	}
	/* Here we iterate through the vectors elements by getting the pointer(the address variable) of the first element
	and increasing it by the size of the variable double (which might be different between systems)
	until it is the same address as the pointer to the last element in the vector, which we get from vec_a.end()*/
	// (2) showing values
	for (vector<double>::iterator it = vec_a.begin(); it != vec_a.end(); it++) {
		cout << *it << "  "; // *itTASK: replace *it with &it and compare the output
	}; cout << "\n";

	// UNDERSTANDING POINTERS IS CRUCIAL IN PROGRAMMING
	/* About pointers: A variable has a value and an address where it is stored in the RAM of the computer. This address can be stored seperately in a pointer variable to create a somewhat remote access, e.g. */
	int a = 5;
	// -> value is 5
	cout << "\nValue of a: " << a << "\n";
	// -> address is somewhat hexadecimal like 0x7ffca28d68a8, this will always be different depending on runtime and system, but the format should be similar
	cout << "Address of a: " << &a << "\n";
	// We can store addresses in pointer variables, this is what the symbol * characterizes:
	int* p_a = &a;
	cout << "Value of p_a: " << p_a << " (is the address of a) \n";
	// We can even access the value of the stored address
	cout << "Stored value through p_a: " << *p_a << " (via *p_a)\n";
	// And of course the pointer variable, that stores the address of another variable has an address as well
	cout << "Address of p_a: " << &p_a << "\n";
	/* Why do we do pointers? Because we can not give whole objects from classes as an input or output argument to or from a function.
	So we create a fixed object and give the address/the reference of it to a function, so that it can manipulate its contents. */
	// TASK: Change the value of a via the pointer variable p_a, print the output!
    *p_a=10;
        cout <<"Value of <a> change by pointer: " << a << "\n";
	// delete space assigned to pointer *darray
	delete[] darray;
	// this need not be done for the vector object, because of its destructor, c.f. https://www.geeksforgeeks.org/destructors-c/

	return 0;
}
