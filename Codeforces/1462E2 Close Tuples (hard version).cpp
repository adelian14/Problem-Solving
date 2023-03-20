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
long long mod=1e9+7;
const long long MAXN=2e5;
long long fact[MAXN+5];
long long fast_power(long long n, long long p){
    long long ans=1;
    while(p){
        if(p&1) ans=(ans*n)%mod;
        n=(n*n)%mod;
        p/=2;
    }
    return ans;
}
void factdp(){
    fact[0]=1;
    for(int i = 1; i <= MAXN; i++) fact[i]=(i*fact[i-1])%mod;
}
long long inv(long long n) {return fast_power(n,mod-2);}
long long add(long long a, long long b) {return (a%mod+b%mod)%mod;}
long long sub(long long a, long long b) {return (a%mod-b%mod+mod)%mod;}
long long mul(long long a, long long b) {return (a%mod*b%mod)%mod;}
long long divide(long long a, long long b) {return (a%mod*inv(b))%mod;}
long long npr(long long n, long long r) {return divide(fact[n],fact[n-r]);}
long long ncr(long long n, long long r) {return divide(npr(n,r),fact[r]);}
int main()
{
    fast();
    factdp();
    int tc = 1;
    cin >> tc;
    while(tc--){
        long long n,sum=0,x,m,k;
        cin >> n >> m >> k;
        int a[n];
        loop0(n) cin >> a[i];
        sort(a,a+n);
        int j = 0;
        for(int i = 0; i < n; i++){
            while(a[j]-a[i] <= k){
                j++;
                if(j==n) break;
            }
            j--;
            x=j-i;
            if(x < m-1) continue;
            sum=add(sum,ncr(x,m-1));
        }
        cout << sum << '\n';
    }
    return 0;
}
