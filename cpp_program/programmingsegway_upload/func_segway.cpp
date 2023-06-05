/* Introduction to Scientific Programming, Programming project, 2019/2020 */
/* (c) Matthias Braendel, 2019 */
/* func_segway.cpp */

#include <vector>
#include "func.h"

void f_segway(  unsigned int                                m,
                const std::vector<double>                   &yt,
                const std::vector< std::vector<double> >    &A,
                const std::vector<double>                   &b1,
                std::vector<double>                         &F,
                const std::vector<double>                   &b2,
                const std::vector<double>                   &T,
                const std::vector<double>                   &K,
                std::vector<double>                         &ki){
    /* Matlab Pseudocode
        F = -K*y;
        dydt = A*y+b1*F+b2*T;
        dydt -> k, which is one of: (k1,k2,k3,k4)
    */
    std::vector<double> dydt(4), temp(4);
    f_vecinit(dydt);
    f_vecinit(temp);

    // #################
    // Your code here...

    //matrix scalar product

    /*for (unsigned i=0; i<K.size(); i++){
    //    F[m]=-K[i]*yt[i];
    //}*/
    F(m)=-f_scalarp(K,yt);
    // TASK 4.1: computing F = -K*y;
    // #################
    // #################
    // Your code here...
   /* for (unsigned j=0; j<A.size(); j++){
        for (unsigned n=0; n<A[j].size(); n++){
            temp[j]=temp[j]+A[j][n]*yt[n];
        }
    }*/
    f_matvecmult(temp,A,yt);
    // TASK 4.2: computing temp = A*y
    // #################
    // #################
    // Your code here...
   /* for (unsigned g=0; g<dydt.size(); g++){
   //     dydt[g]=temp[g]+b1[g]*F[m]+b2[g]*T[m];
   // }*/
    f_vecupd(temp, F(m), b1);
    f_vecupd(temp, T(m), b2);
    f_veccpy(dydt, temp);
	// do this with the vecupd and veccpy
    // TASK 4.3: computing dydt = temp + b1*F+b2*T
    // #################
    // #################
    // Your code here...
    f_veccpy(dydt,ki);
    // TASK 4.4: assign dydt to k with the veccpy function
    // #################
}
