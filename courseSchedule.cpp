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
    queue<ll> q;
    for(ll i = 0;i < n;i++) {
        if(in[i]) continue;
        q.push(i);
    }
    vector<ll> ans;
    while(!q.empty()) {
        ll curr = q.front();q.pop();
        ans.push_back(curr);
        for(auto x : g[curr]) {
            in[x]--;
            if(in[x])
            if(in[x]) continue;
            q.push(x);
        }
    }
    if(ans.size() != n) cout << "IMPOSSIBLE\n";
    else {
        for(auto x : ans) cout << x + 1 << " ";
        cout << endl;
    }
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