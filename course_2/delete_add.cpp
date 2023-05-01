#include<iostream>
#include<string.h>
using namespace std;
int removing (int x[],int deleted_array_number,int n)
{
 for (int j=deleted_array_number;j<n-1;j++)
 {
  x[j]=x[j+1];      
 }
 return *x;
}
int adding (int x[],int added_array_number,int n,int added_number)
{
 for (int j=n-1;j>=added_array_number;j--)
 {
  x[j+1]=x[j];   
 }
 x[added_array_number]=added_number;   
 return *x;
}
int main ()
{
 int m,j,n,deleted_array_number,added_array_number,added_number; 
 char order[20];  
 cin >> n >> m;
 int x[200];
 for (int i=0;i<n;i++)
 {
      cin >> x[i];
 }
 for (int i=0;i<m;i++)
 {
   cin >> order;
  if (strcmp(order,"add")==0)
  {
   cin >>added_array_number >>added_number;
   x[200]=adding(x,added_array_number,n,added_number); 
   for (j=0;j<n+1;j++)
   {
       cout << x[j] << " ";
   }
    cout <<endl;
    n+=1;
  }
   else if (strcmp(order,"remove")==0)
    {
    cin >>deleted_array_number;
    x[200]=removing(x,deleted_array_number,n);
    for (j=0;j<n-1;j++)
     {
       cout << x[j] << " ";
     }
     cout <<endl; 
     n-=1;
    }
    
 }  
 return 0;
}