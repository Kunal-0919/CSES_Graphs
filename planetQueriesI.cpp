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
    ll n, q;cin >> n >> q;
    vector<ll> v(n);
    for(ll i = 0;i < n;i++) cin >> v[i];
    // vector<vector<ll>> dp(n + 1, vector<ll> (32));
    ll dp[n + 1][32];
    memset(dp, 0, sizeof(dp));
    for(ll i = 0;i < n;i++) dp[i + 1][0] = v[i];

    for(ll j = 1;j < 32;j++) {
        for(ll i = 1;i <= n;i++) {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }
    // for(auto x : dp)  {
    //     for(auto y : x) cout << y << " ";
    //     cout << endl;
    // }
    while(q--) {
        ll node, k;cin >> node >> k;
        for(ll i = 0;i < 32;i++) {
            if(k & (1LL << i)) {
                node = dp[node][i];
            }
        }
        cout << node << "\n";
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