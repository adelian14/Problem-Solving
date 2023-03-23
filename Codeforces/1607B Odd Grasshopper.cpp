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
        long long x,n,k,ans;
        cin >> x >> n;
        k=n/4;
        if(n%4==0) ans=0;
        else if(n%4==1) ans=(-k*4)-1;
        else if(n%4==2) ans=1;
        else if(n%4==3) ans=(k+1)*4;
        if(x&1) ans*=-1;
        cout << x+ans << '\n';
    }
    return 0;
}
