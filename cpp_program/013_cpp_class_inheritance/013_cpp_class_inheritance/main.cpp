#include <iostream>

/* talking about inheritance in O(bject)O(riented)P(rogramming) */

/* quick reminder why we want inheritance: we are lazy, certain classes have a lot in common and we do not want to program everything over and over again */

/* see https://www.geeksforgeeks.org/inheritance-in-c/ */

/* Example: this is the basis class*/
class Vehicle{
    private:
        unsigned int wheels;
        unsigned int passengers;

    public:
        Vehicle(){
            wheels = 1;
            passengers = 1;
        }
        Vehicle(unsigned int m_wheels, unsigned int m_passengers):wheels(m_wheels),passengers(m_passengers){};
        void moves(){
            std::cout << "The vehicle moves on " << wheels << " wheels and with " << passengers << " passengers.\n";
        }
};

/* this is the derived class */
class Bicicle : public Vehicle{
    private:
        bool helmet;

    public:
        Bicicle():Vehicle(2,1){
            helmet = false;
        }
        Bicicle(bool m_helmet):Vehicle(2,1),helmet(m_helmet){}
        void rides(){
            std::cout << "The driver rides with ";
            if(helmet){std::cout << "a ";}
            else{std::cout << "no ";}
            std::cout << "helmet!\n";
        }
};

int main()
{
    std::cout << "Hello world!\nLets start with the simple know usage of a single class:\n\n";

    Vehicle vh;
    vh.moves();

    std::cout << "\nNow we do the same for the inherited class (the sub class, that is actually bigger and more speficic, but still has the \"old\" properties and methods):\n\n";
    Bicicle bc1;
    bc1.moves();
    bc1.rides();
    Bicicle bc2(true);
    bc2.moves();
    bc2.rides();

    /* TASK: from Vehicle derive a class Boat and from class Boat derive another class Speedboat. Consider suitable members (properties and methods). */

    return 0;
}
