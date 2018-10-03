#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int i, a[12], test,t;
    cin >> test;
    for(t= 1 ; t<= test ; t++)
    {
        for(i = 0 ; i<3 ; i++) cin >> a[i];
        sort(a,a+3);
        if(a[0]*a[0] + a[1]*a[1] == a[2]*a[2]) printf("Case %d: yes\n", t);
        else printf("Case %d: no\n", t);
    }
}
 
