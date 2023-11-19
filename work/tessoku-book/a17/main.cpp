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
  REP(i,N-1) cin>>A[i];
  vector<ll> B(N-2);
  REP(i,N-2) cin>>B[i];

  // 部屋Nに辿り着くための最短手数
  vector<ll> dp(N);
  dp[0] = 0;
  dp[1] = A[0];

  for(ll i=2;i<N;i++) {
    ll x = dp[i-1] + A[i-1];
    ll y = dp[i-2]+B[i-2];
    dp[i] = min(x,y);
  }
  vector<ll> ans;
  ll cur = N-1;
  while(true) {
    ans.push_back(cur);
    if (cur==0) break;
    ll x = dp[cur-1] + A[cur-1];
    ll y = dp[cur-2] + B[cur-2];
    if (x>y) {
      cur -=2;
    } else {
      cur -=1;
    }
  }
  reverse(ans.begin(), ans.end());
  OUT(ans.size());
  REP(i, ans.size()) {
    cout << ans[i]+1 << " \n"[i==ans.size()-1];
  }
}

