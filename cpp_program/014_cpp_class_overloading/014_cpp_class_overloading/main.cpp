#include <iostream>

/* Overloading is something, that we have done multiple times up to this point:
    we have multiple functions or operator, that have the same name, but differ with regard to input/output arguments
a little class unrelated example: */

int my_add(int a, int b);
double my_add(double a, double b);

#include "Example.h"
#include "fraction.h"

int main()
{
    std::cout << "Hello world!\n";

    int int_sum = my_add(5,2);
    double double_sum = my_add(1.2,3.4);

    std::cout << "int_sum: " << int_sum << "\ndouble_sum: " << double_sum << "\n";
    /* here we have used the same function name identifier */

    /* We did the same way with the constructors of classes from previous examples */
    /* see Example.h */
    Example ex1,ex2(int_sum),ex3(double_sum);

    /* for a more sophisticated example, from which a task will emerge, we attend the fraction class:
                    2    numerator (x)
    fraction =    -----
                    3    denominator (y),
    see Fraction.h */

    Fraction f1;
    //std::cout << "\n\nThe fraction is: " << f1.get() << "\n";
    Fraction f2(4);
    std::cout << "The fraction is: " << f2.get() << "\n";
    Fraction f3(12,8);
    std::cout << "The fraction is: " << f3.get() << "\n";
    Fraction f4;
    f4 = f2+f3;
    std::cout << "The fraction is: " << f4.get() << "\n";

    /* Note how the +operator is overloaded and now works for die Fraction class as well. Note furthermore how the bodies of the member function of the fraction class are outsourced to fraction cpp. Remember that syntax. */

    /* TASK: Add functionality to the fraction class:
        (1) Implement the body of the member function reduce() that reduces the fraction, 12/8 -> 4/3. see https://en.wikipedia.org/wiki/Greatest_common_divisor
        (2) Overload the operators -,*,/,==, !=, <, > */

    return 0;
}

int my_add(int a, int b){
    int c = a+b;
    std::cout << "addition of integers called\n";
    return c;
}

double my_add(double a, double b){
    double c = a+b;
    std::cout << "addition of doubles called\n";
    return c;
}
