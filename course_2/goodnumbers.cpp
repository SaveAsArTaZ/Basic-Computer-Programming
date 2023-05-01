#include <iostream>
using namespace std;
int main ()
{
 unsigned long long int i=1,d=2;
 unsigned short int k,m;
 cin >> k;
 while (m<k)
 {
  m=0;
  i+=d;
  for (int j=1;j <=i;j++)
  {
   if (i % j==0)
   {
    m+=1;   
   }
  }
  d+=1;
 }
 if (k==1)
 cout <<1;
 else
 cout <<i;
 return 0;   
}