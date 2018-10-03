// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم //
//________________//
#include <bits/stdc++.h>
 
//  http://ideone.com/kxcEk8
using namespace std;
#define inf                  1e15
#define white                0
#define grey                 1
#define black                2
#define ll                   long long
#define ull                  unsigned long long
#define PI                   2.0*acos(0.0)   // acos(-1)
#define pii                  pair <int,int>
#define pll                  pair <ll,ll>
#define rep(i,x,y)           for(int i = x ; i < y ; i++)
#define ff                   first
#define ss                   second
#define X(i)                 x+fx[i]
#define Y(i)                 y+fy[i]
#define BOUNDRY(i,j)         ((i>=0 && i < r) && (j>= 0 && j< c))
#define WRITE                freopen("a.txt","w",stdout);
//***********************************************
#define MOD
#define ashraf
#ifdef ashraf
     #define so(args...) {cerr<<"so: "; dbg,args; cerr<<endl;}
#else
    #define so(args...)  // Just strip off all debug tokens
#endif
struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
int fx[] = {0,1,0,-1,1,-1,1,-1};
int fy[] = {1,0,-1,0,1,-1,-1,1};
#define NN 1000005
long long arr[NN], cul[NN];
int n , k;
long long fun(long long m){
    long long pos, temp = 0, prevPos = -1;
    for(int i = 0 ; i< k ; i++){
        pos = upper_bound(cul,cul+n,m+temp) - cul;
        pos--;
        if(pos == n-1) return 1;
        temp = cul[pos];
    }
    if(pos == n-1) return 1;
    else return -1;;
}
long long bisection(){
    long long b = 1, e = 1e15;
    int mmin = inf;
    while(b <= e){
        long long m = (b+e)/2;
       // cout << b << ' ' << e << ' ' <<  m << ' ' << fun(m) << endl;
        if(fun(m) > 0){
            e = m - 1;
            mmin = m;
        }
        else b = m+1;
    }
    return mmin;
}
int main()
{
     ios_base::sync_with_stdio(0); cin.tie(0);
 
//    cout << fun(6) << endl;
     int test , cs = 1;
     cin >> test ;
     while(test--){
         cin >> n >> k;
         for(int i = 0 ; i <  n ; i++){
             cin >> arr[i];
         }
         cul[0] = arr[0];
         for(int i = 1 ; i< n ; i++){
             cul[i] = cul[i-1] + arr[i];
         }
         long long res = bisection();
         printf("Case %d: %lld\n", cs++ , res);
     }
 
}
 
