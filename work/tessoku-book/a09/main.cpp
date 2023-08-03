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
  ll H,W,N;cin>>H>>W>>N;
  vector<vector<ll>> SUM(H+2, vector<ll>(W+2, 0));
  REP(i, N) {
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    SUM[a][b] += 1;
    SUM[c+1][b] -= 1;
    SUM[a][d+1] -= 1;
    SUM[c+1][d+1] += 1;
  }
  REP(i, H+2) {
    REP(j, W+2) {
      if (j==0) continue;
      SUM[i][j] += SUM[i][j-1];
    }
  }
  REP(i, H+2) {
    REP(j, W+2) {
      if (i==0) continue;
      SUM[i][j] += SUM[i-1][j];
    }
  }
  REP(i, H) {
    REP(j, W) {
      cout << SUM[i+1][j+1] << " \n"[j==W-1];
    }
  }

}

