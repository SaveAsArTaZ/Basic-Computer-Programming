#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    unsigned int t;
    short int i,d4, d1, d2, d3, A_equal_numbs = 0, E_equal_numbs = 0, A_max_score = 0, E_max_score = 0;
    char E[20]="ehsan wins";
    char A[20]="arshia wins";
    char T[20]="tie";
    cin >> t;
    char answer_t[1000][20];
    for ( i = 0; i < t; i++)
    {
        cin >> d1 >> d2 >> d3 >> d4;
        if (d1 == d2)
            A_equal_numbs = 2 * d1;
        if (d3 == d4)
            E_equal_numbs = 2 * d3;
        if (d1 + d2 == 7)
        {
            if (d1 == 1)
                A_max_score = 1;
            else if (d1 == 6)
                A_max_score = 1;
        }
        if (d4 + d3 == 7)
        {
            if (d3 == 1)
                E_max_score == 1;
            else if (d3 == 6)
                E_max_score = 1;
        }
        if (A_max_score > 0)
        {
            if (E_max_score > 0)
                strcpy(answer_t[i],T); //arshia and ehsan have max score are equal
            if (E_max_score == 0)
               strcpy(answer_t[i],A);//just arshia have max numbers
        }
        else if (E_max_score > 0)
        {
            if (A_max_score == 0)
                strcpy(answer_t[i],E);//just ehsan have max number
        }
        else if (A_equal_numbs > 0) //arshia has equal numbs
        {
            if (E_equal_numbs > 0) //ehsan has equal numbs
            {
                if (E_equal_numbs > A_equal_numbs)
                    strcpy(answer_t[i], E); // sum of numbs of ehsan bigger than sum of numbs of arshia
                        else if (E_equal_numbs < A_equal_numbs)
                            strcpy(answer_t[i], A); // sum of numbs of arshia bigger than sum of numbs of ehsan
                        else if (E_equal_numbs == A_equal_numbs)
                            strcpy(answer_t[i], T); // numbs of arshia equal numbs of ehsan
            }
            if (E_equal_numbs == 0)
                strcpy(answer_t[i],A); //just arshia has equal numbs
        }
        else if (E_equal_numbs > 0)
        {
            if (A_equal_numbs == 0)
                strcpy(answer_t[i], E); //just ehsan has equal numbs
        }
        else if ((d1 + d2) > (d3 + d4))
           strcpy(answer_t[i],A); //arshia has bigger score than ehsan(both have not equal numbs or max score)
        else if ((d1 + d2) < (d3 + d4))
           strcpy(answer_t[i],E); //ehsan has bigger score than arshia(both have not equal numbs or max score)
        else if ((d1 + d2) == (d3 + d4))
           strcpy(answer_t[i],T); //ehsan and arshia have equal score (both have  not equal numbs or max score)
        A_equal_numbs = 0, E_equal_numbs = 0, A_max_score = 0, E_max_score = 0;
    }
    for (int i=0;i<t;i++)cout <<answer_t[i]<<endl;
    return 0;
}