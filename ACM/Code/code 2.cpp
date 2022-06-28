/*
sort排序
*/
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n, s(0);
    cin >> n;
    int a[100];
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(a, a+n);
    for(int j=0; j<n; j=j+2)
        s += a[j+1] - a[j];
    cout << s;
    return 0;
}
