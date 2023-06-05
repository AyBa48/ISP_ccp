#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

/* introducing function files and matrices */

/* for visibility (and compilation overhead) we want to outsource code into files, function code e.g. */
/* this code needs to be brought to the compilers attention like this: */
#include "func.h"

int main()
{
    std::cout << "When we want to outsorce code into a - say - func.cpp file, we also need a so called header file, that contains the heads of the functions.\n\n";
	/* the following function call refers to a function that can be found in the func.* header and source files */
	my_hello();

	/* again the scalar product as another example */
	time_t walltime = time(nullptr);
	srand(walltime);
	int the_size = 100;
    std::vector<double> vec_b(the_size);
    std::vector<double> vec_c(the_size);
    for(int i = 0; i < the_size; i++){
        vec_b[i] = double(rand())/RAND_MAX;
        vec_c[i] = double(rand())/RAND_MAX;
    }
    std::cout << "\nThe scalar product of the two vectors is " << my_scalarp(vec_b,vec_c) << "\n\n";
	std::cout << "Note, that the scalar product code is the same from the 010*archive\n\nFurthermore, note that in the function source files *cpp, we have to include all the packages we need again.\n\n";

	/* next section we attend to is matrices: A matrix can be displayed as a vector of vectors, which is our method of choice here */
	/* you certainly have observed, that the vector class is data type independet, meaning we can create a vector of ints
		vector<int> vec_int(100);
	as well as a vector of doubles
		vector<double> vec_double(100);
	so now we create a vector of vectors: */
	std::vector< std::vector<double> > mat_A(5);
	/* now we have a vector of 5 (empty, no entries, no size) vectors, which we now initialize */
	for(unsigned int i = 0; i < mat_A.size(); i++){
		mat_A[i].resize(5);
	}
	/* now we can access and fill the matrix like this: */
	for(unsigned int i = 0; i < mat_A.size(); i++){
		for(unsigned int j = 0; j < mat_A[i].size(); j++){
			mat_A[i][j] = double(rand())/RAND_MAX;
		}
	}
	/* and print it to the command line */
	for(unsigned int i = 0; i < mat_A.size(); i++){
		for(unsigned int j = 0; j < mat_A[i].size(); j++){
			std::cout << mat_A[i][j] << " ";
		}std::cout << "\n";
	}std::cout << "\n";

	/* TASK: Write a function (and outsource it to func.cpp obviously) that computes the matrix vector multiplication of a 100x100 matrix with a 100x1 vector filled with random numbers! Every vector/matrix object has to be passed by reference! Decide which object not to pass as constant! Print the resulting vector to the command line! (Do not forget the head of the function in the header file func.h) */

	int n = 100;
	std::vector< std::vector<double> > mat_B(n);
	std::vector<double> vec_a1(n), vec_a2(n);

	/* printing the resulting vector, note that the values of this vector should be approx 25 */
	for(unsigned int i = 0; i < vec_a2.size(); i++){
		std::cout << vec_a2[i] << "\n";
	}


    return 0;
}
