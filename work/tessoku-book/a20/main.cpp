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
  string S,T;
  cin>>S>>T;
  // dp[i][j] マスi,jに到達するまでに通る赤い辺の最大値
  vector<vector<ll>> dp(2001, vector<ll>(2001));
  dp[0][0] = 0;
  auto s = S.size();
  auto t = T.size();
  for (ll i=0;i<=s;i++) {
    for (ll j=0;j<=t;j++) {
      if (i>=1&&j>=1&&S[i-1] == T[j-1]) {
        dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]+1);
      } else if (i>=1&&j>=1) {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      } else if (i>=1) {
        dp[i][j] = dp[i-1][j];
      } else if (j>=1) {
        dp[i][j] = dp[i][j-1];
      }
      }
  }
  OUT(dp[s][t]);
}

