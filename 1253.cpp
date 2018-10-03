//  Misère Nim is exactly like the standard Nim game,
//  except for one critical difference. If the size of every pile is ,
//  then we need to treat it as a special case where we count the number
//  of piles. If the count is even, then the first player will win;
//  if the count is odd, then the first player will lose.
 
//  If the size of every pile is not
//     , then you can use XOR sum to determine who will win the game.
#include <bits/stdc++.h>
using namespace std;
#define NN 205
int main()
{
    int test , cs = 1;
    scanf("%d",&test);
    while(test--){
        int n;
        scanf("%d",&n);
        long long res = 0, counter = 0;
        for(int i = 0 ; i< n ; i++){
            long long a ;
            scanf("%lld", &a);
            if(a>1) counter++;
            res ^= a;
        }
       if( (res && counter) || (!res && !counter))
                 printf("Case %d: Alice\n",cs++);
        else printf("Case %d: Bob\n",cs++);
    }
}
