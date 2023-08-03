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

// printf("%.3lf", S);
// 小数で割ったあまり　fmod(1,1.0)
// 末尾3文字 str.substr(str.length() - 3)
// 円周率 M_PI
// 等差数列の和
// a1: 初項、n: 項数、d: 項差
// return n * (2 * a1 + (n - 1) * d) /2

int main() {
  ll N;cin>>N;
  vector<ll> vec(N);
  REP(i, N) cin>>vec[i];
  vector<ll> L(N);
  L[0] = vec[0];
  for(int i=1;i<N;i++) {
    L[i] = max(vec[i], L[i-1]);
  }
  vector<ll> R(N);
  R[N-1] = vec[N-1];
  for(int i=N-2;i>=0;i--) {
    R[i] = max(vec[i], R[i+1]);
  }

  ll Q;cin>>Q;
  REP(i, Q) {
    ll l,r;cin>>l>>r;
    l--;r--;
    ll ans = max(L[l-1], R[r+1]);
    OUT(ans);
  }
}

