#include <bits/stdc++.h>
using namespace std;
#define NN 100005
int tree[NN] , a[NN], b[NN], n;
void update(int in , int val){
    while( in <= n){
        tree[in] += val;
        in += in & -in;
    }
}
int query(int in){
    int sum = 0;
    while(in){
        sum += tree[in];
        in -= in & -in;
    }
    return sum;
}
 
int binarySearch(int key){
    int b = 1 , e = n;
    while(b <= e){
        int m = (b+e)/2;
        if(query(m) < key){
            b = m+1;
        }
        else e = m-1;
    }
    return b;
}
int main()
{
      int test , cs = 1;
      scanf("%d", &test);
      while(test--){
        scanf("%d",&n);
        for(int i = 1 ; i<= n ; i++){
            scanf("%d", &a[i]);
            b[i] = i;
            update(i,1);
        }
        reverse(b+1,b+n+1);
        reverse(a+1,a+n+1);
       
        int res;
        for(int i = 1 ; i<= n ; i++){
            int temp = a[i]+1;
            int pos = binarySearch(temp);
            res = b[pos];
            update(pos,-1);
        }
        printf("Case %d: %d\n",cs++ , res);
      }
}
