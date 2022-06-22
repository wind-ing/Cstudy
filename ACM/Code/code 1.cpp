#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;
    while(cin>>n && n!=0)
    {
        int c(0);
        while(~ n & 1)
        {
            c++;
            n >>= 1;
        }
        cout << pow(2, c)<<endl;
    }

    return 0;
}