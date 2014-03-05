#include <blaze/Math.h>
using namespace blaze;
int main()
{
//std::typedef 
StaticVector<int,3UL> vecArr[100000]; 
StaticVector<int,3UL> *vArr=new StaticVector<int,3UL>[100000];
std::cout<<vecArr[0]<<std::endl;
std::cout<<vArr[0]<<std::endl;
return 0;
}
