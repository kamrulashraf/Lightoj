clude <bits/stdc++.h>
using namespace std;
#define NN 205
#define inf 1e7
int node , s , t ,edge, minEdge;
int parent[NN];
map < int , vector <int>  > adjList;
int resGraph[NN][NN] , f;
map < string , int > hit;
 
    void argument(int v , int mmin){
       if(v == s){
         f = mmin;
         return;
       } else if(parent[v] != -1){
          // cout << v << ' ';
          argument(parent[v], min(mmin , resGraph[parent[v]][v]));
          resGraph[parent[v]][v] -= f;
          resGraph[v][parent[v]] += f;
       }
 
    }
    int edmondKarps(){
        int maxFlow = 0;
        while(1){
            f = 0;
            bool vis[NN];
            stack < int > q;
            q.push(s);
            memset(vis,0,sizeof vis);
            memset(parent , - 1 , sizeof(parent));
            while(!q.empty()){
               int u = q.top();
               q.pop();
               if(u == t) break;
               for(int i = 0 ; i< adjList[u].size() ; i++){
                  int v = adjList[u][i];
                  if(v == 11 || parent[v] == 11){
                    // cout << u << ' ' <<  v << ' ' << resGraph[u][v] << endl;
                  }
                  if(resGraph[u][v] > 0 && !vis[v]){
                      vis[v] = 1;
                      q.push(v);
                      parent[v] = u;
                  }
               }
            }
            argument(t , inf);
            if(f == 0) break; // can not sent more flow in this graph
            maxFlow += f;
        }
      return maxFlow;
    }
int main()
{
    int test , cs = 1;
    scanf("%d",&test);
    string tShirt = "XXL.XL.L.M.S.XS." , temp;
    for(int i = 0 ,counter = 0 ; i < tShirt.size() ; i++){
        if(tShirt[i] == '.'){
            counter++;
            hit[temp] = counter;
            temp.clear();
        }
        else temp += tShirt[i];
    }
    temp.clear();
 
    while(test--){
         int noOfShirt , edge, target = 200;
         scanf("%d%d",&noOfShirt , &edge);
         for(int i = 1 ; i<= 6 ; i++){
            adjList[i].push_back(target);
            adjList[target].push_back(i);
            resGraph[i][target] += noOfShirt;
         }
 
         for(int i = 0 ; i< edge ; i++){
            string a, b;
            cin >> a >> b;
            int aa = hit[a];
            int bb = hit[b];
            adjList[0].push_back(i+7);
            adjList[i+7].push_back(0);
            resGraph[0][i+7] += 1;
            adjList[i+7].push_back(aa);
            adjList[aa].push_back(i+1);
            adjList[i+7].push_back(bb);
            adjList[bb].push_back(i+7);
            resGraph[i+7][aa] += 1;
            resGraph[i+7][bb] += 1;
         }
         s = 0 ; t = target;
         int res = edmondKarps();
         // cout << res << endl;
         if(res >= edge)
               printf("Case %d: YES\n",cs++ );
         else printf("Case %d: NO\n", cs++);
         adjList.clear();
         memset(resGraph,0,sizeof resGraph);
    }
}
