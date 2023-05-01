#include <iostream>
using namespace std;
int prime (int x)
{
 bool flag = true;
 for (int i=2;i < x  ;i++ )
 {
  if (x % i == 0 )
  {
   flag = false;
   break;
  }
 }
 return flag;    
}
int main ()
{
 int a , b,d=0;   
 bool flag2;
 cin  >> a ;
 cin  >> b ;
 for (int i=a+1;i < b ; i++)
 {
  flag2=prime(i);
  if (flag2==true )
  {
  d+=1;
  }
  if ( flag2==true )
  {
    if(d == 1)
    {
     cout << i;
    }
    else
    {
     cout <<","<<i;
    }
    
  }
 }
}