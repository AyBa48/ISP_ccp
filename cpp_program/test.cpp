
#include <iostream>
#include <cstdlib>
#include <vector>

double scalarproduct(std::vector<double> &n, std::vector<double> &p);
void matrix_product(std::vector< std::vector<double> > &m, std::vector<double> &v1, std::vector<double> &v2);
void f_printlinearsystem(const std::vector< std::vector<double> > &A,const std::vector<double> &b1, const std::vector<double> &b2, const std::vector<double> &K);

int main()
{
    std::cout<<"test the behavior of a matrice initialization \n";
    std::vector< std::vector<double> >k(4);
    std::cout<<"After the initialization of a matrix with a number of rows, that matrix should be resize (or initialize the number of column\n";
    for (unsigned int v=0; v<k.size(); v++){
        k[v].resize(4);
    }
    for (unsigned int i=0; i<k.size(); i++){
        for (unsigned int j=0; j<k[i].size(); j++){
            k[i][j]=0.0;
        }
    }
    std::cout<<"Try out to show the values of the matrice \n";
     for (unsigned int i=0; i<k.size(); i++){
        for (unsigned int j=0; j<k[i].size(); j++){
           std::cout<<k[i][j]<<" ";
        }

        std::cout<<"\n";
    }
    std::cout<<"\n";
    std::cout<<"Is that results corrects ?\n";

    std::cout<<"let´s try out that matrix from the programming project \n";
   /*Initialize matrice row and column*/
    std::vector<std::vector<double> >A(4); /*Row*/
    for (unsigned int k=0; k<A.size(); k++){ /*Column*/
        A[k].resize(4);
    }
    /*Filling the matrix */
    for(unsigned int i=0; i<A.size(); i++){
        for(unsigned int j=0; j<A[i].size(); j++){
                A[i][j]=0.0;
                if (i==0&&j==1){
                    A[i][j]=1;
                }
                if(i==1&&j==2){
                    A[i][j]=(((0.36*0.204)/(1.08+0.36))*((3*9.81)/(4*0.204)))/(1-(((0.36*0.204)/(1.08+0.36))*(3/(4*0.204))));
                }
                if(i==2&&j==3){
                    A[i][j]=1;
                }
                if(i==3&&j==2){
                    A[i][j]=((3*9.81)/(4*0.204))/(1-(((0.36*0.204)/(1.08+0.36))*(3/(4*0.204))));
                }
        }
    }
    /*Display the value on the screen-------*/
       for (unsigned int i=0; i<A.size(); i++){
        for (unsigned int j=0; j<A[i].size(); j++){
           std::cout<<A[i][j]<<" ";
        }

        std::cout<<"\n";
    }
    std::cout<<"\n";
    /*-------------------------------------------*/
    std::cout<<"let see if the vector y is implemented correctly\n";
    int n= 5;
    std::vector< std::vector<double> >y(4);
    for (unsigned int j=0; j<y.size(); j++){
        y[j].resize(n);
    }

    for (unsigned int i=0; i<y.size(); i++){
        for (unsigned int j=0; j<y[i].size(); j++){
           std::cout<<y[i][j]<<" ";
        }

        std::cout<<"\n";
    }

    std::vector<double> v0(2);
    v0[0]=1; v0[1]=5;
    std::vector<double> v1(2);

    std::vector< std::vector<double> >mat(2);
    for (unsigned int i =0; i<mat.size(); i++){
        mat[i].resize(2);
    }
    /*filling the matrix value*/
   mat[0][0]=2; mat[0][1]=3;
   mat[1][0]=4; mat[1][1]=5;

   /*Try the matrix multiplication function -- the matrice multiplication call the scalar product function */

    matrix_product(mat, v0, v1);

   std::cout<< v1[0] <<" ---" <<v1[1];


   /*Vector C */
   int g=9.810;
    double m1=1.080;
    double m2=0.360;
    double l=0.204;

    std::vector<double> C(6);
    C[0]=-((m2*l)/(m1+m2));
    C[1]=-1*C[0];
    C[2]=1/(m1+m2);
    C[3]=3/(4*l);
    C[4]=g*C[3];
    C[5]=3/(4*m2*l*l);


    /*vector b1, b2 and K*/
    std::vector<double> b1(4);
    std::vector<double> b2(4);
    for (unsigned int i=0; i<b1.size(); i++){
            b1[i]=0.0;
            b2[i]=0.0;
        if (i==1){
            b1[i]=C[2]/(1-(C[1]*C[3]));
            b2[i]=C[1]*C[5]/(1-(C[1]*C[3]));
        }
        if (i==3){
            b1[i]=(C[2]*C[3])/(1-(C[1]*C[3]));
            b2[i]=C[5]/(1-(C[1]*C[3]));
        }
    }

    /* for K c.f. segway_background.pdf p. 12 */
    std::vector<double> K(4);
    //f_vecinit(K);  // func.h
    K[0] = -0.7786; K[1] = -1.6220; K[2] = 25.4766; K[3] = 3.6236;


   /*Display linear system*/
   f_printlinearsystem(A,b1,b2,K);



    return 0;

}

    /*Another exercice of vector scalar product and matrix multiplication */
    /*function that return the scalar product */

double scalarproduct(std::vector<double> &n, std::vector<double> &p){
        double val = 0;
        if (n.size()==p.size()){
            for (unsigned int i=0; i<n.size(); i++){
                val=val+n[i]*p[i];
            }
        }
        return val;
    }
void matrix_product(std::vector< std::vector<double> > &m, std::vector<double> &v1, std::vector<double> &v2){
        if (m[0].size()==v1.size()){
            for (unsigned i=0; i<v1.size(); i++){
                v2[i]=scalarproduct(m[i], v1);
            }
        }
    }
void f_printlinearsystem(const std::vector< std::vector<double> > &A,const std::vector<double> &b1, const std::vector<double> &b2, const std::vector<double> &K){
    std::cout << "\nLinear system A*x+b1*F+b2*T:" <<"\n";

    std::cout<<"\n\t|";
    for (unsigned int x=0; x<A.size(); x++){
        for (unsigned int y=0; y<A[x].size(); y++){
            std::cout <<A[x][y] <<" ";

                if (x==0&&y==3){
                    std::cout <<"|x_1 + | "<<b1[0]<<" |*F + |"<<b2[0]<<" |*T\n\t|";
                }
                if (x==1&&y==3){
                    std::cout <<"|x_2 + | "<<b1[1]<<"|*F + |"<<b2[1]<<"|*T\n\t|";
                }
                if (x==2&&y==3){
                    std::cout <<"|x_3 + | "<<b1[2]<<"|*F + |"<<b2[2]<<"|*T\n\t|";
                }
                if (x==3&&y==3){
                    std::cout <<"|x_4 + | "<<b1[3]<<" |*F + |"<<b2[3]<<"|*T \n";
                }
        }
    }

}
