//
// Created by chesn on 18/03/2022.
//

#include "functions.h"

int fibonacci_rec(int n)
{
    int res;
    if (n == 0)
    {
        res = 0;
    }
    else
    {
        if ( n == 1 )
        {
            res = 1;
        }
        else
        {
            res = fibonacci_rec(-- n) + fibonacci_rec(n - 1);
        }
    }
    return res ;
}