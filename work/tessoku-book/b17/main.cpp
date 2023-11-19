#include <bits/stdc++.h>
using namespace std;
#define dump(x) cout << #x << " = " << (x) << endl;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define FOREACH(x, a) for (auto &x : (a))
#define OUT(n) cout << n << endl
typedef long long ll;
// #include <atcoder/all>
// using namespace atcoder;

int main() {
  ll N;cin>>N;
  vector<ll> H(N);
  REP(i, N) cin>>H[i];
  // 足場n(0<=n<N)にいる時の最短手数
  vector<ll> dp(N);
  dp[0] = 0;
  dp[1] = abs(H[1]-H[0]);
  for(ll i=2;i<N;i++) {
    dp[i] = min(dp[i-1] + abs(H[i] - H[i-1]), dp[i-2] + abs(H[i] - H[i-2]));
  }
  vector<ll> ans;
  ll cur = N-1;
  while(true) {
    ans.push_back(cur);
    if (cur == 0) break;
    ll x = dp[cur-1] + abs(H[cur]-H[cur-1]);
    if (dp[cur] == x) {
      cur -=1;
    } else {
      cur -=2;
    }
  }
  OUT(ans.size());
  reverse(ans.begin(), ans.end());
  REP(i, ans.size()) {
    cout << ans[i]+1 << " \n"[i==ans.size()-1];
  }
}

