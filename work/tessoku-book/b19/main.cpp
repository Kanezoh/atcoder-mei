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
  ll N,K;cin>>N>>K;
  vector<ll> W(N);
  vector<ll> V(N);
  REP(i, N) {
    cin>>W[i];
    cin>>V[i];
  }
  // dp[i][j] i番目までの品物を選んだ時、価値がj以下の時の重さの最小値
  vector<vector<ll>> dp(N+1, vector<ll>(100001, 100000000000));
  dp[0][0] = 0;
  for(ll i=1;i<=N;i++) {
    for(ll j=0;j<=100000;j++) {
      if (j<V[i-1]) dp[i][j] = dp[i-1][j];
      else dp[i][j] = min(dp[i-1][j], dp[i-1][j-V[i-1]]+W[i-1]);
    }
  }
  ll ans = 0;
  REP(j, 100001) {
    if (dp[N][j] <= K) ans = j;
  }
  OUT(ans);
}

