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
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    vector<ll> in(n);
    for(ll i = 0;i < m;i++) {
        ll a, b;cin >> a >> b; a--, b--;
        g[a].push_back(b); in[b]++;
    }
    // for(auto x : in) cout << x << " ";
    // cout << endl;
    queue<ll> q;
    for(ll i = 0;i < n;i++) {
        if(in[i]) continue;
        q.push(i);
    }
    vector<ll> topo;
    while(!q.empty()) {
        ll curr = q.front();q.pop();
        topo.push_back(curr);
        for(auto x : g[curr]) {
            in[x]--;
            if(in[x]) continue;
            q.push(x);
        }
    }
    vector<ll>dist(n, LLONG_MIN);dist[0] = 0;
    vector<ll> par(n, -2); par[0] = -1;
    for(ll curr : topo) {
        if(dist[curr] == LLONG_MIN) continue;
        // cout << curr << " " << dist[curr] << endl;
        for(auto x : g[curr]) {
            if(dist[curr] + 1 > dist[x]) {
                dist[x] = dist[curr] + 1;
                par[x] = curr;
            }
        }
    }
    
    if(dist[n - 1] == LLONG_MIN) {
        cout << "IMPOSSIBLE" << endl;return;
    }
    ll node = n - 1;
    vector<ll> ans;
    while(node != -1) {
        ans.push_back(node);node = par[node];
    }
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for(auto x : ans) cout << x + 1 << " ";
    cout << endl;
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