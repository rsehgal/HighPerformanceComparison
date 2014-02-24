/**
* A Sample example of using BLAZE library
* author "Raman "Sehgal"
*/
#include <iostream>
#include <blaze/Math.h>
#include "TBBStopWatch.h"
#include "Vector3DFast.h"

using blaze::StaticVector;
using blaze::DynamicVector;

int main()
{
// Instantiation of a static 3D column vector. The vector is directly initialized as
// ( 4 -2 5 )
StaticVector<int,3UL> a( 4, -2, 5 );
//StaticVector<int,3UL> b( 4, -2, 5 );
// Instantiation of a dynamic 3D column vector. Via the subscript operator the values are set to
// ( 2 5 -3 )

DynamicVector<int> b( 3UL );
b[0] = 2;
b[1] = 5;
b[2] = -3;

// Adding the vectors a and b

StopWatch tmr;
double Tacc=0.0;
//tmr.getOverhead(10);
Tacc=0.0;
tmr.Start();
DynamicVector<int> c = a + b;
tmr.Stop();
Tacc=tmr.getDeltaSecs();

std::cout<<"Execution Time : "<<Tacc<<std::endl;

// Printing the result of the vector addition
std::cout << "c =\n" << c << "\n";

std::cout<<"==================================================================="<<std::endl;
std::cout<<"Starting Using Vector3DFast Class"<<std::endl;
std::cout<<"==================================================================="<<std::endl;

double scalar=3;
Vector3DFast av(4,-2,5);
Vector3DFast bv(2,5,-3);
Vector3DFast cv(0,0,0);

Tacc=0.0;
tmr.Start();
cv=av+bv;
tmr.Stop();
Tacc=tmr.getDeltaSecs();

std::cout<<"Execution Time : "<<Tacc<<std::endl;

std::cout << cv <<std::endl;

return 0;
}


/*
StopWatch tmr;
double Tacc=0.0;

tmr.getOverhead(10);
Tacc=0.0;
*/
