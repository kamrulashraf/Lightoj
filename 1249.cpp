#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
int main()
{
    int test , cs =  1;
    scanf("%d",&test);
    getchar();
    while(test--){
         int n;
         cin >> n;
         std::vector< pair < int , string > > v;
         for(int i = 0 ; i< n ; i++){
             string s ;
             int a,  b,  c;
             cin >> s >> a >> b >> c;
             a = (a*b*c);
             v.push_back({a,s});
         }
         sort(v.begin() , v.end());
         bool flag = 0;
         if(n == 1) flag = 1;
         else{
            if(v[0].ff == v[n-1].ff){
              flag = 1;
            }
         }
         if(flag) printf("Case %d: no thief\n",cs++);
         else{
            printf("Case %d: ",cs++);
            cout << v[n-1].ss << " took chocolate from " << v[0].ss << endl;
         }
         v.clear();
    }
    return 0;
}
