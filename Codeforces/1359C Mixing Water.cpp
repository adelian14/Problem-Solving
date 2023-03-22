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
        long long c,h,t,k=2,k1,k2;
        cin >> h >> c >> t;
        if(2*t > c+h){
            k=(h-t)/(2*t-h-c);
            k1 = ((k*(h+c)+h)-((2*k+1)*t))*(2*k+3);
            k2 = (((k+1)*(h+c)+h)-((2*k+3)*t))*(2*k+1);
            if(abs(k1) > abs(k2)) k++;
            k=2*k+1;
        }
        cout << k << '\n';
    }
    return 0;
}
