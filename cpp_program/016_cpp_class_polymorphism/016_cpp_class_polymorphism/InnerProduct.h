#include <vector>
#include <cstdlib>

class my_item{
    private:
        int dim;
    public:
        my_item() : dim(-1) {}
        my_item(unsigned int m_dim) : dim(m_dim) {}
        int get_type(){
            return dim;
        }
       virtual double innerProduct(){
            return 0;
        }
};

class my_scalar: public my_item{
    private:
        double value;
    public:
        my_scalar():my_item(0) {
            value = double(rand())/RAND_MAX;
            //my_item(0);
        }
        double innerProduct(){ // not to be confused with scalar product
            return value*value;
        }
};

class my_vector: public my_item {
    private:
        std::vector<double> value;
    public:
        my_vector():my_item(1) {
            value.resize(10);
            for(unsigned int i = 0; i < value.size(); i++){
                value[i] = double(rand())/RAND_MAX;

            }
        }
        double innerProduct(){
            double val = 0.0;
            unsigned int m = value.size();
            for(unsigned int i = 0; i < m; i++){
                val += value[i]*value[i];
            }
            return val;
        }
};

class my_matrix: public my_item {
    private:
        std::vector< std::vector<double> > value;
    public:
        my_matrix():my_item(2) {
            value.resize(10);
            for(unsigned int i = 0; i < value.size(); i++){
                value[i].resize(10);
                for(unsigned int j = 0; j < value[i].size(); j++){
                    value[i][j] = double(rand())/RAND_MAX;
                }
            }
        }
        double innerProduct(){
            double val = 0.0;
            unsigned int m = value.size();
            unsigned int n = value[0].size();
            for(unsigned int i = 0; i < m; i++){
                for(unsigned int j = 0; j < n; j++){
                    val += value[i][j]*value[i][j];
                }
            }
            return val;
        }
};
