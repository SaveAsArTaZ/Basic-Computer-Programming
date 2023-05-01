#include <iostream>
using namespace std;
int findimax(int p[],int n)//function of finding max 
{
 int imax,max;
 imax=0;
 max=p[0];   
 for (int i=1;i<n;i++)
 {
  if (p[i]>=max)
  {
  max=p[i];
  imax=i;
  }
 }
 return imax;
}
int findimin(int p[],int n)//function of finding min
{
 int imin,min;
 imin=0;
 min=p[0];   
 for (int i=1;i<n;i++)
 {
  if (p[i]<=min)
  {
  min=p[i];
  imin=i;
  }
 }
 return imin;
}
bool halat_aval(int p[],int n,int imin)//p[i]>=p[i+1]>=....p[imin] then p[imin]<p[imin+1]<...<p[n-1]
{
  int flag=true;
    for (int i = 1; i < imin; i++)
    {
      if (p[i] >= p[i + 1])
        flag = true;
      else
      {
        flag = false;
        break;
      }
    }
    if (flag==true)
    {
     for (int i = imin; i < n-1 ; i++)
     {
       if (p[i] < p[i + 1])
         flag = true;
       else
       {
         flag = false;
         break;
       }
     }
    }
   return flag; 
}
bool halat_dovom(int p[],int n,int imax)//p[0]<=p[1]<=p[2]<=....p[imax]>p[imax+1]>p[imax+2]>...>p[n-1]
{
  bool flag=true;
    for (int i = 0; i < imax; i++)
    {
      if (p[i] <= p[i + 1])
        flag = true;
      else
      {
        flag = false;
        break;
      }
      if (flag == true)
      {
       for (int i = imax; i < n-1 ; i++)
       {
         if (p[i] > p[i + 1])
           flag = true;
         else
         {
           flag=false;
           break;
         }
       }
      }
    }
  return flag;
}
bool halat_sevom(int n)// n==1 so this is always true
{
 int flag=false;
 if (n==1)
 {
  flag=true; 
 }
 return flag;
}
bool halat_chaharom(int n)// n==2 so this is always true 
{
  int flag=false;
 if (n==2)
 {
   flag=true;
 }
}
int main()
{
 short  unsigned int n; 
 int *p;
 cin >> n;
 p=new int [n];
 bool flag=false;  
 int i,imax,imin;
 for (i=0;i<n;i++)
 {
  cin >> p[i];   
 }
 imin=findimin(p,n);
 imax = findimax(p, n);
 flag=halat_aval(p,n,imin);
 if (flag==false)
 {
  flag=halat_dovom(p,n,imax); 
 }
 if (n==1)
 {
  flag=halat_sevom(n); 
 }
 if (n==2)
 {
  flag=halat_chaharom(n); 
 }
 if (flag==true)
 cout <<"Yes"<<endl;
 else
 {
  cout <<"No"<<endl;
 }
 delete []p; 
 return 0;   
}