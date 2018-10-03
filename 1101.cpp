#include <bits/stdc++.h>
using namespace  std;
 
#define N 100005
#define inf 2e9
#define rep(i,x,y)  for(int i = x ; i< y ; i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
#define ff first
#define ss second
#define pii pair < int , int>
#define ll long long
#define ull unsigned ll
#define MP make_pair
#define PB push_back
#define sca(a) scanf("%d",&a)
#define scaa(a,b) scanf("%d%d",&a,&b)
#define scaaa(a,b,c) scanf("%d%d%d",&a,&b,&c)
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};
 
int llog[N], par[N], cost[N][22], vis[N], level[N];
int table[N][22]  , n;
vector <  pair < int , pii > > v;
map < int , vector < pii > > adj;
void dfs(int u){
 
 
     vis[u] = 1;
     for(int i = 0 ; i< adj[u].size() ; i++){
         pii ch = adj[u][i];
         if(vis[ch.ss] == 0){
             level[ch.ss] = level[u]+1;
             table[ch.ss][0] = u;
             cost[ch.ss][0] = ch.ff;
             dfs(ch.ss);
         }
     }
 
}
 
 
int find(int a){
    if(a==par[a]) return a;
    return par[a] = find(par[a]);
}
 
 
void precal(int n){
    for(int i = 2 ; i<= n ; i++)
        llog[i] = llog[i/2]+1;
    for(int len=1 ; (1<<len) <=n ; len++){
        for(int i = 0 ; i<=n ; i++){
            cost[i][len] = -inf;
        }
    }
 
    for(int len = 1 ; (1<<len) <= n; len++){
         for(int i = 0 ; i<=n ; i++){
                if(table[i][len-1] != -1){
 
                    cost[i][len] = max(cost[i][len-1],cost[table[i][len-1]][len-1]);
                    table[i][len] = table[table[i][len-1]][len-1];
                }
                else{
                    table[i][len] = -1;
                    cost[i][len] = -inf;
                }
                if(table[i][len] == -1) cost[i][len] = -inf;
         }
    }
 
}
 
 
int lca(int u , int v){
     if(level[u] < level[v]){
        swap(u,v);
     }
 
     int diff;
     int res = -inf;
     while(diff = level[u]-level[v]){
 
         int k = llog[diff];
//         cout <<  k << '#' << ' ' << diff << endl;
         res = max(cost[u][k],res);
         u = table[u][k];
     }
 
     if(u == v){
         return res;
     }
 
     for(int i = 20 ; i>=0 ; i--){
        if(table[u][i] == table[v][i]) continue;
        res = max(res,cost[u][i]);
        res = max(res,cost[v][i]);
        u = table[u][i];
        v = table[v][i];
 
     }
 
//     cout << u << v << endl;
 
     res = max(cost[u][0],res);
     res = max(cost[v][0],res);
     return res;
}
 
int main()
{
    int test , cs = 1;
    sca(test);
    while(test--){
         int m;
         scaa(n,m);
         memset(table,-1,sizeof table);
         memset(level,0,sizeof level);
         memset(vis,0,sizeof vis);
         adj.clear();
         v.clear();
         F(i,n+1) par[i] = i;
 
 
         F(i,m){
            int a , b , c;
            scaaa(a,b,c);
            v.push_back(MP(c,MP(a,b)));
         }
         sort(v.begin() , v.end());
 
 
         int sz = v.size();
         int cnt = 0;
 
         for(int i = 0 ; i< sz ; i++){
 
             int a =  v[i].ss.ff;
             int b = v[i].ss.ss;
             int c = v[i].ff;
 
             int tempa = find(a);
             int tempb = find(b);
             if(tempa != tempb){
                adj[a].push_back(MP(c,b));
                adj[b].push_back(MP(c,a));
                par[tempa] = tempb;
                cnt++;
             }
         }
//         n = cnt;
         dfs(1);
         precal(n);
 
 
//         for(int i = 0 ; i< 4 ; i++){
//            F(j,n+1){
//               cout << cost[j][i] << ' ';
//            }
//            cout << endl;
//         }
         int q;
         sca(q);
 
         printf("Case %d:\n",cs++);
         while(q--){
             int a , b;
             scaa(a,b);
             int res = lca(a,b);
             printf("%d\n",res);
         }
 
    }
    return 0;
}
