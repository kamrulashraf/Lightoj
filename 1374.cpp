#include <bits/stdc++.h>
using namespace std;
#define NN 1000005
int a[NN];
int mark[NN];
int main()
{
     int test , cs = 1;
     scanf("%d",&test);
     while(test--){
        int n ;
        scanf("%d",&n);
        memset(mark,0,sizeof mark);
        for(int i = 0 ; i< n ; i++)
            scanf("%d",&a[i]);
        for(int i = 0 ; i< n ; i++){
            mark[a[i]]++;
        }
 
        bool flag = 0;
        int tt = n-1;
        for(int i = 0 ; i< n ; i++){
            // cout << a[i] << ' ' << mark[a[i]] << ' ' << mark[tt-a[i]] << endl;
            if(mark[a[i]] == 2 && mark[tt-a[i]] == 0){
                continue;
            }
            else if(mark[a[i]] == 1 && mark[tt-a[i]] == 1){
                continue;
            }
            else{
                flag = 1;
            }
        }
 
        if(flag) printf("Case %d: no\n",cs++);
        else printf("Case %d: yes\n",cs++);
     }
     return 0;
}
