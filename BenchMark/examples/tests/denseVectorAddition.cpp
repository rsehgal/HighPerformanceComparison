/**
* A Sample example of using BLAZE library
* author "Raman "Sehgal"
*/
#include <iostream>
#include <blaze/Math.h>
#include "TBBStopWatch.h"
#include "Vector3DFast.h"
#include <fstream>

#include <cstdlib>
#include <time.h>
//#define N 30000

using blaze::StaticVector;
using blaze::DynamicVector;
using namespace blaze;
int main()
{
std::system("rm -rf timingVectorAddition.txt");
std::ofstream outfile;
outfile.open("timingVectorAddition.txt",std::ios::app);

int n=10000,N=0;
int iter=20;
int store=1,doValidation=1;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

for(int i=1;i<=iter;i++)
{
//-------------------------------
//For generating random numbers
time_t t;
time(&t);
srand((double)t);
//-------------------------------
N=n*i;
double *testArray=new double[N*3];
double *Vector3DFastArray=new double[N*3];
double *BlazeArray=new double[N*3];

for(int k=0 ; k<3*N ; k++)
{
 testArray[k]=rand()%100; //Assigning random number between 0 and 100   // previous giving 1.2
 Vector3DFastArray[k]=0.0;
 BlazeArray[k]=0.0;
}

StopWatch tmr;
double Tacc=0.0;
tmr.getOverhead(100);
Tacc=0.0;
tmr.Start();
for(int j=0;j<N;j++)
{
//For testing purpose filling same array in both av and bv
Vector3DFast av(testArray+(3*j));
Vector3DFast bv(testArray+(3*j));
Vector3DFast cv;
cv=av+bv;
if(store)  //requires for data Validation
{
*(Vector3DFastArray+(3*j)+0)=cv.GetX();
*(Vector3DFastArray+(3*j)+1)=cv.GetY();
*(Vector3DFastArray+(3*j)+2)=cv.GetZ();
}
//sumv+=cv;
}
tmr.Stop();
Tacc=tmr.getDeltaSecs();
std::cout<<"Execution Time N="<<N*3<<"  :  "<<Tacc<< " :::: ";
outfile<<N<<"\t"<<Tacc<<"\t";

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Below code uses Blaze and utilizing its 3D vectors to do dense vector addition
Tacc=0.0;
tmr.getOverhead(100);
Tacc=0.0;
tmr.Start();
for(int j=0;j<N;j++)
{
//DynamicVector<double> a( 3 ), b( 3 ), c( 3 );
StaticVector<double,3UL,rowVector> a(3UL, testArray+(3*j));

//StaticVector<double,3UL> b( 2, 5, -3 );
StaticVector<double,3UL,rowVector> b( 3UL, testArray+(3*j) );

StaticVector<double,3UL,rowVector> c;
c=a+b;
//sv+=c;
if(store)  //requires for data Validation
{
*(BlazeArray+(3*j)+0)=c[0];
*(BlazeArray+(3*j)+1)=c[1];
*(BlazeArray+(3*j)+2)=c[2];
}
}
tmr.Stop();
Tacc=tmr.getDeltaSecs();
std::cout<<Tacc<<" :::: "<<std::endl;
outfile<<Tacc<<std::endl;

//Validating the results.
if(doValidation)
for(int k=0 ; k<3*N ; k++)
  {
	if( (Vector3DFastArray[k]-BlazeArray[k]) )
	    std::cout<<"Value Differs"<<std::endl;
  }
}

outfile.close();
std::cout<<"******* Finished ********"<<std::endl;


}
