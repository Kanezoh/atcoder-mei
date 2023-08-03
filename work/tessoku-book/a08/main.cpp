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
  ll H,W;cin>>H>>W;
  vector<vector<ll>> vec(H, vector<ll>(W));
  REP(i, H) {
    REP(j, W) {
      cin>>vec[i][j];
    }
  }

  vector<vector<ll>> sum(H+2, vector<ll>(W+2,0));
  REP(i, H) {
    REP(j, W) {
      sum[i+1][j+1] = vec[i][j];
    }
  }

  REP(i, H) {
    REP(j, W) {
      if (j==0) continue;
      sum[i+1][j+1] += sum[i+1][j];
    }
  }
  REP(i, H) {
    if (i==0) continue;
    REP(j, W) {
      sum[i+1][j+1] += sum[i][j+1];
    }
  }
  ll Q;cin>>Q;
  // REP(i, H+2) {
  //   REP(j, W+2) {
  //     cout << sum[i][j];
  //   }
  //   cout << endl;
  // }
  REP(i, Q) {
    ll a,b,c,d;cin>>a>>b>>c>>d;
    //a--;b--;c--;d--;
    OUT(sum[c][d]+sum[a-1][b-1]-sum[a-1][d]-sum[c][b-1]);
  }

}

