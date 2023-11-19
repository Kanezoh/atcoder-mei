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
  vector<ll> A;
  vector<ll> B;
  REP(i,N) {
    ll h;cin>>h;
    if (i%2) A.push_back(h);
    else B.push_back(h);
  }
  vector<ll> P;
  vector<ll> Q;

  for(ll bit=0;bit<(1 << A.size());++bit) {
    ll sum = 0;
    for(ll i=0; i<A.size();++i) {
      if (bit & (1 << i)) sum += A[i];
    }
    P.push_back(sum);
  }

  for(ll bit=0;bit<(1 << B.size());++bit) {
    ll sum = 0;
    for(ll i=0; i<B.size();++i) {
      if (bit & (1 << i)) sum += B[i];
    }
    Q.push_back(sum);
  }
  sort(Q.begin(), Q.end());
  // t +P[i] = K
  for(ll i=0;i<P.size();i++) {
    ll t = P[i];
    auto itr = lower_bound(Q.begin(), Q.end(), K-t);
    ll ans = distance(Q.begin(), itr);
    if (t+Q[ans]==K) {
      OUT("Yes");
      return 0;
    }
  }
  OUT("No");
}

