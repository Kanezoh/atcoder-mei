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

vector<pair<char,int>> renchoAsshuku(string s) {
  int n = s.size();
  vector<pair<char,int>> ret;
  for(int l=0;l<n;l++) {
    int r = l+1;
    int i = 0;
    while(r<n&&s[l]==s[r]) r++;
    ret.push_back({s[l], r-l});
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  constexpr char endl = '\n';

  // input
  int n; cin >> n;
  string s;cin>>s;

  auto ret = renchoAsshuku(s);
  map<char,int> mp;
  REP(i, ret.size()) {
    auto p = ret[i];
    mp[p.first] = max(mp[p.first], p.second);
  }
  REP(i, mp.size()) {
    mp[i];
  }
  

  // output
  cout << ans << endl;
}

