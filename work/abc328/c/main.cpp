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
  int n,q; cin >> n >> q;
  string s; cin>>s;

  // 累積和: S[i] i文字目までに同じ英子文字が隣り合う箇所がいくつあるか
  vector<int> S(n+1, 0);
  int len = s.size();
  for(int i=2;i<=len;i++) {
    if (s[i-2]==s[i-1]) S[i] = S[i-1]+1;
    else S[i] = S[i-1];
  }
  REP(i, q) {
    int l,r;cin>>l>>r;
    cout << S[r]-S[l] << endl;
  }
}
