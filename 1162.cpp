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
 
map < int , vector < pii > > adj;
int vis[N] ;
int level[N], mmin[N][22] , mmax[N][22] , table[N][22];
int llog[N];
 
void dfs(int u){
     vis[u] = 1;
     F(i,adj[u].size()){
        pii v = adj[u][i];
        if(vis[v.ss]==0){
             level[v.ss] = level[u]+1;
             mmin[v.ss][0] = v.ff;
             mmax[v.ss][0] = v.ff;
             table[v.ss][0] = u;
             dfs(v.ss);
        }
     }
}
 
void precal(int n){
     for(int i = 2 ; i<= n ; i++) llog[i] = llog[i/2]+1;
 
     for(int len = 1 ; (1<<len) <= n ; len++){
         for(int i = 0 ; i<= n ; i++){
             if(table[i][len-1] != -1){
 
                 mmin[i][len] = min(mmin[i][len-1],mmin[table[i][len-1]][len-1]);
                 mmax[i][len] = max(mmax[i][len-1],mmax[table[i][len-1]][len-1]);
                 table[i][len] = table[table[i][len-1]][len-1];
             }
             else{
                 table[i][len] = -1;
             }
 
             if(table[i][len] == -1){
                mmin[i][len] = inf;
                mmax[i][len] = -inf;
             }
         }
     }
}
 
 
pii lca(int u , int v){
   int maxret = -inf , minret = inf;
   if(level[u] < level[v]) swap(u,v);
 
   int diff = 0;
   while(diff = level[u] - level[v]){
      int k = llog[diff];
      maxret = max(maxret,mmax[u][k]);
      minret = min(minret,mmin[u][k]);
      u = table[u][k];
   }
   if(u == v) return MP(maxret , minret);
 
   for(int i = 20 ; i >= 0 ; i--){
     if(table[u][i] == table[v][i]) continue;
     maxret = max(maxret,mmax[u][i]);
     minret = min(minret,mmin[u][i]);
     maxret = max(maxret,mmax[v][i]);
     minret = min(minret,mmin[v][i]);
     u = table[u][i];
     v = table[v][i];
   }
   maxret = max(maxret,mmax[u][0]);
   minret = min(minret,mmin[u][0]);
   maxret = max(maxret,mmax[v][0]);
   minret = min(minret,mmin[v][0]);
 
   return MP(maxret,minret);
}
 
int main()
{
    int test , cs = 1;
    sca(test);
    while(test--){
         int n ;
 
         sca(n);
         memset(vis,0,sizeof vis);
         memset(level,0,sizeof level);
         memset(table,-1,sizeof table);
         adj.clear();
         F(i,n-1){
             int a , b, c;
             scaaa(a,b,c);
             adj[a].PB(MP(c,b));
             adj[b].PB(MP(c,a));
         }
         dfs(1);
         precal(n);
         int q;
         sca(q);
         printf("Case %d:\n",cs++);
         while(q--){
            int a , b;
            scaa(a,b);
            pii res = lca(a,b);
            printf("%d %d\n",res.ss , res.ff);
         }
    }
}
