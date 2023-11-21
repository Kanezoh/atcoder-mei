#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
using namespace std;
typedef long long ll;

int64_t solve(int n, const vector<int64_t>& a) {
    // ...
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  constexpr char endl = '\n';

  // input
  ll n,m; cin >> n>>m;
  vector<ll> v(n);
  REP(i,n) cin>>v[i];
  sort(ALL(v));

  ll ans = 0;
  for(int i=0;i<n;i++) {
    auto a = lower_bound(ALL(v), v[i]+m);
    ll index = distance(v.begin(), a);
    ans = max(ans, index-i);
  }
  cout << ans << endl;
}