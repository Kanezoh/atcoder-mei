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
  vector<ll> P,A;
  map<ll,ll> mp;
  REP(i,N) {
    ll p,a;cin>>p>>a;
    P.push_back(p);
    A.push_back(a);
  }
  // dp[l][r] l番目からr番目のブロックが残っている状態の得点の最大値
  vector<vector<ll>> dp(2009, vector<ll>(2009));
  dp[1][N] = 0;

  for(ll i=1;i<=N;i++) {
    for(ll j=1;j<=N;j++) {
    }
  }

  if ()
}

