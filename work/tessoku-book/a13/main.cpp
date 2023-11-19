#include <bits/stdc++.h>
using namespace std;
#define dump(x) cout << #x << " = " << (x) << endl;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define OUT(n) cout << n << endl
typedef long long ll;
// #include <atcoder/all>
// using namespace atcoder;

int main() {
  ll N,K;cin>>N>>K;
  vector<ll> A(N);
  REP(i, N) cin>>A[i];
  // R[i]
  vector<ll> R(N);
  ll ans = 0;
  for(ll i=0;i<N;i++) {
    if (i==0) R[i] = 0;
    else R[i] = R[i-1];
    while(A[R[i]+1]-A[i]<=K && R[i]+1<N) {
      R[i]++;
    }
    ans += R[i]-i;
  }
  OUT(ans);
}

