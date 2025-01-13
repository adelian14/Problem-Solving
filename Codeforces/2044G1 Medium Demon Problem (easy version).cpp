#include <bits/stdc++.h>
#define loop(n) for(int i = 1; i <= n; i++)
#define rloop(n) for(int i = n; i >= 1; i--)
#define loop0(n) for(int i = 0; i < n; i++)
#define rloop0(n) for(int i = n-1; i >= 0; i--)
#define int long long
#define all(x) x.begin(),x.end()
using namespace std;
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
void testcase(int tc) {
    int n;
    cin >> n;
    vector<int> a(n+1),dis(n+1),in(n+1),start;
    loop(n){
        int x;
        cin >> x;
        a[i]=x;
        in[x]++;
    }
    loop(n){
        if(in[i]==0) start.push_back(i);
    }
    while(!start.empty()){
        int p = start.back();
        start.pop_back();
        int node = a[p];
        dis[node] = max(dis[node],dis[p]+1);
        in[node]--;
        if(in[node]==0) start.push_back(node);
    }
    cout << *max_element(all(dis))+2 << '\n';
}
signed main()
{
    fast();
    int tc=1;
    cin >> tc;
    loop(tc) testcase(i);
    return 0;
}
