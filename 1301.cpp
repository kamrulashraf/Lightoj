#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pii pair < int ,int >
 
 
bool comp(pii a , pii b){
    if(a.ff == b.ff){
        if(a.ss > b.ss) return true;
        else return false;
    }
    if(a.ff < b.ff) return true;
    else return false;
}
int main()
{
 
     int test , cs = 1;
     scanf("%d",&test);
     while(test--){
        int n;
        scanf("%d",&n);
        std::vector< pii > v;
        for(int i = 0 ; i< n ; i++){
             int a , b;
             scanf("%d%d",&a,&b);
             v.push_back({a,1});
             v.push_back({b,-1});
        }
        sort(v.begin(),v.end(),comp);
        int res = 0, temp = 0;
        for(int i=0 ; i< v.size() ; i++){
              temp += v[i].ss;
              // cout << v[i].ff << ' ' << v[i].ss << ' ' << temp <<  endl;
              res = max(temp,res);
        }
        printf("Case %d: %d\n",cs++ , res);
     }
     return 0;
}
