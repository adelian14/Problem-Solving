#include <bits/stdc++.h>
#define loop(n) for(int i = 1; i <= n; i++)
#define rloop(n) for(int i = n; i >= 1; i--)
#define loop0(n) for(int i = 0; i < n; i++)
#define rloop0(n) for(int i = n-1; i >= 0; i--)
#define iloop(s,n,step) for(int i = s; i <= n; i+=step)
#define jloop(s,n,step) for(int j = s; j <= n; j+=step)
#define loopit(x) for(auto it = x.begin(); it!= x.end(); it++)
#define all(x) x.begin(),x.end()
using namespace std;
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
int dp[200009][18];
int main()
{
    fast();
    for(int i = 1; i <= 200000; i++){
        int j = 0,x = i;
        for(int j = 0; j < 18; j++){
            dp[i][j]=dp[i-1][j]+(x&1);
            x = x >> 1;
        }
    }
    int tc = 1;
    cin >> tc;
    while(tc--){
        int l,r,mn=2e5;
        cin >> l >> r;
        for(int i = 0; i < 18; i++){
            mn=min(r-l+1-(dp[r][i]-dp[l-1][i]),mn);
        }
        cout << mn << '\n';
    }
    return 0;
}
