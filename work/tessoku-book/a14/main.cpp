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
  vector<ll> A(N), B(N), C(N), D(N);
  REP(i, N) cin>>A[i];
  REP(i, N) cin>>B[i];
  REP(i, N) cin>>C[i];
  REP(i, N) cin>>D[i];

  vector<ll> P;
  vector<ll> Q;

  REP(i, N) {
    REP(j, N) {
      P.push_back(A[i]+B[j]);
    }
  }
  REP(i, N) {
    REP(j, N) {
      Q.push_back(C[i]+D[j]);
    }
  }

  // sort(P.begin(), P.end());
  sort(Q.begin(), Q.end());
  bool ans = false;

  // P[i] - K = Q[] となる数字が存在するか
  for(ll i=0;i<N*N;i++) {
    ll t = P[i];
    ll L=0, R=N*N;
    while (L<=R) {
      ll m = (L+R) / 2;
      if (Q[m]+t==K) {
        ans = true;
        break;
      } else if (Q[m]+t>K) {
        R = m-1;
      } else {
        L = m+1;
      }
    }
  }

  if(ans) {
    OUT("Yes");
  } else {
    OUT("No");
  }
}

