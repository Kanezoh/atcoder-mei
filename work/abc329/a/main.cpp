#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
using namespace std;

int64_t solve(int n, const vector<int64_t>& a) {
    // ...
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  constexpr char endl = '\n';

  // input
  int n; cin >> n;
  vector<int64_t> a(n);
  REP (i, n) {
      cin >> a[i];
  }

  // solve
  auto ans = solve(n, a);

  // output
  cout << ans << endl;
}

