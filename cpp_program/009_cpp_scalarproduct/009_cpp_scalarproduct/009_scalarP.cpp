#include <iostream>
#include <vector>
// to gain access to the function to create random numbers, rand() and srand()
#include <cstdlib>
#include <ctime>

#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

using namespace std;

double my_max(vector<double> vec_a, int* index);

int main()
{
	time_t walltime = time(nullptr);
	cout << "Hello world! It is " << asctime(localtime(&walltime)) << "\n";

	// Initialize the random number sequence
	srand(walltime);
	// single random number
	int a = rand();
	cout << a << "\n";
	// random number between (0,1) ?
	double b = rand() / RAND_MAX;
	cout << b << "\n";
	// random number between (0,1) !
	double c = double(rand()) / RAND_MAX;
	cout << c << "\n\n";
	/* Changing the variable type from int to double with the cpp double() function allows for "real" division. */

	// TASK: Create a vector of doubles of arbitrary (user-given) size and fill it with random numbers from the interval (0,1)!
	vector<double> vec_a(100); //TODO

	int index = 0;
	cout << "The maximum value is " << my_max(vec_a, &index);
	cout << " at index " << index << "\n";

	// TASK: Create two vectors of size 100, fill them with random numbers of (0,1) and compute their scalar product in a function!

	return 0;
}

// My function to get the maximum value of an array of doubles, note how i "return" the index of the maximum value as well: via a pointer!
double my_max(vector<double> vec_a, int* index) {
	double the_max = *(vec_a.begin()); *index = 0;
	if (vec_a.size() > 1) {
		for (int i = 1; i < vec_a.size(); i++) {
			if (the_max < vec_a[i]) {
				the_max = vec_a[i];
				*index = i;
			}
		}
	}
	return the_max;
}
