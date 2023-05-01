#include <iostream>
#include <cmath>
using namespace std;
int convert(long long unsigned a,int b,int c)
{
    long long unsigned int base_10;

    

    if (b == 10)
        base_10 = a;
    else //convert base b to base 10
    {
        int r, i = 0;
        long long int s = 0;
        do
        {
            r = a % 10;
            s += r * pow(b, i);
            a /= 10;
            ++i;
        } while (a != 0);
        base_10 = s;
    }

    //convert base 10 to base c
    long long unsigned int base_c = 0;
    int i = 1;
    while (base_10 != 0)
    {
        base_c += (base_10 % c) * i;
        base_10 /= c;
        i *= 10;
    }
    return base_c;
}    
int reverse_number(unsigned long long d)   
{
    unsigned long long reversed;
    int m;
    while (d > 0) //reverse base_c
    {
        m = d % 10;
        reversed = (reversed * 10) + m;
        d = d / 10;
    }
    return reversed;
}   
int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    int m;
    unsigned long long int d,reversed=0,y;
    
    d=convert(a,b,c);
    reversed= reverse_number(d);
    y=d;

    if (reversed==y)//compare reverse and base_c
    {
       cout <<"YES";   
    }
    else
    {
       cout <<"NO";
    }
    return 0;
}