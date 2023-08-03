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
  vector<vector<ll>> A(N, vector<ll>(N));
  REP(i, N) {
    REP(j, N) {
      char c;cin>>c;
      int h = c - '0';
      A[i][j] = h;
    }
  }

  ll prev = A[0][0];
  for(int i=1;i<N;i++) {
    ll h = A[0][i];
    A[0][i] = prev;
    prev = h;
  }
  for(int i=1;i<N;i++) {
    ll h = A[i][N-1];
    A[i][N-1] = prev;
    prev = h;
  }
  for(int i=N-1;i>=1;i--) {
    ll h = A[N-1][i-1];
    A[N-1][i-1] = prev;
    prev = h;
  }
  for(int i=N-1;i>=1;i--) {
    ll h = A[i-1][0];
    A[i-1][0] = prev;
    prev = h;
  }

  REP(i, N) {
    REP(j, N) {
      cout << A[i][j];
    }
    cout << endl;

  }
}

