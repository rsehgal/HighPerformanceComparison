#include <iostream>
#include <common.h>
#include "Vector3DFast.h"
#include <blaze/Math.h>
using namespace blaze;

int main()
{
Vector3DFast temp(0,0,0);
double *testArray=new double[9];
for(int i=0;i<9;i++)
{
*(testArray+i)=2.5;
}

time_t t;
time(&t);
srand((double)t);

int n=10,doValidation=1;
Vector3DFast *a=new Vector3DFast[n];
Vector3DFast *b=new Vector3DFast[n];
Vector3DFast *d=new Vector3DFast[n];
Vector3DFast *c=new Vector3DFast[n];

StaticVector<int,3UL,rowVector> *bl_a=new StaticVector<int,3UL,rowVector>[n];
StaticVector<int,3UL,rowVector> *bl_b=new StaticVector<int,3UL,rowVector>[n];
StaticVector<int,3UL,rowVector> *bl_d=new StaticVector<int,3UL,rowVector>[n];
StaticVector<int,3UL,rowVector> *bl_c=new StaticVector<int,3UL,rowVector>[n];

for(int i=0 ; i<n ; i++) //Filling data in vectors
{
//Generating Random data to fill Vector3DFast and Blaze 3D Vectors
double tempa_x=rand()%100;
double tempa_y=rand()%100;
double tempa_z=rand()%100;

double tempb_x=rand()%100;
double tempb_y=rand()%100;
double tempb_z=rand()%100;

//Filling Vector3DFast 3D Vectors
(a[i]).SetX(tempa_x);
(a[i]).SetY(tempa_y);
(a[i]).SetZ(tempa_z);

(b[i]).SetX(tempb_x);
(b[i]).SetY(tempb_y);
(b[i]).SetZ(tempb_z);


(d[i]).SetX(tempb_x);
(d[i]).SetY(tempb_y);
(d[i]).SetZ(tempb_z);


//Filling Blaze 3D Vectors
StaticVector<int,3UL,rowVector> tempVect_a(tempa_x,tempa_y,tempa_z);
StaticVector<int,3UL,rowVector> tempVect_b(tempb_x,tempb_y,tempb_z);

bl_a[i]=tempVect_a;
bl_b[i]=tempVect_b;
bl_d[i]=tempVect_b;
//std::cout<<a[i]<" :: ";
//std::cout<<bl_a[i]<<std::endl;

} //Data filling over

std::cout<<"---------------------------------------------"<<std::endl;
std::cout<<"Data filled successfully"<<std::endl;
std::cout<<"Now lets do the real stuff"<<std::endl;
if(doValidation)
std::cout<<"Data Validation switched ON"<<std::endl;
else
std::cout<<"Data Validation switched OFF"<<std::endl;
std::cout<<"---------------------------------------------"<<std::endl;

//Real Stuff of Vector Processing
for(int i=0 ; i<n ; i++) //Start Vector Processing
{
#ifdef USEAVX
//For AVX don't know why this extra stuff is required, otherwise SEGMENTATION FAULT
//Actually this should not be required and it should work like "c[i]=a[i]+b[i]+d[i]"
std::cout<<"------ USING AVX --------"<<std::endl;
Vector3DFast av(0,0,0);
av.SetX(a[i].GetX());
av.SetY(a[i].GetY());
av.SetZ(a[i].GetZ());

Vector3DFast bv(0,0,0);
bv.SetX(b[i].GetX());
bv.SetY(b[i].GetY());
bv.SetZ(b[i].GetZ());

Vector3DFast cv(0,0,0);

Vector3DFast dv(0,0,0);
dv.SetX(d[i].GetX());
dv.SetY(d[i].GetY());
dv.SetZ(d[i].GetZ());

cv=av+bv+dv;
c[i].SetX(cv.GetX());
c[i].SetY(cv.GetY());
c[i].SetZ(cv.GetZ());

#else
//For SSE it works as expected
std::cout<<"------ USING SSE --------"<<std::endl;
c[i]=a[i]+b[i]+d[i];
#endif

//BLAZE is OK in both cases
bl_c[i]=bl_a[i]+bl_b[i]+bl_d[i];

//std::cout<<a[i]<<" : "<<b[i]<<" :: "<<bl_a[i]<<" : "<<bl_b[i]<<" :::: "<<c[i]<<" : "<<bl_c[i]<<std::endl;
//std::cout<<c[i]<<" : "<<bl_c[i]<<std::endl;
}

if(doValidation)
{
for(int i=0 ; i<n ; i++) //Do Validation
  {
    if((bl_c[i][0]-c[i].GetX()) || (bl_c[i][1]-c[i].GetY()) || (bl_c[i][2]-c[i].GetZ()))
      std::cout<<"Result Differs : Validation Fails"<<std::endl;
    else
      std::cout<<"Result Matches : Validation Successfull"<<std::endl;
  }
}

} //main ends here