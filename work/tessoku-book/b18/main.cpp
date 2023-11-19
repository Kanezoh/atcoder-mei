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
  ll N,S;cin>>N>>S;
  vector<ll> A(N);
  REP(i, N) cin>>A[i];

  // i番目までのカードを選んでSになルカ
  vector<vector<bool>> dp(N+1, vector<bool>(S+1, false));
  dp[0][0] = true;

  for(ll i=1;i<=N;i++) {
    for (ll j=0;j<=S;j++) {
      if (j-A[i-1]>=0&&j-A[i-1]<=S) {
        dp[i][j] = dp[i][j] || dp[i-1][j-A[i-1]];
      }
      dp[i][j] = dp[i][j] || dp[i-1][j];
    }
  }
  if (!dp[N][S]) {
    OUT(-1);
    return 0;
  }

  vector<ll> ans;
  ll cur = S;
  for(ll i=N;i>=1;i--) {
    if (dp[i-1][cur]) {
      continue;
    }
    if (dp[i-1][cur-A[i-1]]) {
      ans.push_back(i);
      cur -= A[i-1];
    }
  }
  OUT(ans.size());
  reverse(ans.begin(), ans.end());
  REP(i, ans.size()) {
    cout << ans[i] << " \n"[i==ans.size()-1];
  }
}

