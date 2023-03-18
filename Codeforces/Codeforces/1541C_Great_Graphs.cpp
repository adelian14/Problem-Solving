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
int main()
{
    fast();
    int tc = 1;
    cin >> tc;
    while(tc--){
        long long n,sum1=0,sum2=0;
        cin >> n;
        long long a[n],p[n]={0};
        loop0(n) cin >> a[i];
        sort(a,a+n);
        for(int i = 1; i < n; i++){
            p[i]=p[i-1]+a[i];
            sum1+=a[i]-a[i-1];
            sum2+=a[i]*i-p[i-1];
        }
        cout << sum1-sum2 << '\n';
    }
    return 0;
}
