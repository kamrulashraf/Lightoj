#include <bits/stdc++.h>
using namespace std;
    vector < int > zAlgorihm(string s){
          vector< int > z(s.size());
          int l=0, r=0,len=s.size();
 
          for(int i = 1 ; i< len ; i++){
                if(i <= r) z[i] = min(r-i+1 , z[i-l]);
 
                while( i < len && s[z[i]] == s[i+z[i]])
                    z[i]++;
 
                if( i+z[i]-1 > r){
                    l = i;
                    r = i+z[i]-1;
                }
          }
          return z;
    }
int main()
{
   int test , cs = 1;
   string s;
   scanf("%d",&test);
   while(test--){
        cin >> s;
        string temp = s;
        int res = 2*s.size();
//        cout << res << endl;
        int save = s.size();
        reverse(temp.begin(),temp.end());
        temp += '#';
        temp += s;
      //  cout << s << endl;
        vector <int>  v;
        v = zAlgorihm(temp);
       // cout << temp << endl;
        int sz = temp.size();
        for(int i = save ; i< temp.size() ; i++){
              if(sz-v[i] ==i){
                res -= v[i];
                break;
              }
        }
        printf("Case %d: %d\n",cs++,res);
        v.clear();
   }
 
}#include <bits/stdc++.h>
 
//  http://ideone.com/kxcEk8
using namespace std;
#define inf                  1e7
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
 
 
//******************************************************
inline void take(int &x) {scanf("%d",&x);}
inline void take(int &x ,int &y)  {scanf("%d %d",&x, &y);}
template < class T> inline T Set(T N, T pos){ return N = N | (1<< pos);}
template < class T> inline bool Check(T N , T pos){ return (bool) (N & (1<<pos));}
template < class T> inline T Reset(T N , T pos) { return N = N & ~(1 << pos); }
template < class T> inline T gcd(T a, T b) {
  while (a > 0 && b > 0)
    a > b ? a%=b : b%=a;
  return a + b;
}
template < class T> inline T lcm(T a, T b) {return (a*b)/gcd(a,b);}
template < class T> T big(T b , T p , T mod){
    if(p == 0) return 1;
    if(!(p&1)){
        T x = big(b,p/2,mod);
        return (x*x)%mod;
    }
    else return (b*big(b,p-1,mod))%mod;
}
 
template < class T> T POW(T b , T p){
    if(p == 0) return 1;
    if(!(p&1)){
        T x = POW(b,p/2);
        return (x*x);
    }
    else return (b*POW(b,p-1));
}
 
int fx[] = {0,1,0,-1,1,-1,1,-1};
int fy[] = {1,0,-1,0,1,-1,-1,1};
int m;
int pre[1000005];
void kmpPreCal(char *sub){
   int i=0,j=-1;
   pre[0]=-1;
   int len = strlen(sub);
   while(i<len){
       while(j>=0 && sub[i] != sub[j])
           j = pre[j];
       i++ , j++;
       pre[i] = j;
   }
}
 
int kmp(char *s , char *sub){
    int i=0,j=0,save=0;
    int len = strlen(s);
    while(i<len){
       while(j>=0 && s[i] != sub[j])
           j = pre[j];
       i++ , j++;
//       cout << i << ' ' << j << endl;
    }
   return j;
}
int main()
{
  char s[1000005] ,sub[1000005];
   int test , cs = 1;
   scanf("%d",&test);
   getchar();
   while(test--){
       gets(s);
       int len = strlen(s);
       sub[len] = '\0';
       for(int i = 0 ; s[i] ; i++)
           sub[i] = s[--len];
        kmpPreCal(sub);
        int res = kmp(s,sub);
        len = strlen(s);
        printf("Case %d: %d\n",cs++ ,2*len- res);
   }
}
