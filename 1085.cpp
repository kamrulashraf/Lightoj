#include <bits/stdc++.h>
using namespace std;
#define NN 100005
#define ff first
#define ss second
#define pii pair < int , int >
#define inf 1e9
long long mmax, a[NN], tree[NN];
long long mod = 1000000007;
 
void update(long long in , long long val){
    while(in <= mmax){
        tree[in] = (tree[in]+val)%mod;
        tree[in] += mod;
        tree[in] %= mod;
        in += in & -in;
    }
}
 
int query(long long in){
    long long sum = 0;
    while(in){
        sum =  (sum + tree[in])%mod;
        sum += mod;
        sum %= mod;
        in -= in & -in;
    }
    return sum;
}
 
bool cmp(pii a , pii b){
    return a.second < b.second;
}
int main()
{
    int test , cs = 1;
    cin >> test;
    while(test--){
       int n;
       mmax = 0;
       memset(tree,0,sizeof tree);
       scanf("%d",&n);
       vector < pii > v;
       v.push_back({-inf,0});
       for(int i = 1 ; i<=n ; i++){
            scanf("%lld", &a[i]);
            v.push_back({a[i],i});
       }
 
       sort(v.begin() , v.end());
       int prev = -inf;
       for(int i = 1 ; i<= n ; i++){
           // cout << v[i].ff << '*' << v[i-1].ff << endl;
           if(v[i].first != prev){
               prev = v[i].first;
               v[i].first = i+1;
           }
           else{
                prev = v[i].first;
                v[i].first = v[i-1].first;
            }
       }
 
       sort(v.begin() , v.end() , cmp);
 
       for(int i = 1 ; i<= n ; i++)
           a[i] = v[i].first;
       
       mmax = 0;
       for(int i = 1 ; i<= n ; i++)
             mmax = max(mmax , a[i]);
   
 
       long long res = 0;
       for(int i = 1 ; i<= n ; i++){
             long long numberOfway = query(a[i]-1)+1;
             // cout  << i << '*' <<  a[i] << ' ' << numberOfway <<  endl;
             res = (res+numberOfway)%mod;
             update(a[i], numberOfway);
       }
       printf("Case %d: %lld\n",cs++ ,res );
       v.clear();
    }
}
