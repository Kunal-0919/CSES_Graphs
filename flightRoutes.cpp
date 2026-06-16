#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
 
const ll MOD = 1e9 + 7;
const ll INF = 9223372036854775807;
#define FAST_EXECUTION
#ifdef FAST_EXECUTION
#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:247474112")
#endif
 
void Main() {
    ll n, m, k; cin >> n >> m >> k;
    vector<vector<pair<ll, ll>>> g(n);
    for(ll i = 0;i < m;i++) {
        ll a, b, c;cin >> a >> b >> c;
        a--, b--;
        g[a].push_back({b, c});
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, 0});
    vector<priority_queue<ll>> maxh(n); maxh[0].push(0);
    while(!q.empty()) {
        pair<ll, ll> top = q.top();q.pop();
        ll d = top.first, curr = top.second;
        if(!maxh[curr].empty() && maxh[curr].top() < d) continue;
        for(auto [x, w] : g[curr]) 
        {
            if(maxh[x].size() < k || w + d < maxh[x].top()) {
                maxh[x].push(w + d);
                while(maxh[x].size() > k) maxh[x].pop();
                q.push({w + d, x});
            }
        }
    }
    ll i = 0;
    vector<ll> ans(k);
    while(!maxh[n - 1].empty()) {
        ans[i++] = maxh[n-1].top();maxh[n - 1].pop();
    }
    reverse(ans.begin(), ans.end());
    for(auto x : ans) cout << x << " ";
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