/* in visual studio you need to add this file to the existing project */
#include <iostream>
#include <vector>
#include "func.h"

using namespace std;

void my_hello(){
	cout << "Hello world from func.cpp file!\n";
}

double my_scalarp(const std::vector<double> &v, const std::vector<double> &w){
	double scalarp = 0.0;
	int the_size = v.size() < w.size() ? v.size() : w.size();
	for(int i = 0; i < the_size; i++){
		scalarp += v[i]*w[i];
	}
	return scalarp;
}


