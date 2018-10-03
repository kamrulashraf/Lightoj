#include <bits/stdc++.h>
using namespace std;
#define NN 1429431+15
int tree[NN+5];
int sum(int indx){
     int sum = 0;
     while(indx){
        sum += tree[indx];
        indx -= indx&-indx;
     }
     return sum;
}
 
 
void update(int n , int indx , int val){
    while(indx <= n){
         tree[indx] += val;
         indx += indx&-indx;
    }
}
 
int binarySearch(int key){
      int b = 1 , e = NN ;
      while(b <= e){
         int m = (b+e)/2;
//       cout << b << ' ' << e << ' ' << ' ' << sum(m) << endl;
         if(sum(m) >= key){
            e = m-1;
         }
         else b  =m+1;
      }
      return b;
}
int main()
{
     int test , cs = 1;
 
     for(int i = 1 ; i<= NN-2  ; i++){
         update(NN,i,1);
     }
//   update(NN,2,-1);
//     cout << binarySearch(5) << endl;
 
     for(int i = 1 ; i<= 100000 ; i++){
         int counter = 0, temp;
         if(i == 1) temp = 2;
         else temp = i;
         temp = binarySearch(temp);
         for(int j = temp ; j<= 1429432 ; j+= temp){
            int pos = binarySearch(j-counter);
            counter++;
            update(NN , pos , -1);
         }
     }
     scanf("%d",&test);
     while(test--){
          int n;
          scanf("%d",&n);
          int pos = binarySearch(n);
 
          printf("Case %d: %d\n",cs++, pos);
     }
 
}

