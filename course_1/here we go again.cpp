#include <iostream>

using namespace std;
int main()
{   
    int n,i,min=0;
    int x[1000];
	cin >> n;
    for (i=0;i <=n-1 ;i++)
	{
		cin >> x [i];	
	}	
    for (i=0; i <=n-1;i++)
    {
     min = x[i];
	 for(int j=i+1; j <=n-1; j++)
	 {
	  if (x[j] < min )
	  {
	   min = x[j];
	   x[j]=x[i];
	   x[i]=min;	
	  }	
	 }	
	}
	for (i=0; i<=n-1;i++)
	{
	cout << x [i];
	if (i != n-1)
	cout << ", ";	
    }
	return 0;
}
