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

int main()
{
int n=10000,N=0;
int iter=50;
double testArray[]={4,-2,5};
/*
for(int i=1;i<=iter;i++)
{
N=n*3*i;
DynamicVector<double> a( N ), b( N ), c( N );
// ... Initialization of the vectors

StopWatch tmr;
double Tacc=0.0;

tmr.getOverhead(100);
Tacc=0.0;
tmr.Start();
c = a + b;
tmr.Stop();
Tacc=tmr.getDeltaSecs();
std::cout<<"Execution Time N="<<N<<"  :  "<<Tacc<<std::endl;
}
*/
std::cout<<"==================================================================="<<std::endl;
std::cout<<"Starting Using Vector3DFast Class"<<std::endl;
std::cout<<"==================================================================="<<std::endl;
//Using new Libraries
Vector3DFast fv;
std::cout << fv <<std::endl;
//Vector3DFast bv,cv,av,sumv;
Vector3DFast sumv;
for(int i=1;i<=iter;i++)
{
N=n*i;

StopWatch tmr;
double Tacc=0.0;
tmr.getOverhead(100);
Tacc=0.0;
tmr.Start();
for(int j=0;j<N;j++)
{
Vector3DFast bv(2,5,-3),cv;//,av(4,-2,5);
Vector3DFast av(testArray);
cv=av+bv;
sumv+=cv;
}
tmr.Stop();
Tacc=tmr.getDeltaSecs();
std::cout<<"Execution Time N="<<N*3<<"  :  "<<Tacc<<std::endl;
//std::cout << cv <<std::endl;
}
std::cout<<sumv<<std::endl;
//std::cout << bv <<std::endl;
//Vector3DFast cv(0,0,0);

/*
std::cout<<"==================================================================="<<std::endl;
std::cout<<"Starting Using Vector3DFast Class"<<std::endl;
std::cout<<"==================================================================="<<std::endl;
//Using new Libraries
Vector3DFast fv;
std::cout << fv <<std::endl;
//Vector3DFast bv,cv,av,sumv;
Vector3DFast sumv;
for(int i=1;i<=iter;i++)
{
N=n*i;
Vector3DFast av=new Vector3DFast();
Vector3DFast bv=new Vector3DFast();
Vector3DFast cv=new Vector3DFast();
StopWatch tmr;
double Tacc=0.0;
tmr.getOverhead(100);
Tacc=0.0;
tmr.Start();

cv=av+bv;

tmr.Stop();
Tacc=tmr.getDeltaSecs();
std::cout<<"Execution Time N="<<N*3<<"  :  "<<Tacc<<std::endl;
//std::cout << cv <<std::endl;
}
*/
std::cout<<"==================================================================="<<std::endl;
std::cout<<"Starting Using BLAZE Manually"<<std::endl;
std::cout<<"==================================================================="<<std::endl;
//Using new Libraries
DynamicVector<double> sv(3);
for(int i=1;i<=iter;i++)
{
N=n*i;
StopWatch tmr;
double Tacc=0.0;

tmr.getOverhead(100);
Tacc=0.0;
tmr.Start();
for(int j=0;j<N;j++)
{
//DynamicVector<double> a( 3 ), b( 3 ), c( 3 );
StaticVector<int,3UL> a( testArray );
StaticVector<int,3UL> b( 2, 5, -3 );
StaticVector<int,3UL> c;
c=a+b;
sv+=c;
}
tmr.Stop();
Tacc=tmr.getDeltaSecs();
std::cout<<"Execution Time N="<<N*3<<"  :  "<<Tacc<<std::endl;

//std::cout
} 
std::cout<<sv<<std::endl;
}
