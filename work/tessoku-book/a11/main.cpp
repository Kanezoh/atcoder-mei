#include <bits/stdc++.h>
using namespace std;
#define dump(x) cout << #x << " = " << (x) << endl;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define ITOC(n) (char)'0' + n
#define KETAUNE(keta, num) setw(keta) << setfill('0') << num
#define SORTVEC(vec) sort(vec.begin(), vec.end())
#define RSORTVEC(vec) sort(vec.rbegin(), vec.rend())
#define REVERSEVEC(vec) reverse(vec.begin(), vec.end())
#define FOREACH(x, a) for (auto &x : (a))
#define OUT(n) cout << n << endl
#define SISHAGONYU(X, base) round(X / (double)base) * base
#define KIRISUTE(X, base) X / base *base
typedef long long ll;
// #include <atcoder/all>
// using namespace atcoder;

int main() {
  ll N,X;cin>>N>>X;
  vector<ll> A(N);
  REP(i, N) cin>>A[i];
  ll L = 0, R = N;
  while(L<R) {
    ll m = (L+R) / 2;
    if (A[m] == X) {
      return 0;
    } else if (A[m] < X) {
      L = m+1;
    } else {
      R = m-1;
    }
  }
}


