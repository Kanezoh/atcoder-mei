#include <bits/stdc++.h>
using namespace std;
#define dump(x) cout << #x << " = " << (x) << endl;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define FOREACH(x, a) for (auto &x : (a))
#define OUT(n) cout << n << endl
typedef long long ll;
// #include <atcoder/all>
// using namespace atcoder;

ll Power(ll a, ll b, ll m) {
  ll p = a, ans = 1;
  for(int i=0;i<30;i++) {
    int wari = (1<<i);
    if ((b/wari) %2==1) {
      ans = (ans*p)%m;
    }
    p = (p*p)%m;
  }
  return ans;
}

int main() {
  ll a,b;cin>>a>>b;
  OUT(Power(a,b,1000000007));
  OUT(((42/1)%2));
  OUT(((42/2)%2));
  OUT(((42/4)%2));
  OUT(((42/8)%2));
}

