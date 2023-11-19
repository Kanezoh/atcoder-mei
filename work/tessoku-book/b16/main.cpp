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

  // 足場iに辿り着くための最小コスト
  vector<ll> dp(N);
  // 最初の足場を0とする
  dp[0] = 0;
  // 1に辿りつく方法は一通りのみ
  dp[1] = abs(H[1]-H[0]);

  for(ll i=2;i<N;i++) {
    dp[i] = min(dp[i-1] + abs(H[i]-H[i-1]), dp[i-2] + abs(H[i]-H[i-2]));
  }
  OUT(dp[N-1]);
}

