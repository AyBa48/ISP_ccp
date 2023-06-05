/* Introduction to Scientific Programming, Programming project, 2019/2020 */
/* (c) Matthias Braendel, 2019 */
/* main.cpp */

#include <iostream>
#include <cstdlib>
#include <vector>

#include "func.h"
#include "func_segway.h"
#include "func_rk4.h"

using namespace std;

int main()
{
    f_introduction(); // func.h

    /* time options */
    double tsta = 0.0; // time start
    double tend = 10.0; // time end
    int framerate = 100;
    // #################
    // Your code here...
    /* n (number of time-steps)*/
    double n=(framerate*(tend-tsta))+1;
    std::vector<double>tspan(n);
    // TASK 1.1: calculate n (number of time-steps), create the tspan vector to save the time-steps
    // #################
    f_vecinit(tspan); // func.h
    // #################
    // Your code here... done in func.cpp
    // TASK 2.1+2.2: complete the following two functions to fill tspan and create the desired output
    // #################
    f_filltspan(tspan,tsta,tend,framerate); // func.h
    f_printtimeoptions(tspan,tsta,tend,framerate); // func.h

    /* model parameters */
    // #################
    // Your code here...
    int g=9.810;
    double m1=1.080;
    double m2=0.360;
    double l=0.204;
    // TASK 1.2: variables g,m1,m2,l
    // #################
    // #################
    // Your code here... done in func.cpp
    // TASK 2.3: complete the following function, similar to f_printtimeoptions
    // #################
    f_printmodelparameters(g,m1,m2,l); // func.h

    /* coefficients */
    // #################
    // Your code here...
    std::vector<double> C(6);
    C[0]=-((m2*l)/(m1+m2));
    C[1]=-1*C[0];
    C[2]=1/(m1+m2);
    C[3]=3/(4*l);
    C[4]=g*C[3];
    C[5]=3/(4*m2*l*l);
    // TASK 1.3: implement the coefficients in a vector, see segway_background.pdf page 5
    // #################
    // #################
    // Your code here...done in func.cpp
    // TASK 2.4: complete the fowlling function in the same way as you have done for f_printtimeoptions and f_printmodelparameters
    // #################
    f_printcoefficients(C); // func.h

    /* disturbance */
    double valT = 1.0;
    double tdiststa = 1.0;
    double tdistend = 1.1;
    int ndist = (tdistend-tdiststa)*framerate+1;
    std::vector<double> tdist(ndist);
    f_vecinit(tdist); // func.h
    f_filltspan(tdist,tdiststa,tdistend,framerate); // func.h
    std::vector<double> T(n);
    f_vecinit(T); // func.h
    f_filldisturbance(T,valT,tdist,framerate); // func.h
    // #################
    // Your code here...done in func.cpp
    // TASK 2.5: complete the following function, similar to f_printtimeoptions
    // #################
    f_printdisturbance(valT,tdiststa,tdistend,framerate); // func.h

    /* system matrix A */
    // #################
    // Your code here...
    std::vector<std::vector<double> >A(4);
    for (unsigned int k=0; k<A.size(); k++){
        A[k].resize(4);
    }
    f_matinit(A);
    //for(unsigned int i=0; i<A.size(); i++){
     //   for(unsigned int j=0; j<A[i].size(); j++){
                //A[i][j]=0.0;
                //if (i==0&&j==1){
                    A[0][1]=1;
               // }
               // if(i==1&&j==2){
                    A[1][2]=(C[1]*C[4])/(1-(C[1]*C[3]));
                //}
               // if(i==2&&j==3){
                    A[2][3]=1;
               // }
                //if(i==3&&j==2){
                    A[3][2]=C[4]/(1-(C[1]*C[3]));
               // }
        //}
    //}
    // TASK 1.4: implement the system matrix A (a 4x4 matrix) and fill it accordingly to segway_background.pdf page 8
    // #################
    /* for b1,b2 and F (and T) c.f. segway_background.pdf p. 8 */
    // #################
    // Your code here...
    std::vector<double> b1(4);
    std::vector<double> b2(4);
    f_vecinit(b1);
    f_vecinit(b2);
   // for (unsigned int i=0; i<b1.size(); i++){
            //b1[0]=0.0;
           // b2[0]=0.0;
       // if (i==1){
            b1[1]=C[2]/(1-(C[1]*C[3]));
            b2[1]=C[1]*C[5]/(1-(C[1]*C[3]));
       // }
       // if (i==3){
            b1[3]=(C[2]*C[3])/(1-(C[1]*C[3]));
            b2[3]=C[5]/(1-(C[1]*C[3]));
      //  }
    //}
    // TASK 1.5: do the same for the vectors b1 and b2
    // #################
    std::vector<double> F(n);
    f_vecinit(F); // func.h
    /* for K c.f. segway_background.pdf p. 12 */
    std::vector<double> K(4);
    f_vecinit(K);  // func.h
    K[0] = -0.7786; K[1] = -1.6220; K[2] = 25.4766; K[3] = 3.6236;
    // #################
    // Your code here... done in func.cpp
    // TASK 2.6: complete f_printlinearsystem
    // #################
    f_printlinearsystem(A,b1,b2,K); // func.h
    f_systemhasbeensetup(); // func.h

    // testing
    /* f_vecshow(b1); f_matshow(A); */

    /* Solution of the problem
    we have:
      tspan - vector - timespan of the simulation
      y0    - vector - initial condition
      A     - matrix - system matrix (4x4)
      b1    - vector - vector for the force
      F     - vector - force (scalar over time)
      b2    - vector - vector for the disturbance
      T     - vector - disturbance (scalar over time)
      C     - vector - coefficients of the equations of motion
      K     - vector - control matrix
    we want:
      t - vector - basically tspan
      y - matrix - contains the solution over time, (4x#steps)
                   x,x',a,a', position, velocity, angle, angle velocity
                   and y0
      F - vector - force from control over time*/

    /* creating space for y */
    /*matrix 4x(nof time steps) that contains for every time steps the vector of the 4 unknowns*/
    // #################
    // Your code here...
    std::vector< std::vector<double> > y(4);
    for (unsigned int j=0; j<y.size(); j++){
        y[j].resize(n);
    }
    // TASK 1.6: create a matrix 4x(nof time steps) that contains for every time steps the vector of the 4 unknowns
    // #################
    f_matinit(y);

    /* Runge-Kutta-method */
    // #################
    // Your code here...
    // TASK 3: complete the f_rk4 runge-kutta method
    // #################
    f_rk4(y,tspan,A,b1,F,b2,T,C,K); // func_rk4.h
    f_succeed(); // func.h

    /* printing values to file */
    f_fileoutput(tspan,y,F,T); // func.h

    return 0;
}
