// pointers and reference
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>


int my_sum_normal(int a, int b);
int my_sum_reference(int *a, int *b);
double my_arraysum_reference(double *a, int size);
double my_vectorsum_normal(std::vector<double> v);
double my_vectorsum_reference(std::vector<double> &v);

double my_scalarp(const std::vector<double> &v, const std::vector<double> &w);

int main()
{
    // see https://www.geeksforgeeks.org/pointers-vs-references-cpp/
    // and https://www.geeksforgeeks.org/when-do-we-pass-arguments-by-reference-or-pointer/
    /* variable, basic data type, has a value and an address (where the value is stored) */
    int a = 5,b,c; // value 5, address ???
//    std::cout << "variable a, value: " + std::to_string(a) + "\n";
    /* pointers: A pointer is a variable that holds memory address of another variable as a value. */
    std::cout << "variable a, address: " << &a << "\n\n";
    int *p = &a;
    std::cout << "pointer p, value (is a's address): " << p << "\n";
    // we can access and modify the value of a via the pointer p
    *p = 6;
    std::cout << "variable a, new value: " << a << "\n\n";
    // we can even combine the syntax
    std::cout << "value of a: a = " << a << "\n";
    std::cout << "value at the address of a: *(&a) = " << *(&a) << "\n\n";

    /* so, why do we do this?
    when we pass a variable as an argument to a function, we leave the current variable's scope (where is exists) and enter a new scope (where it does not exist).
    Here, by passing the variable as an argument, we copy its value from the variable of the old scope to a new variable in the new (function-)scope, where we can access the value of the variable, but not the old variable, who remains untouched. */
    a = 1; b = 2;
    c = my_sum_normal(a,b);
    std::cout << a << " + " << b << " = " << c << "\n";
    /* if we pass not the value of the variable as an argument, but the address, we can still access the variable's value through the passed address/pointer */
    c = my_sum_reference(&a,&b);
    std::cout << a << " + " << b << " = " << c << "\n\n";

    /* without pointers, no software would work the way we have it today */

    /* an array, e.g. is a chunk of reserved memory and the identifier is just the address to the first element */
    double d[2] = {0.1,0.2};
    std::cout << "values of d: " << d[0] << " " << d[1] << "\n";
    std::cout << "what is this? " << d << " " <<d+1 <<"\n"; //well its the address of the first element of the array
    std::cout << "first value, *d: "<< *d << "\n";
    std::cout << "next value, *(d+1): " << *(d+1) << "\n";
    /* so that is why, when we have an array as a function argument we are actually providing a pointer to the first element and it does not matter, if we access the elements via d[i] or *(d+i) */
    double e = my_arraysum_reference(d,2);

	/* for structures like classes, finding the pointer to the first - well what? element? - is not straightforward, but c++ found a workaround, which too is called "passing by reference".
	This ensures, that we can access the passed object normally in the function */
	std::vector<double> f(3);
	f[0] = 0.1; f[1] = 0.2; f[2] = 0.3;
	std::cout << "\nvalues of f: " << f[0] << " " << f[1] << " " << f[2] << "\n";
	/* in the first function we pass the vector intuitively, then it gets copied into a lokal vector variable, after the summation we change the vectors elements, but just locally */
	double g = my_vectorsum_normal(f);
	std::cout << "sum of f (normal): " << g << "\n";
	std::cout << "values of f back in the main function: " << f[0] << " " << f[1] << " " << f[2] << "\n#############\n";
	/* now we pass by reference and the changed values will be accessible in the main function, since we altered the actual object and not its copy */
	double h = my_vectorsum_reference(f);
	std::cout << "sum of f (reference): " << h << "\n";
	std::cout << "values of f back in the main function: " << f[0] << " " << f[1] << " " << f[2] << "\n";

	std::cout << "\nNow up to this point, we talked about pointers and passing by reference. Two things that you must absolutely understand, so make sure there are no questions unanswered.\n\nIf we always pass objects by referece we might loose overview in our function and accidently change an object, that we do not want to change, e.g. in the scalar product we do not need to change the vectors values.\n\nTo prevent this we will use the const keyword. A constant variable can not be changed without the compiler complaining, so we will pass our objects by constant reference, so they do not get changed.\n\n";

	time_t walltime = time(nullptr);
	srand(walltime);
	int the_size = 100;
    std::vector<double> vec_b(the_size);
    std::vector<double> vec_c(the_size);
    for(int i = 0; i < the_size; i++){
        vec_b[i] = double(rand())/RAND_MAX;
        vec_c[i] = double(rand())/RAND_MAX;
    }
    std::cout << "The scalar product of the two vectors is " << my_scalarp(vec_b,vec_c) << "\n";

    return 0;
}

int my_sum_normal(int a, int b){
    int c = a+b;
    a = 123;
    std::cout << "Note how we change a in the my_sum_normal function to " << a << ", but the a in the main function does not change!\n";
    return c;
}

int my_sum_reference(int *a, int *b){
    int c = *a+*b;
    *a = 123;
    std::cout << "Note how we use the *a syntax to access the value at the given address!\n";
    return c;
}

double my_arraysum_reference(double *a, int size){
	double sum1 = 0.0;
	double sum2 = 0.0;
	for(int i = 0; i < size; i++){
		sum1 += *(a+i);
		sum2 += a[i];
	}
	if(sum1 == sum2){
		std::cout << "sums are equal at (" << sum1 << "," << sum2 << ")\n";
		return sum1;
	}else{
		std::cout << "sums are not equal\n";
		return 0;
	}
}

double my_vectorsum_normal(std::vector<double> v){
	double sum = 0.0;
	for(unsigned int i = 0; i < v.size(); i++){
		sum += v[i];
		v[i] = 2*v[i];
	}
	std::cout << "changed values of f (in normal function): " << v[0] << " " << v[1] << " " << v[2] << "\n";

	return sum;
}

double my_vectorsum_reference(std::vector<double> &v){
	double sum = 0.0;
	for(unsigned int i = 0; i < v.size(); i++){
		sum += v[i];
		v[i] = 2*v[i];
	}
	std::cout << "changed values of f (in reference function): " << v[0] << " " << v[1] << " " << v[2] << "\n";

	return sum;
}

double my_scalarp(const std::vector<double> &v, const std::vector<double> &w){
	double scalarp = 0.0;
	int the_size = v.size() < w.size() ? v.size() : w.size();
	for(int i = 0; i < the_size; i++){
		scalarp += v[i]*w[i];
	}
	// uncomment this to see, what the compiler says, when you try to change a const variable
	// v[0] += 1;

	return scalarp;
}
