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
const int maxn=1e6;
int dp[maxn+1][10];
int gdp[maxn+1];
long long f(long long n){
    long long p=1;
    while(n){
        if(n%10) p*=(n%10);
        n/=10;
    }
    return p;
}
long long g(long long n){
    if(n < 10) return n;
    return g(f(n));
}
int main()
{
    fast();
    loop(maxn) gdp[i] = g(i);
    for(int i = 1; i <= maxn; i++){
        for(int j = 1; j <= 9; j++){
            dp[i][j]=dp[i-1][j];
            dp[i][j]+=(gdp[i]==j);
        }
    }
    int tc = 1;
    //cin >> tc;
    while(tc--){
        int q,l,r,x;
        cin >> q;
        loop(q){
            cin >> l >> r >> x;
            cout << dp[r][x]-dp[l-1][x] << '\n';
        }
    }
    return 0;
}
