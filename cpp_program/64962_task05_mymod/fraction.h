/* class_algebra, class fraction, class vector, class matrix,
  an regarding functions, constructor, add..., show, ....
Matthias Braendel, 2019 */
#pragma once
#include<iostream>

using namespace std;

class Fraction{
  private: // properties
    int x; //numerator
    int y; //denominator
    void reduce();


  public: // methods
    // STRUCTORS
    // CON-
	Fraction(){
		std::cout << "Empty Constructor start\n";
		x=0; y=1;
		std::cout << "Empty Constructor end\n";
	}
    Fraction(int a , int b ){
		std::cout << "Full Constructor start\n";
		x=a; y=b;
		std::cout<<"\nReduce function of full constructor: \n";
		reduce();
		std::cout << "Full Constructor end\n";
	} // constructor(parameters)
	Fraction(int a ){
		std::cout << "Integer Constructor start\n";
		x=a; y=1;
		std::cout << "Integer Constructor end\n";
	}
    // DE-
    ~Fraction(){}
    // COPY - Constructor
    Fraction(const Fraction &image){
      x = image.x;
      y = image.y;
      this->reduce();
    }

    // OUTPUT
    //string get();
    void show();

    // +
    Fraction operator+(const Fraction &f1); // for c = a+b
    // unary-
    Fraction operator-(); // for c = -a

    // -Operator
    Fraction operator- (const Fraction &f2);

    //* Operator
    Fraction operator* (const Fraction &f3);

    // / Operator
    Fraction operator/ (const Fraction &f4);

    //Operator ==
    Fraction operator== (const Fraction &f5);

    //Operator !=
    Fraction operator!= (const Fraction &f6);

    //Operator <
    Fraction operator< (const Fraction &f7);

    //Operator >
    Fraction operator> (const Fraction &f8);
};
