#include <iostream>
using namespace std;
int main()
{
 unsigned long long int a,b;
 long long int c;
 cin >> a >> b;
 c=a-b;
 if (c<0)
 {
  c=-c;   
 }
 for (int i=2;i<=c;i++)
 {
  if(c % i ==0)
  {
   cout << i << " ";   
  }   
 }


 return 0;   
}