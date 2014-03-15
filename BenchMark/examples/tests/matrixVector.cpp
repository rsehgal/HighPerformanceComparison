/**
* A Sample example of using BLAZE library
* author "Raman "Sehgal"
*/
#include <iostream>
#include <blaze/Math.h>
#include <common.h>
#include "TBBStopWatch.h"
#include "Vector3DFast.h"
#include <fstream>
//#define N 30000
#include <cstdlib>
#include <time.h>

using blaze::StaticVector;
using blaze::DynamicVector;
using blaze::DynamicMatrix;
using blaze::StaticMatrix;
using namespace blaze;

int main()
{
std::system("rm -rf timingMatrixVector.txt");
std::ofstream outfile;
outfile.open("timingMatrixVector.txt",std::ios::app);

double *matrixArray=new double[9]; //Transformation Matrix array
for(int i=0;i<9;i++)
{
*(matrixArray+i)=2.5;
}
//Creating a Matrix using Blaze
DynamicMatrix<double,rowMajor> A(3,3,matrixArray);
std::cout<<A<<std::endl;
//Creating Matrix using Sandro's Library
FastTransformationMatrix Av;
Av.SetRotation(matrixArray);

//Actual Benchmarking stuff (doing transformation of dense Vector of N dimension using transformation matrix)
int n=10000,N=0;
int iter=20;
int store=1,doValidation=1;
int scalar=0.001;
 //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


for(int i=1;i<=iter;i++)
{
time_t t;
time(&t);
srand((double)t);

N=n*i;
double *testArray=new double[N*3];
double *Vector3DFastArray=new double[N*3];
double *BlazeArray=new double[N*3];
//double *denseBlazeArray=new double[N*3];
for(int k=0 ; k<3*N ; k++)
{
 //testArray[k]=1.2;
  testArray[k]=rand()%100; //Assigning random number between 0 and 100   // previous giving 1.2
}

StopWatch tmr;
double Tacc=0.0;

double sum=0;
int ent=10;
//for(int s=0 ; s<ent ; s++)

{
tmr.getOverhead(100);
Tacc=0.0;
tmr.Start();
for(int j=0;j<N;j++)
{
Vector3DFast av(testArray+(3*j));
Vector3DFast bv;
Av.MasterToLocal<0,1>(av,bv); //Multiplying Matrix with Vector
if(store)
{
*(Vector3DFastArray+(3*j)+0)=bv.GetX();
*(Vector3DFastArray+(3*j)+1)=bv.GetY();
*(Vector3DFastArray+(3*j)+2)=bv.GetZ();
}
}
tmr.Stop();
Tacc=tmr.getDeltaSecs();
//sum+=Tacc;
}
std::cout<<"Execution Time N="<<N<<"  :  "<<Tacc<< " :::: ";
//outfile<<N*3<<"\t"<<sum/ent<<"\t";
outfile<<N<<"\t"<<Tacc<<"\t";

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Below code uses Blaze and utilizing its 3D vectors to do dense vector addition
sum=0;
//for(int s=0 ; s<ent ; s++)
{
tmr.getOverhead(100);
Tacc=0.0;
tmr.Start();
for(int j=0;j<N;j++)
{
//DynamicVector<double> a( 3 ), b( 3 ), c( 3 );
StaticVector<double,3UL> a(3UL, testArray+(3*j));
//DynamicVector<double,rowVector> a(3UL, testArray+(3*j));
//StaticVector<double,3UL> a( 0, 0, 0 );
StaticVector<double,3UL> b( 0, 0, 0 );
b = A * a;
if(store)
{
*(BlazeArray+(3*j)+0)=b[0];
*(BlazeArray+(3*j)+1)=b[1];
*(BlazeArray+(3*j)+2)=b[2];
}
}
tmr.Stop();
Tacc=tmr.getDeltaSecs();
//sum+=Tacc;
}
//std::cout<<Tacc<<std::endl;
std::cout<<Tacc<<" :::: "<<std::endl;
//std::cout<<sumv<<"  ::  "<<sv;//<<std::endl;
//outfile<<sum/ent<<std::endl;
outfile<<Tacc<<std::endl;



//Validating the results.
if(doValidation)
{
for(int k=0 ; k<3*N ; k++)
  {
	if( (Vector3DFastArray[k]-BlazeArray[k]) )
	    std::cout<<"Value Differs"<<std::endl;
  }
}

}

outfile.close();
std::cout<<"******* Finished ********"<<std::endl;

}
