#include <bits/stdc++.h>
using namespace std;
#define dump(x) cout << #x << " = " << (x) << endl;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define FOREACH(x, a) for (auto &x : (a))
#define OUT(n) cout << n << endl
typedef long long ll;
// #include <atcoder/all>
// using namespace atcoder;

bool Deleted[1000009];

void eratstenes(ll num) {
  for(ll i=2;i*i<=num;i++) {
    if (Deleted[i]) continue;
    for(int j=i*2;j<=num;j+=i) {
      Deleted[j] = true;
    }
  }
}

int main() {
  ll N;cin>>N;
  for(int i=0;i<=N;i++) {
    Deleted[i] = false;
  }
  eratstenes(N);
  for(ll i=2;i<=N;i++) {
    if (!Deleted[i]) {
      OUT(i);
    }
  }
}

