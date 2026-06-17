#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


const ll MOD = 1e9 + 7;
const ll INF = 9223372036854775807;
#define FAST_EXECUTION
#ifdef FAST_EXECUTION
#pragma GCC optimize("O3")
#endif

void Main() {
    ll n, m; cin >> n >> m;
    vector<ll> in(n);
    vector<vector<ll>> g(n);
    for(ll i = 0;i < m;i++) {
        ll a, b;cin >> a >> b;a--, b--;
        g[a].push_back(b);
        in[b]++;
    }
    queue<ll> q;
    vector<ll> topo;
    for(ll i = 0;i < n;i++) if(in[i] == 0) q.push(i);
    while(!q.empty()) {
        ll curr = q.front();q.pop();
        topo.push_back(curr);
        for(auto x : g[curr]) {
            in[x]--;
            if(in[x] == 0) {
                q.push(x);
            }
        }
    }
    vector<ll> dp(n);
    dp[0] = 1;
    for(auto x : topo) {
        for(auto v : g[x]) {
            dp[v] = (dp[x] + dp[v]) % MOD;
        }
    }

    cout << dp[n - 1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--) {
        Main();
    }
    return 0;
}