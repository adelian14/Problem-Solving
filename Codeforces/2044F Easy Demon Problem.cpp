#include <bits/stdc++.h>
#define loop(n) for(int i = 1; i <= n; i++)
#define rloop(n) for(int i = n; i >= 1; i--)
#define loop0(n) for(int i = 0; i < n; i++)
#define rloop0(n) for(int i = n-1; i >= 0; i--)
#define int long long
#define all(x) x.begin(),x.end()
#define mx 200001
using namespace std;
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

void solve(set<int> &a, set<int> &b, bitset<mx> &k){
    for(auto x : a){
        for(auto y : b){
            if(x*y >= mx) break;
            k[x*y]=1;
        }
    }
}
void testcase(int tc) {
    int n,m,q,sum=0;
    cin >> n >> m >> q;
    vector<int> a(n), b(m);
    bitset<mx> k_pos(0),k_neg(0);
    set<int> ap,bp,an,bn;
    for(auto &x : a){
        cin >> x;
        sum+=x;
    }
    for(auto &x : a){
        int k = sum-x;
        if(abs(k) >= mx) continue;
        if(k < 0) an.insert(-k);
        else ap.insert(k);
    }
    sum = 0;
    for(auto &x : b){
        cin >> x;
        sum+=x;
    }
    for(auto &x : b){
        int k = sum-x;
        if(abs(k) >= mx) continue;
        if(k < 0) bn.insert(-k);
        else bp.insert(k);
    }
    solve(ap,bp,k_pos);
    solve(an,bn,k_pos);
    solve(ap,bn,k_neg);
    solve(an,bp,k_neg);
    loop(q){
        int x;
        cin >> x;
        if(x < 0){
            x=-x;
            if(k_neg[x]) cout << "YES\n";
            else cout << "NO\n";
        }
        else{
            if(k_pos[x]) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
signed main()
{
    fast();
    int tc=1;
    //cin >> tc;
    loop(tc) testcase(i);
    return 0;
}
