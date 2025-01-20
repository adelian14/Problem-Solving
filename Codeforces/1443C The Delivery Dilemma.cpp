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
    vector<vector<int>> a(n,vector<int>(2));
    loop0(n) cin >> a[i][0];
    loop0(n) cin >> a[i][1];
    sort(all(a),greater<vector<int>>());
    int sum = 0, ans = 1e9;
    loop0(n){
        ans = min(ans,max(a[i][0],sum));
        sum+=a[i][1];
    }
    cout << min(ans,sum) << '\n';
}
signed main()
{
    fast();
    int tc=1;
    cin >> tc;
    loop(tc) testcase(i);
    return 0;
}
