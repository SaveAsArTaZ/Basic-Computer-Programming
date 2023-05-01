#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    unsigned long long int row;
    unsigned short int col;
    int i, j, repeat;
    int temp[10];
    cin >> row >> col;
    char A[row][col];
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            cin >> A[i][j];
        }
    }
    for (repeat = 0; repeat < row - 1; repeat++)
    {
        for (i = row - 1; i >= 0; i--)
        {
            for (j = col - 1; j >= 0; j--)
            {
                if (A[i][j] == '.')
                {
                    if (A[i - 1][j] == 'a')
                    {

                        A[i - 1][j] = '.';
                        A[i][j] = 'a';
                    }
                }
            }
        }
    }
    cout <<endl<<endl<<endl;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            cout << A[i][j];
        }
        cout << endl;
    }

    return 0;
}