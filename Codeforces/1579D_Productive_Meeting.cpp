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
        priority_queue<pair<int,int>> p;
        vector<pair<int,int>> v;
        loop(n){
            cin >> x;
            if(!x) continue;
            p.push({x,i});
        }
        while(p.size() >= 2){
            auto p1 = p.top();
            p.pop();
            auto p2 = p.top();
            p.pop();
            v.push_back({p1.second,p2.second});
            p1.first--;
            p2.first--;
            if(p1.first) p.push(p1);
            if(p2.first) p.push(p2);
        }
        cout << v.size() << '\n';
        for(auto u : v) cout << u.first << ' ' << u.second << '\n';
    }
    return 0;
}
