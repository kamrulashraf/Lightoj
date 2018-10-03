#include <bits/stdc++.h>
using namespace std;
#define rep( i ,x , y) for(int i = x ; i< y ; i++)
#define ll long long
#define ul unsigned int
int save[55][55];
void ncr(int n){
    rep(i,0,n+1)
     rep(j,0,n+1){
       if(i == j || j== 0){
           save[i][j] = 1;
       }
       else save[i][j] = (ul) (save[i-1][j-1]+save[i-1][j]);
     }
}
 
struct MAT
{
   long long r,c;
   long long a[55][55];
   MAT(long long a,long long b){
    r = a;
    c = b;
   }
     void init(vector < ll > temp){
      for(long long i = 0 ; i<r*c ; i++){
        a[i/c][i%c] = temp[i];
      }
     }
     void print(){
          for(long long i = 0 ; i< r ; i++){
             for(long long j = 0; j < c ; j++){
               cout << a[i][j] << ' ';
             }
             cout << endl;
          }
     }
     MAT operator*(MAT b){
       MAT sum(r,c);
       vector<ll> temp(r*c);
       sum.init(temp);
       for(long long i = 0 ; i< r ; i++){   // row 1st mat
         for(long long j = 0 ; j< b.c ; j++){  // col 2nd mat
                   for(long long k=0; k<c ;k++){   // col 1st matss
                      sum.a[i][j] += (a[i][k]*b.a[k][j]);
                   }
                   sum.a[i][j] = (ul) sum.a[i][j];
         }
       }
       return sum;
 
     }
};
 
MAT pow(MAT b , long long p){
    if(p == 0 || p == 1)
      return b;
    if(p&1){
        return b*pow(b,p-1);
    }
    else{
        MAT temp = pow(b,p/2);
        return temp*temp;
    }
 
}
 
long long power(long long b, long long p){
     if(p == 0 || p == 1) return b;
     if(p&1) return b*power(b,p-1);
     else{
        long long x = power(b,p/2);
        return x*x;
     }
}
 
 
int main()
{
   int test , cs = 1;
   scanf("%d",&test);
   ncr(55);
   while(test--){
        long long n , k;
        scanf("%lld%lld",&n,&k);
        vector <ll> v;
        rep(i,0,k+2){
            if(i == 0) v.push_back(1);
            rep(j,0,i){
               v.push_back(0);
            }
            int t = 0;
            if(i == 0 || i == 1){
              rep(j,1,k+2){
                   v.push_back(save[k][t]);
                   t++;
              }
            }
            else{
              rep(j,i,k+2){
                   v.push_back(save[k-i+1][t]);
                   t++;
              }
            }
        }
 
//        for(int i = 0 ; i< v.size() ; i++){
//            if(i%(k+2) == 0) cout << endl;
//            cout << v[i] << ' ' ;
//        }
 
        MAT a(k+2,k+2);
        a.init(v);
        a = pow(a,n-1);
 
        ll res =  0;
        for(int i = 0 ; i< k+2 ; i++){
           res = (ul) (res+ a.a[0][i]);
        }
        res = (ul) res;
        printf("Case %d: %lld\n",cs++ , res);
 
        v.clear();
 
 
   }
}

