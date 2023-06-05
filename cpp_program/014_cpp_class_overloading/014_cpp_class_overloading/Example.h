
class Example{
    private:
        int value;
    public:
        /* two different constructors, overloading occurs: same name but different parameters */
        Example():value(0){
            std::cout << "Empty constructor called\n";
        }
        Example(int m_value):value(m_value){
            std::cout << "Constructor with integer called\n";
        }
        Example(double m_value){
            value = int(m_value);
            std::cout << "Constructor with double called\n";
        }
};
