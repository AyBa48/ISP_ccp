/* Introduction to Scientific Programming, Programming project, 2019/2020 */
/* (c) Matthias Braendel, 2019 */
/* func_rk4.cpp */

#include <vector>
#include "func.h"
#include "func_segway.h"

void f_rk4( std::vector< std::vector<double> >          &y,
            const std::vector<double>                   &tspan,
            const std::vector< std::vector<double> >    &A,
            const std::vector<double>                   &b1,
            std::vector<double>                         &F,
            const std::vector<double>                   &b2,
            const std::vector<double>                   &T,
            const std::vector<double>                   &C,
            const std::vector<double>                   &K){
    /* initialization of temporary vectors */
    // #################
    // Your code here...
    /*Declaration of temporary vector*/
    std::vector<double> k1(4);
    std::vector<double> k2(4);
    std::vector<double> k3(4);
    std::vector<double> k4(4);
    std::vector<double> yt(4);
    std::vector<double> yn(4);
    /*Initialization*/
    f_vecinit(k1);
    f_vecinit(k2);
    f_vecinit(k3);
    f_vecinit(k4);
    f_vecinit(yn);
    f_vecinit(yt);
    // TASK 3.1: declare and initialize the temporary vectors k1,k2,k3,k4,yn,yt
    // #################
    // #################
    // Your code here...

    double h= 1.0/100;

    // TASK 3.2: compute the time step size h
    // #################
    /* classical Runge-Kutta method */
    for(unsigned int m = 0; m < tspan.size(); m++){
        // #################
        // Your code here...
        // TASK 3.3+4: implement the following pseudo code:
        // (1) yn = y[:][m]; // m-th colum for the m-th time step of y

        // (2) yt = yn;

        // (3) f_segway(yt,...,k1); // new k1
        f_segway(m,yt,A,b1,F,b2,T,K,k1);

        // (4) yt = yn+0.5*h*k1;
        for (unsigned int j=0; j<yt.size(); j++){
                for(unsigned int x=0; x<k1.size(); x++){
                    yt[j]=yn[j]+0.5*h*k1[x];
                }
        }
        // (5) f_segway(yt,...,k2); // new k2
       f_segway(m,yt,A,b1,F,b2,T,K,k2);

        // (6) yt = yn+0.5*h*k2;
        for(unsigned int j=0; j<yt.size(); j++){
                for(unsigned int x=0; x<k1.size(); x++){
                    yt[j]=yn[j]+0.5*h*k2[x];
                }
        }

        // (7) f_segway(yt,...,k3); // new k3
       f_segway(m,yt,A,b1,F,b2,T,K,k3);

        // (8) yt = yn+h*k3;
          for(unsigned int j=0; j<yt.size(); j++){
                for(unsigned int x=0; x<k1.size(); x++){
                    yt[j]=yn[j]+h*k3[x];
                }
        }
        // (9) f_segway(yt,...,k4); // new k4
        f_segway(m,yt,A,b1,F,b2,T,K,k4);
        // #################
        // compute new k1
        f_veccpy(yt,yn); // func.h
        f_segway(m,yt,A,b1,F,b2,T,K,k1); // func_segway.h
        // compute new k2
        f_segway(m,yt,A,b1,F,b2,T,K,k2);
        // compute new k3
        f_segway(m,yt,A,b1,F,b2,T,K,k3);
        // compute new k4
        f_segway(m,yt,A,b1,F,b2,T,K,k4);
        /* update y */
        // #################
        // Your code here...
        for (unsigned int l=0; l<y.size(); l++){
            for(unsigned int n=0; n<y[l].size(); n++){
                y[l][n]=y[l][n] + (h/6*(k1[l]+2*k2[l]+2*k3[l]+k4[l]));
            }
        }
        // TASK 3.4: update new column of y with the old column and the k's
        // y[:][m+1] = y[:][m]+h/6*(k1+2*k2+2*k3+k4);
        // #################
    }
}
