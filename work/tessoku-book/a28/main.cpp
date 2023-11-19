#include <bits/stdc++.h>
using namespace std;
#define dump(x) cout << #x << " = " << (x) << endl;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define FOREACH(x, a) for (auto &x : (a))
#define OUT(n) cout << n << endl
typedef long long ll;
// #include <atcoder/all>
// using namespace atcoder;

int main() {
  ll N;cin>>N;
  ll ans = 0;
  REP(i, N) {
    char c;ll n;
    cin>>c>>n;
    if (c=='+') {
      ans += n;
    } else if (c=='-') {
      ans -= n;
    } else if (c=='*') {
      ans *= n;
    }
    ans %= 10000;
    if (ans<0) ans+=10000;
    OUT(ans);
  }
}

