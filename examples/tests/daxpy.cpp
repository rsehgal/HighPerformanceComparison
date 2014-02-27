/**
* A Sample example of using BLAZE library
* author "Raman "Sehgal"
*/
#include <iostream>
#include <blaze/Math.h>
#include "TBBStopWatch.h"
#include "Vector3DFast.h"

//#define N 30000

using blaze::StaticVector;
using blaze::DynamicVector;
using namespace blaze;
int main()
{
int n=10000,N=0;
int iter=30;
int store=0;
int scalar=0.001;
//double testArray[]={4,-2,5};

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Using Vector3DFast Library
Vector3DFast fv;
std::cout << fv <<std::endl;

Vector3DFast sumv; //for storing sum using Vector3DFast
DynamicVector<double,rowVector> sv(3); //for storing sum using Blaze


for(int i=1;i<=iter;i++)
{
N=n*i;
double *testArray=new double[N*3];
double *Vector3DFastArray=new double[N*3];
double *BlazeArray=new double[N*3];
double *denseBlazeArray=new double[N*3];
for(int k=0 ; k<3*N ; k++)
{
 testArray[k]=1.2;
}

StopWatch tmr;
double Tacc=0.0;
tmr.getOverhead(100);
Tacc=0.0;
tmr.Start();
for(int j=0;j<N;j++)
{
Vector3DFast av(testArray+(3*j));
Vector3DFast bv(testArray+(3*j));
Vector3DFast cv;
cv = bv + av*scalar;
if(store)
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
c = b + a*scalar;
//sv+=c;
if(store)
{
*(BlazeArray+(3*j)+0)=c[0];
*(BlazeArray+(3*j)+1)=c[1];
*(BlazeArray+(3*j)+2)=c[2];
}
}
tmr.Stop();
Tacc=tmr.getDeltaSecs();
//std::cout<<Tacc<<std::endl;
std::cout<<Tacc<<" :::: "; //std::endl;
//std::cout<<sumv<<"  ::  "<<sv;//<<std::endl;


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Utilizing dense vector mechanism of Blaze itself
Tacc=0.0;
tmr.getOverhead(100);
Tacc=0.0;
tmr.Start();
const int sz=N*3;

DynamicVector<double> da(sz, testArray);
DynamicVector<double> db( sz, testArray );
DynamicVector<double> dc;
dc = db+ da*scalar;
if(store)
{
for(int j=0;j<3*N;j++)
{
*(denseBlazeArray+j)=dc[j];
}
}
tmr.Stop();
Tacc=tmr.getDeltaSecs();
std::cout<<Tacc<<"  :::: ";//std::endl;
std::cout<<sumv<<"  ::  "<<sv;//<<std::endl;

//Validating the results.
for(int k=0 ; k<3*N ; k++)
  {
	if( (Vector3DFastArray[k]-denseBlazeArray[k]) || (Vector3DFastArray[k]-BlazeArray[k]) || (denseBlazeArray[k]-BlazeArray[k]) )
	    std::cout<<"Value Differs"<<std::endl;
  }
}

std::cout<<"******* Value ********"<<std::endl;
//std::cout<<sumv<<" :::: "<<sv<<std::endl;
//std::cout<<"----------------------"<<std::endl;
//std::cout<<dc<<std::endl;

}
