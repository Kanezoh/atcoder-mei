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
  vector<ll> A(N);
  REP(i, N) cin>>A[i];
  ll Q;cin>>Q;
  vector<ll> ATARI(N+1);
  vector<ll> HAZURE(N+1);
  ATARI[0] = 0;
  HAZURE[0] = 0;
  REP(i, N) {
    if (A[i] == 1) {
      ATARI[i+1] = ATARI[i] +1;
      HAZURE[i+1] = HAZURE[i];
    } else {
      ATARI[i+1] = ATARI[i];
      HAZURE[i+1] = HAZURE[i]+1;
    }
  }
  REP(i, Q) {
    ll l,r;cin>>l>>r;
    ll atari = ATARI[r] - ATARI[l-1];
    ll hazure = HAZURE[r] - HAZURE[l-1];
    if (atari>hazure) {
      OUT("win");
    } else if (hazure>atari) {
      OUT("lose");
    } else {
      OUT("draw");
    }
  }
}

