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
const int maxn=1e5;
vector<int> g[maxn+5];
bool vis[maxn+5];
int cost[maxn+5];
int dfs(int v, int mn=1e9){
    vis[v]=true;
    mn=min(mn,cost[v]);
    for(int u : g[v]){
        if(vis[u]) continue;
        mn=min(mn,dfs(u,mn));
    }
    return mn;
}
int main()
{
    fast();
    int tc = 1;
    //cin >> tc;
    while(tc--){
        int n,m,x,y;
        long long sum=0;
        cin >> n >> m;
        loop(n) cin >> cost[i];
        loop(m){
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        loop(n){
            if(vis[i]) continue;
            sum+=dfs(i);
        }
        cout << sum;
    }
    return 0;
}
