#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

/* polymorphism is, regarding the idea behind it, quite similar to overriding */

#include "InnerProduct.h"

int main()
{
    time_t walltime = time(nullptr);
    srand(walltime);

    std::cout << "The difference between overriding and polymorphism is, that you do not know at runtime, which class your object is from. Then you can not easily distinguish between the different classes and therefor can not call the member function form the class, that you want.\n\n";
    /* see https://stackoverflow.com/questions/7489335/overriding-vs-polymorphism */

    std::cout << "Consider for example the inner product from the Hilbert space. Depending on the space that we choose, the computation varies:\n";
    std::cout << "\tFor scalar numbers: (a,a) = a * a\n\tFor vectors: (a,a) = a_i * a_i\n\tand for matrices (A,A) = A_ii * A_ii.\n\n";

    std::cout << "Now imagine you get a sequence of scalars, vectors and matrices, not knowing which one the next item is, but you still have to compute every inner product.\n\n";
    /* see https://www.tutorialspoint.com/cplusplus/cpp_polymorphism.htm */

    /* creating some objects */
    my_scalar a1,a2;
    my_vector b1,b2;
    my_matrix c1,c2;

    /* computing their inner products */
    std::cout << "Inner product of a1: " << a1.innerProduct() << "\n"; // a1.scalar_innerProduct() : modify after class function has been modified
    std::cout << "Inner product of a2: " << a2.innerProduct() << "\n";
    std::cout << "Inner product of b1: " << b1.innerProduct() << "\n"; //b1.vector_innerProduct() : modify after class function has been modified
    std::cout << "Inner product of b2: " << b2.innerProduct() << "\n";
    std::cout << "Inner product of c1: " << c1.innerProduct() << "\n";//c1.matrix_innerProduct(): modify after class function has been modified
    std::cout << "Inner product of c2: " << c2.innerProduct() << "\n";

    /* TASK: The goal is to put the above 6 lines in a single loop. For this we use polymorphism, since they are objects from different classes.
    If you have not read https://www.tutorialspoint.com/cplusplus/cpp_polymorphism.htm now is the time.
    (1) You need to add a member function innerProduct() to the classes my_scalar, my_vector, my_matrix and my_item, where for the my_item class the innerProduct() is a virtual function.
    (2) You need to implement, that my_item is a parent class to all the others.
    (*) In this example my_item is merely an artificial parent, that allows us later to treat the other functions similarly by reference.
    (3) You need to assign the reference of the created objects to the my_list below.
    (4) You need to compute the inner product for the referenced objects in a loop and display them to the user as well as the dim property from the my_item class. */

    /* To gather all object from the different classes, we need the my_item class, as a common base class. We then save the reference of the derived classes in pointers of the my_item type: */
    std::vector<my_item*> my_list(6); //my_list is a pointer of type my_item
    my_list[0]=&a1;
    my_list[1]=&a2;
    my_list[2]=&b1;
    my_list[3]=&b2;
    my_list[4]=&c1;
    my_list[5]=&c2;

    for (unsigned int i=0; i<my_list.size(); i++){
        std::cout <<"Inner product is  : " <<my_list[i]->innerProduct()<<" and dim properties : " <<my_list[i]->get_type()<< "\n";
    }



    return 0;
}
