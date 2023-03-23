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
long long p[101][101][11];
vector<int> f[101][101];
int main()
{
    fast();
    int tc = 1;
    //cin >> tc;
    while(tc--){
        int n,q,c,x,y,s,x1,x2,y1,y2,t,sum;
        cin >> n >> q >> c;
        loop(n){
            cin >> x >> y >> s;
            f[x][y].push_back(s);
        }
        for(int i = 1; i <= 100; i++){
            for(int j = 1; j <= 100; j++){
                for(int k = 0; k <= c; k++){
                    for(int w = 0; w < f[i][j].size(); w++){
                        p[i][j][k]+=(f[i][j][w]+k)%(c+1);
                    }
                    p[i][j][k]+=p[i-1][j][k]+p[i][j-1][k]-p[i-1][j-1][k];
                }
            }
        }
        loop(q){
            cin >> t >> x1 >> y1 >> x2 >> y2;
            t%=(c+1);
            cout << p[x2][y2][t] - p[x1-1][y2][t] - p[x2][y1-1][t] + p[x1-1][y1-1][t] << '\n';
        }
    }
    return 0;
}
