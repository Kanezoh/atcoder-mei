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
  ll MASS = 1509;
  vector<vector<ll>> VEC(MASS, vector<ll>(MASS, 0));
  REP(i, N) {
    ll x,y;cin>>x>>y;
    x--;y--;
    VEC[x][y] += 1;
  }

  vector<vector<ll>> SUM(MASS+2, vector<ll>(MASS+2, 0));

  REP(i, MASS) {
    REP(j, MASS) {
      SUM[i+1][j+1] = VEC[i][j];
    }
  }
  // REP(i,MASS+2) {
  //   REP(j, MASS+2) {
  //     cout << SUM[i][j];
  //   }
  //   cout << endl;
  // }
  // return 0;
  REP(i, MASS) {
    REP(j, MASS) {
      if (j==0) continue;
      SUM[i+1][j+1] += SUM[i+1][j];
    }
  }
  REP(i, MASS) {
    if (i==0) continue;
    REP(j, MASS) {
      SUM[i+1][j+1] += SUM[i][j+1];
    }
  }


  ll Q;cin>>Q;
  REP(i, Q) {
    ll a,b,c,d;cin>>a>>b>>c>>d;
    OUT(SUM[c][d]+SUM[a-1][b-1]-SUM[a-1][d]-SUM[c][b-1]);
  }
}

