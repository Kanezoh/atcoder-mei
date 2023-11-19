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
  vector<ll> A(N-1);
  vector<ll> B(N-2);
  REP(i, N-1) {
    cin>>A[i];
  }
  REP(i, N-2) {
    cin>>B[i];
  }

  // 部屋番号iに辿りつく最短移動時間
  vector<ll> dp(N);
  dp[0] = 0;
  for(ll i=1;i<N;i++) {
    if (i==1) {
      dp[i] = dp[i-1] + A[i-1];
    } else {
      dp[i] = min(dp[i-1] + A[i-1], dp[i-2] + B[i-2]);
    }
  }
  OUT(dp[N-1]);
}

