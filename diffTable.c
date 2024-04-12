/*
Derivative of tabulated functions using forward difference formula
x: 1    1.1     1.2     1.3
y: 1    1.21    1.44    1.69 
Find f'(1)
*/

#include<stdio.h>
#include<math.h>

#define n 4

int main()
{
    float x[n] = {1, 1.1, 1.2, 1.3};
    float y[n] = {1, 1.21, 1.44, 1.69};
    float h = x[1] - x[0];
    int i;
    for(i = 1; i < n; i++)
    {
        y[i] = y[i + 1] - y[i];
    }
    return 0;
}