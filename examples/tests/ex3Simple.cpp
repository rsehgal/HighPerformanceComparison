/**
* A Sample example of using BLAZE library
* author "Raman "Sehgal"
*/
#include <iostream>
#include <blaze/Math.h>

using blaze::StaticVector;
using blaze::DynamicVector;

int main()
{
StaticVector<int,3UL> a( 4, -2, 5 );
StaticVector<int,3UL> b( 2, 5, -3 );
DynamicVector<int> c = a + b;
}
