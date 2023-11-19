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
  REP(i,N) cin>>A[i];

  // 累積和
  vector<ll> S(N+1);
  S[0] = 0;
  REP(i, N) {
    S[i+1] += S[i] + A[i];
  }

  vector<ll> R(N+1);
  
  for(ll i=0;i<N;i++) {
    if (i==0) R[i] = 0;
    else R[i] = R[i-1];

    while (R[i] <= N && S[R[i]] - S[i] <= K) {
      R[i]++;
    }
  }

  ll ans = 0;
  REP(i, N) {
    ans += R[i]-i-1;
  }
  OUT(ans);
}

