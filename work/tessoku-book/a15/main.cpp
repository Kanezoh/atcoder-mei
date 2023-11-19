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
  vector<ll> A(N);
  REP(i, N) cin>>A[i];
  auto B = A;
  sort(A.begin(), A.end());
  map<ll,ll> P;
  P[A[0]] = 1;
  for(ll i=1;i<N;i++) {
    if (A[i-1] == A[i]) P[A[i]] = P[A[i-1]];
    else P[A[i]] = P[A[i-1]] + 1;
  }
  REP(i, N) {
    cout << P[B[i]] << " \n"[i==N-1];
  }
}

