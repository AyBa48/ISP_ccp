/* class_algebra, class fraction, class vector, class matrix,
  an regarding functions, constructor, add..., show, ....
Matthias Braendel, 2019 */
#include <string>
//#include<iostream>
#include "fraction.h"

// private
/* ------------------------------------------------------- */
void Fraction::reduce(){
    int mod;

	if (y!=0 && y!=1 && x!=0){
            for (int i=1; i<=x && i<=y; i++){
                if (x%i==0 && y%i==0){
                    mod=i;
                }
            }
	}
	//cout << "gcd = : " << mod << "\n";
	if (mod!=0){
        x = x/mod;
        y = y/mod;
    }
    cout << "\ngcd = : " << mod << "\n";
    cout << "\nx = : " << x << ",y = :"<<y<< "\n";


}

// public
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/*string Fraction::get(){

  if(y == 1 || y == 0 || x == 0){

    return "";//to_string(x)
  }else{

    return "";//to_string(x) + "/" + to_string(y);
  }
}*/
void Fraction::show(){
  cout << "The fraction is " << x << "/" << y << "\n"; //<< this->get() << endl;
}
Fraction Fraction::operator+(const Fraction &f1){
  Fraction z;
  z.y = f1.y*this->y;
  z.x = f1.x*this->y + this->x*f1.y;
  z.reduce();
  return z;
}
Fraction Fraction::operator-(){
  this->x = -x;
  return *this;
}
//body of the operator -
Fraction Fraction::operator-(const Fraction &f2){
    Fraction mn;
    mn.y= f2.y*this->y;
    mn.x= f2.x*this->y - this->x*f2.y;
    mn.reduce();
    return mn;
}
//Body of the operator *
Fraction Fraction::operator*(const Fraction &f3){
    Fraction mt;
    mt.x=f3.x*this->x;
    mt.y=f3.y*this->y;
    mt.reduce();
    return mt;
}
//Body of the operator /
Fraction Fraction::operator/(const Fraction &f4){
    Fraction  div;
    div.x=f4.x*this->y;
    div.y=f4.y*this->x;
    div.reduce();
    return div;
}
//Body of the operator ==
Fraction Fraction::operator==(const Fraction &f5){

    if (this->x==f5.x && this->y==f5.y ){
        return true;
    }
    else{
		return false;
	}
}
//Body of the Fraction !=
Fraction Fraction::operator!=(const Fraction &f6){

    if (this->x!=f6.x && this->y!=f6.y ){
        return true;
    }
    else{
	 	return false;
	}
}
//Body of the operator <
Fraction Fraction::operator<(const Fraction &F7){

    if (this->x<F7.x && this->y<F7.y ){
        return true;
    }
    else{
		return false;
	}
}
//Body of the operator >
Fraction Fraction::operator>(const Fraction &f8){

    if (this->x>f8.x && this->y>f8.y ){
        return true;
    }
    else{
		return false;
	}
}
