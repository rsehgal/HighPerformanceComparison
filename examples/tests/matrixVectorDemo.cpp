#include <iostream>
#include <blaze/Math.h>
#include <common.h>
#include "Vector3DFast.h"

using blaze::StaticVector;
using blaze::DynamicVector;
using blaze::DynamicMatrix;
using blaze::StaticMatrix;
using namespace blaze;

int main()
{
double *testArray=new double[9];
for(int i=0;i<9;i++)
{
*(testArray+i)=2.5;
}
DynamicMatrix<double,rowMajor> A(3,3,testArray);
std::cout<<A<<std::endl;
StaticVector<double,3UL,columnVector> a( 2, 2, 2 );
StaticVector<double,3UL,columnVector> b( 0, 0, 0 );
b = A * a;
std::cout<<a<<std::endl;
std::cout<<b<<std::endl;
}
