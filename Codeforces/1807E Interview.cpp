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
        long long n,x;
        cin >> n;
        long long p[n+1]={0};
        loop(n){
            cin >> p[i];
            p[i]+=p[i-1];
        }
        int l = 1, r = n;
        while(l < r){
            int m = (l+r)/2;
            cout << "? " << m-l+1 << " ";
            for(int i = l; i <= m; i++){
                cout << i << " ";
            }
            cout << endl;
            cout.flush();
            cin >> x;
            if(x==p[m]-p[l-1]){
                l=m+1;
            }
            else{
                r=m;
            }
        }
        cout << "! " << l << endl;
        cout.flush();
    }
    return 0;
}
