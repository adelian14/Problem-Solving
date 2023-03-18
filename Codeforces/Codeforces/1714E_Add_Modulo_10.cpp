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
        int n,x;
        cin >> n;
        int a[n][10];
        loop0(n){
            cin >> x;
            for(int j = 0; j < 9; j++) a[i][j]=0;
            for(int j = 0; j < 9; j++){
                if(x%10==0 || x%10==5){
                    a[i][x%10]=x+1;
                    x+=(x%10);
                    continue;
                }
                a[i][x%10]=(x/10)%2+1;
                x+=(x%10);
            }
        }
        for(int j = 0; j < 9; j++){
            x=1;
            if(!a[0][j]) continue;
            for(int i = 1; i < n; i++){
                if(a[i][j]!=a[i-1][j]) break;
                x++;
            }
            if(x==n) break;
        }
        if(x==n) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
