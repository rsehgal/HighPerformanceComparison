/**
* A Sample example of using BLAZE library
* author "Raman "Sehgal"
*/
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
//StaticMatrix<double,3UL,3UL> a(testArray);
DynamicMatrix<double,rowMajor> A(3,3,testArray);
DynamicMatrix<double,rowMajor> B(3,3,testArray);
DynamicMatrix<double,rowMajor> C(3,3);
std::cout<<A<<std::endl;
//std::cout<<b<<std::endl;
//StaticVector<double,3UL,blaze::rowVector> b(2,2,2);
DynamicVector<double> a(3UL);
a[0]=2;
a[1]=2;
a[2]=2;
StaticVector<double,3UL> b( 0, 0, 0 );

b = A * a;
 std::cout<<a<<std::endl;
std::cout<<b<<std::endl;
C=A*B;
std::cout<<C<<std::endl;
std::cout<<"=========== Using Sandro's Class =============="<<std::endl;
Vector3DFast av(2,2,2);
Vector3DFast bv;
FastTransformationMatrix Av;
Av.SetRotation(testArray);

FastTransformationMatrix Bv;
Bv.SetRotation(testArray);

FastTransformationMatrix Cv;
//std::cout<<Av<<std::endl;
//bv = Av * av;
Av.MasterToLocal<0,1>(av,bv); //Multiplying Matrix with Vector
std::cout<<av<<std::endl;
std::cout<<bv<<std::endl;
Av.printMatrix();
std::cout<<std::endl<<"--------------------------------------------"<<std::endl;
Av.Multiply<0,1>(&Bv);
Av.printMatrix();
std::cout<<std::endl;

}
