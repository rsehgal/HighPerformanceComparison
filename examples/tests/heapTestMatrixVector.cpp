#include <iostream>
//#include <common.h>
#include "Vector3DFast.h"
#include <blaze/Math.h>
#include "TBBStopWatch.h"
#include <fstream>
//#include <mm_malloc.h>
using namespace blaze;

void doworkVector3DFast(FastTransformationMatrix const &A, Vector3DFast const * __restrict__ a, Vector3DFast * __restrict__ b, int n)
{
  for(int i=0 ; i<n ; i++) //Start Vector Processing
    {
      A.MasterToLocal<0,-1>(a[i],b[i]); //Multiplying Matrix with Vector
    }
}

// let the compiler figure out the types ...
template<class M, class V>
__attribute__((noinline))
void 
doworkBlaze(M const &A, V const * __restrict__ a, V * __restrict__ b, int n)
{
  for(int i=0 ; i<n ; i++) //Start Vector Processing
    {
      b[i]=A*a[i];
    }
}


int main()
{
std::system("rm -rf timingHeapMatrixVector.txt");
std::ofstream outfile;
outfile.open("timingHeapMatrixVector.txt",std::ios::app); //File to store timing information

Vector3DFast temp(0,0,0);
double *matrixArray=new double[9];
for(int i=0;i<9;i++)
{
*(matrixArray+i)=2.5;
}

//Creating Matrix using Blaze
//DynamicMatrix<double,rowMajor> bl_A(3,3,matrixArray);
 StaticMatrix<double, 3UL, 3UL> bl_A;
 for(int i=0;i<3;i++)
   for(int j=0;j<3;j++)
   {
     bl_A(i,j)=2.5;
   }

//Creating Matrix using Sandro's Library
FastTransformationMatrix A;
A.SetRotation(matrixArray);
 A.print();

int iter=10;
time_t t;
time(&t);
srand((double)t);
int N=10000,doValidation=1;
for(int k=1;k<=iter;k++)
{
  int n=N*k;
  Vector3DFast *a=new Vector3DFast[n];
  Vector3DFast *b=new Vector3DFast[n];

  typedef   StaticVector<double,3UL,columnVector> BlazeVec;
  std::cout << sizeof(BlazeVec) << std::endl;
  void * memorypool1= _mm_malloc(sizeof(BlazeVec)*n,32);
  void * memorypool2= _mm_malloc(sizeof(BlazeVec)*n,32);
  BlazeVec *bl_a=new (memorypool1) BlazeVec[n];
  BlazeVec *bl_b=new (memorypool2) BlazeVec[n];
  //BlazeVec *bl_a=new BlazeVec[n];
  //  BlazeVec *bl_b=new BlazeVec[n];


  for(int i=0 ; i<n ; i++) //Filling data in vectors
    {
      //Generating Random data to fill Vector3DFast and Blaze 3D Vectors
      double tempa_x=rand()%100;
      double tempa_y=rand()%100;
      double tempa_z=rand()%100;
      

      //Filling Vector3DFast 3D Vectors
      a[i].Set(tempa_x,tempa_y,tempa_z);

      //Filling Blaze 3D Vectors
      StaticVector<int,3UL,columnVector> tempVect_a(tempa_x,tempa_y,tempa_z);
      bl_a[i]=tempVect_a;
    } //Data filling over

  std::cout<<"---------------------------------------------"<<std::endl;
  std::cout<<"Data filled successfully"<<std::endl;
  std::cout<<"Now lets do the real stuff"<<std::endl;
  if(doValidation)
    std::cout<<"Data Validation switched ON"<<std::endl;
  else
    std::cout<<"Data Validation switched OFF"<<std::endl;
  std::cout<<"---------------------------------------------"<<std::endl;
  
  //Adding Stopwatch
  StopWatch tmr;
  double Tacc=0.0;
  Tacc=0.0;
  tmr.getOverhead(100);
  Tacc=0.0;
  tmr.Start();
  doworkVector3DFast(A,a,b,n);
  
  //Real Stuff of Vector Processing
  tmr.Stop();
  Tacc=tmr.getDeltaSecs();
  std::cout<<"Execution Time N="<<n<<"  :  "<<Tacc<< " :::: ";
  outfile<<n<<"\t"<<Tacc<<"\t";


//----------------------------

Tacc=0.0;
tmr.getOverhead(100);
Tacc=0.0;
tmr.Start();

 doworkBlaze(bl_A,bl_a,bl_b,n);
  
tmr.Stop();
Tacc=tmr.getDeltaSecs();
std::cout<<Tacc<<" :::: "<<std::endl;
outfile<<Tacc<<std::endl;


//----------------------------------------

if(doValidation)
{
  int counter=0;
for(int i=0 ; i<n ; i++) //Do Validation
  {
    if((bl_b[i][0]-b[i].GetX()) || (bl_b[i][1]-b[i].GetY()) || (bl_b[i][2]-b[i].GetZ()))
      {
	counter++;
	/*
	std::cout<<"Result Differs : Validation Fails"<<std::endl;
	std::cout << b[i] << " " << bl_b[i] << std::endl;
	std::cout << a[i] << " " << bl_a[i] << std::endl;
	*/
      }
    //else
    //  std::cout<<"Result Matches : Validation Successfull"<<std::endl;
  }
 std::cout << counter << std::endl;
}

//delete a;delete b

}// iter loop ends
outfile.close();
} //main ends here
