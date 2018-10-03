#include <bits/stdc++.h>
using namespace std;
#define white    0
#define black    2
#define grey     1
#define N 10005
 
#define kamrul
#ifdef kamrul
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif
struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
 
map < int , vector <int> > g;
int vis[N], parent[N] , low[N] , num[N] ,counter,sss,same[N];
stack<int> s;
void scc(int u){
    vis[u] = grey;
    low[u] = num[u] = counter++;
    s.push(u);
    for(int i = 0 ; i< g[u].size() ; i++){
        int v = g[u][i];
        if(vis[v] == white){
            parent[v] = u;
            scc(v);
        }
        if(vis[v] == grey && parent[u] != v){
            low[u] = min(low[u],low[v]);
        }
    }
 
    if(low[u] == num[u]){
       sss++;
       while(1){
          int temp = s.top();
          vis[temp] = black;
          same[temp] = sss;
          s.pop();
          if(temp == u){
              break;
          }
       }
    }
}
int main()
{
  int test , cs = 1;
  cin >> test;
  while(test--){
         int node , edge;
         scanf("%d%d", &node , &edge);
         for(int i = 0 ; i< edge ; i++){
            int a, b;
            scanf("%d%d", &a , &b);
            g[a].push_back(b);
            g[b].push_back(a);
         }
         memset(vis,0,sizeof(vis));
         memset(parent,-1,sizeof(parent));
         counter = 0;
         sss = 0;
         for(int i = 0 ; i< node ; i++){
             if(!vis[i]){
                scc(i);
             }
         }
         memset(low,0,sizeof(low));
         counter = 0;
         for(int i = 0 ; i< node ; i++){
               int u = i;
               for(int j = 0 ; j < g[u].size() ; j++){
                    int v = g[u][j];
                    if( same[u] != same[v]){
                        low[same[u]]++;
                        low[same[v]]++;
                    }
               }
         }
         for(int i = 1 ; i<= node ; i++)
            if(low[i] == 2) counter++;
 
 
          printf("Case %d: %d\n",cs ++ , (counter+1)/2);
 
 
          g.clear();
          memset(low,0,sizeof(low));
          memset(num,0,sizeof(num));
          memset(same,0,sizeof(same));
  }
 
}
 
