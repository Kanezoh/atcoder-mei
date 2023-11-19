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
  vector<ll> A(N);
  REP(i, N) cin>>A[i];

  // i番目までのカードを使った時にjを実現できるかどうか
  vector<vector<bool>> dp(N+1, vector<bool>(K+1, false));
  dp[0][0] = true;
  for(ll i=1;i<=N;i++) {
    for(ll j=0;j<=K;j++) {
      if (j-A[i-1]>=0 && j-A[i-1]<K) {
        dp[i][j] = dp[i-1][j-A[i-1]];
      }
      dp[i][j] = dp[i][j] || dp[i-1][j];
    }
  }

  if (dp[N][K]) {
    OUT("Yes");
  } else {
    OUT("No");
  }
}

