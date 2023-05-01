#include <iostream>
using namespace std;
int main()
{
    unsigned int n;
    int sum = 0, d = 0;
    int x[100];
    int k=0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        sum += x[i];
        if (x[i] > sum)
        {
        sum =x[i];//har yek az adad
        k+=x[i]; 
        }
    }
    if (k > sum )
    {
     sum = k;//sum kol adad   
    }
    for (int i = 0; i < n; i++)
    {
        d = x[i];
        for (int j = i + 1; j < n; j++)
        {
            if (d > sum)
            {
                sum = d;
            }
            d = d + x[j];
        }
    }
    if (sum < 0)
    {
        sum = 0;
    }
    cout << sum;
    return 0;
}