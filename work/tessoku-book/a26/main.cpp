#include <bits/stdc++.h>
using namespace std;
#define dump(x) cout << #x << " = " << (x) << endl;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define FOREACH(x, a) for (auto &x : (a))
#define OUT(n) cout << n << endl
typedef long long ll;
// #include <atcoder/all>
// using namespace atcoder;

bool isPrime(ll num) {
  ll root = sqrt(num);
  for(ll i=2;i<=root;i++) {
    if (num%i==0) {
      return false;
    }
  }
  return true;
}

int main() {
  ll Q;cin>>Q;
  REP(i, Q) {
    ll x;cin>>x;
    if (isPrime(x)) {
      OUT("Yes");
    } else {
      OUT("No");
    }
  }
}

