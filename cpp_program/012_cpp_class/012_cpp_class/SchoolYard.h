#include <iostream>
#include <string>

/* this is a basic class definition */
class SchoolYard{
    /* a class has properties and methods
    properties (and methods as well) are either
        private,
        public or
        protected.
    Details obtain from the lecture or https://www.tutorialspoint.com/cplusplus/cpp_class_access_modifiers.htm */

    /* properties are data contained by the class */
    private:
        unsigned int pupils; // this is private
        unsigned int teachers;
        std::string weather;
        /* a private function/method */
        void status(){
            std::cout << "The SchoolYard has opened. Its " << weather << " and there are " << pupils << " pupils and " << teachers << " teachers on the Yard.\n";
        }

    /* methods are functions that provide information or modify the classes data */
    public:
        //unsigned int teachers; // this is public
        /* a special method is the constructor, that initializes the object created from the class with standard or user-given values, see https://www.tutorialspoint.com/cplusplus/cpp_constructor_destructor.htm */
        SchoolYard(){
            pupils = 0;
            teachers = 1;
            weather = "sunny";
            /* the this keyword refers to the object, whos member should be called, in this case, we create an object from this class via the constructor, initialize the properties and then call the member function status (which you can find above) */
            this->status();
        }
        /* another constructor with given input */
        SchoolYard(unsigned int m_pupils, std::string m_weather):pupils(m_pupils),weather(m_weather){
            this->status();
        }
        void addPupil(){
            pupils++;
            this->status();
        }
        void removePupil(){
            pupils--;
            this->status();
        }
        void addTeacher(){
            teachers++;
            //this->status();
        }
        void removeTeacher(){
            teachers--;
            //this->status();
        }
        void myStatus(){
            this->status();
        }
        void newWeather(std::string m_weather){
            weather = m_weather;
        }
         SchoolYard(std::string m_weather):weather(m_weather){
            this->status();
        }
        /* Task can be found in the main.cpp */
};
