#include <bits/stdc++.h>
using namespace std;
#define dump(x) cout << #x << " = " << (x) << endl;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define FOREACH(x, a) for (auto &x : (a))
#define OUT(n) cout << n << endl
typedef long long ll;
// #include <atcoder/all>
// using namespace atcoder;

const int MAX = 10000000;
int M[MAX+1];

int fibonacci(ll n) {
  if (n==1) {
    return 1;
  } else if (n==2) {
    return 1;
  } else if (M[n] != -1) {
    return M[n];
  } else {
    M[n] = (fibonacci(n-1)+fibonacci(n-2))%1000000007;
    return M[n];
  }
}

int main() {
  ll N;cin>>N;
  for(int i=0;i<=MAX;i++) {
    M[i] = -1;
  }
  ll ans = fibonacci(N);
  OUT(ans);
}
