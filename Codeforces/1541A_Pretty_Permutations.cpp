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
        int n;
        cin >> n;
        if(n&1){
            cout << "3 1 2 ";
            for(int i = 4; i <= n; i+=2)
                cout << i+1 << " " << i << " ";
        }
        else{
            for(int i = 1; i <= n; i+=2)
                cout << i+1 << " " << i << " ";
        }
        cout << '\n';
    }
    return 0;
}
