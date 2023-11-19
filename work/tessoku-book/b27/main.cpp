#include <bits/stdc++.h>
using namespace std;
#define dump(x) cout << #x << " = " << (x) << endl;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define FOREACH(x, a) for (auto &x : (a))
#define OUT(n) cout << n << endl
typedef long long ll;
// #include <atcoder/all>
// using namespace atcoder;

ll GCD(ll A, ll B) {
  while (A!=0 && B!=0) {
    // 常にA>=Bとする
    if (B>A) swap(A,B);
    ll amari = A % B;
    A = amari;
  }
  return max(A,B);
}

int main() {
  ll A,B;cin>>A>>B;
  ll gcd = GCD(A,B);
  ll lcm = gcd * A/gcd * B/gcd;
  OUT(lcm);
}

