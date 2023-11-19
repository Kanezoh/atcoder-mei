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
  const int INF = 1<<29;
  string S,T;
  cin>>S>>T;
  // dp[i+1][j+1] Sのi文字目までを変換してTのj文字目までへと変換するための最小操作回数
  vector<vector<ll>> dp(2009, vector<ll>(2009));
  // 変更操作
  // S[i] == T[j] then dp[i+1][j+1] = dp[i][j]
  // S[i] != T[j] then dp[i+1][j+1] = dp[i][j]+1
  // 削除操作
  // dp[i+1][j+1] = dp[i][j+1]+1
  // 挿入操作
  // dp[i+1][j+1] = dp[i+1][j]+1

  for(ll i=0;i<2009;i++) {
    for(ll j=0;j<2009;j++) {
      dp[i][j] = INF;
    }
  }
  dp[0][0] = 0;

  for(ll i=-1;i<(int)S.size();i++) {
    for(ll j=-1;j<(int)T.size();j++) {
      if (i == -1 && j == -1) continue;
      if (i>=0 && j>=0) {
        if (S[i] == T[j]) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
        else dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+1);
      }
      if (i>=0) {
        dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j+1]+1);
      }
      if (j>=0) {
        dp[i+1][j+1] = min(dp[i+1][j+1], dp[i+1][j]+1);
      }
    }
  }
  OUT(dp[S.size()][T.size()]);
}

