#include <bits/stdc++.h>
using namespace std;
#define dump(x) cout << #x << " = " << (x) << endl;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define ITOC(n) (char)'0' + n
#define KETAUNE(keta, num) setw(keta) << setfill('0') << num
#define FOREACH(x, a) for (auto &x : (a))
#define OUT(n) cout << n << endl
#define SISHAGONYU(X, base) round(X / (double)base) * base
#define KIRISUTE(X, base) X / base *base
typedef long long ll;
// #include <atcoder/all>
// using namespace atcoder;

int main() {
  ll N;cin>>N;
  vector<ll> A(N);
  REP(i,N)cin>>A[i];
  ll Q;cin>>Q;
  sort(A.begin(), A.end());
  
  REP(i, Q) {
    ll x;cin>>x;
    auto itr = lower_bound(A.begin(), A.end(), x);
    ll ans = distance(A.begin(), itr);
    OUT(ans);
  }
}

