#include<bits/stdc++.h>
using namespace std;

int fibo(int n)
{
    if(n<2)
        return n;
    return fibo(n-1) + fibo(n-2); 
}

int main()
{
    cout << fibo(5);
    return 0;
}