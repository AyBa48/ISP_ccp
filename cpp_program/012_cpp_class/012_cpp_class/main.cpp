#include <iostream>

/* a class is a building scheme for an arbitrary, abstract construct, so it can be anthing really */

// https://hackr.io/blog/pass-by-reference-vs-pass-by-pointer

#include "SchoolYard.h"
#include "func.h"

int main()
{
    std::cout << "Hello world! This is the implementation of the SchoolYard class! Befor you continue, read the SchoolYard.h class file.\n\n";

    /* Here we create an object from the class */
    SchoolYard School1;
    std::cout << "\n(Note, how with the declaration of the object, the constructor was called and so was the status function via the constructor.)\n\n";
    /* another Object */
    SchoolYard School2(10,"cloudy");
    /* we can access puclic members of the class, either via "." or via "->", see https://www.tutorialspoint.com/cplusplus/cpp_member_operators.htm */
    //std::cout << "This is the number of teachers: " <<  School2.teachers << "\n";
    //School2.teachers++;
    //std::cout << "This is the number of teachers now: " <<  School2.teachers << "\n\n";


    School2.addPupil();
    for(int i = 0; i < 17; i++){
        School2.addPupil();
    }
    /* to emphasize this, because it is important to understand the difference:
    the dot-operator "." is used, when we have access to the actual object, e.g. if we pass the object by reference to a function, whereas
    the arrow-operator "->" is used, when we only have access of the object through a pointer */
    removePupilsofYard(School2,10);
    SchoolYard *p_SY; // this is a pointer to the class
    p_SY = &School2;
    addPupilstoYard(p_SY,5);
    addPupilstoYard(&School2,5); // without an extra pointer
    /* note the different use of the dot- and arrow-operator in the functions */

    /* note, that - due to declaring status() in SchoolYard as private - the following is forbidden */
    // School2.status();

    /* TASK: change the teachers-variable access to private, add methods to the class to modify the teacher number and use them in main */
    School2.addTeacher();

    /* TASK: add a public method to the class, that calls the private status function and use it in main */
    School2.myStatus();

    /* TASK: add class functionality to modify the weather variable */
   // School2.newWeather("Snowy"); /*why when I change the value of weather via a method, the teachers variable behave differently*/
    //School2.myStatus();
    //SchoolYard("Snowy");

    return 0;
}
