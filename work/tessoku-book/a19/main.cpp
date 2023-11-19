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
  ll N,W;cin>>N>>W;
  vector<ll> w(N);
  vector<ll> v(N);
  REP(i, N) {
    cin>>w[i];
    cin>>v[i];
  }
  // dp[i][w] i番目までの品物を、重さがw以下まで選んだ時の価値の最大値
  vector<vector<ll>> dp(N+1, vector<ll>(W+1, 0));
  for(ll i=1;i<=N;i++) {
    for(ll j=0;j<=W;j++) {
      dp[i][j] = dp[i-1][j];
      if (j-w[i-1]>=0 && j-w[i-1]<=W) {
        dp[i][j] = max(dp[i][j], dp[i-1][j-w[i-1]]+v[i-1]);
      }
    }
  }
  OUT(dp[N][W]);
}

