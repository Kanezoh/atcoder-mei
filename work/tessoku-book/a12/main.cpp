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
  ll L=0, R=1000000000;
  while(R-L>1) {
    ll m = L + (R-L) / 2;
    ll num = 0;
    REP(i, N) {
      num += m/A[i];
    }
    if (num < K) {
      L = m;
    }
    if (num >= K) {
      R = m;
    }
  }
  OUT(R);
}

