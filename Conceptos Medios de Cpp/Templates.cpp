template <class myType>
myType GetMax (myType a, myType b) 
{
 return (a>b?a:b);
}
-------------------------------------------------------------------------------------------
int x, y;
GetMax <int> (x,y);
-------------------------------------------------------------------------------------------
// function template
#include <iostream>
using namespace std;

template <class T>
T GetMax (T a, T b) 
{
  T result;
  result = (a>b)? a : b;
  return (result);
}

int main () 
{
  int i=5, j=6, k;
  long l=10, m=5, n;
  k=GetMax<int>(i,j);
  n=GetMax<long>(l,m);
  cout << k << endl;
  cout << n << endl;
  return 0;
}
-------------------------------------------------------------------------------------------
// function template II
#include <iostream>
using namespace std;

template <class T>
T GetMax (T a, T b) {
  return (a>b?a:b);
}

int main () {
  int i=5, j=6, k;
  long l=10, m=5, n;
  k=GetMax(i,j);
  n=GetMax(l,m);
  cout << k << endl;
  cout << n << endl;
  return 0;
}
-------------------------------------------------------------------------------------------
template <class T, class U>
T GetMin (T a, U b) {
  return (a<b?a:b);
}
-------------------------------------------------------------------------------------------
int i,j;
long l;
i = GetMin<int,long> (j,l);
-------------------------------------------------------------------------------------------
template <class T>
class mypair 
{
    T values [2];
  public:
    mypair (T first, T second)
    {
      values[0]=first; values[1]=second;
    }
};
-------------------------------------------------------------------------------------------
