#include <bits/stdc++.h>
using namespace std;
#define dump(x) cout << #x << " = " << (x) << endl;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define FOREACH(x, a) for (auto &x : (a))
#define OUT(n) cout << n << endl
typedef long long ll;
// #include <atcoder/all>
// using namespace atcoder;

double calc(double x) {
  return x*x*x+x;
}

int main() {
  ll N;cin>>N;
  double L=-1, R=100;
  while(R-L>1e-3) {
    double m = L+ (R-L)/2;
    double ans = calc(m);
    if (ans >= N) {
      R = m;
    } else {
      L=m;
    }
  }
  OUT(L);
  OUT(R);
}

