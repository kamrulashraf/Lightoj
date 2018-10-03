#include <bits/stdc++.h>
using namespace std;
#define NN 150005+10
int tree[NN];
int a[NN];
    int sum(int indx)
    {
        int sum = 0;
        while (indx){
            sum += tree[indx];
            indx -= indx & -indx;
        }
        return sum;
    }
 
    void update(int n, int indx, int val){
        while (indx <= n){
            tree[indx] += val;
            indx += indx & (-indx);
        }
    }
 
int binarySearch(int key){
    int b = 1 , e = NN -2;
    while(b <= e){
         int m = (b+e)/2;
         long long val = sum(m);
         if(val < key){
            b = m+1;
         }
         else e = m-1;
    }
    return e;
}
int main()
{
     int test , cs  = 1;
     scanf("%d",&test);
     while(test--){
         printf("Case %d:\n",cs++);
         memset(tree,0,sizeof tree);
         int counter = 0;
         int n, q;
         scanf("%d %d",&n,&q);
         for(int i = 0 ; i< n ; i++){
            scanf("%d",&a[i]);
            update(NN-2 , ++counter , 1);
         }
 
 
         while(q--){
            getchar();
            char ch = getchar();
            if(ch == 'c'){
                int temp ;
                scanf("%d",&temp);
                if(temp > counter){
                  printf("none\n");
                  continue;
                }
                int pos = binarySearch(temp);
                update(NN-2,pos+1,-1);
                counter--;
                printf("%d\n",a[pos]);
            }
            else{
                scanf("%d", &a[n++]);
                counter++;
                update(NN-2,n,1);
            }
         }
     }
}
