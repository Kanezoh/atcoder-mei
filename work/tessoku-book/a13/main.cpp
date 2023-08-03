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
  ll N,K;cin>>N>>K;
  vector<ll> A(N);
  vector<ll> R(N);
  REP(i,N) cin>>A[i];

  REP(i, N-1) {
    if (i==0) R[i] = 0;
    else R[i] = R[i-1];

    while(R[i] < N-1 && A[R[i]+1]-A[i] <= K) {
      R[i] += 1;
    }
  }
  ll ans = 0;
  REP(i, N-1) {
    ans += (R[i]-i);
  }
  OUT(ans);
}

