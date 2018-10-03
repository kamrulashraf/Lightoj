#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int main()
{
    int test;
    int n,p,w, caseno = 0 , result , sum , i;
    cin >> test;
    while(test--){
            int arr[35];
            memset(arr , 35 , 35 );
            cin >> n >> p >> w ;
            for(i = 0; i< n ; i++){
                cin >> arr[i];
            }
 
            for(sum = 0 , i = 0 ; i < p ; i++){
                sum = sum + arr[i];
                if(sum > w)
                {
                  result = i;
                  break;
                }
                else result = i + 1;
            }
        cout << "Case" << ' ' << ++caseno << ':' << ' ' << result << endl;
    }
}
