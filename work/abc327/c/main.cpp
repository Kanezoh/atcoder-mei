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

bool san_san(int i, int j, auto &v) {
  set<int> s;
  REP(k, 3) {
    int h = i+k;
    REP(l, 3) {
      int w = l+j;
      s.insert(v[h][w]);
    }
  }
  return s.size() == 9;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  constexpr char endl = '\n';

  // input
  vector<vector<int>> v(9, vector<int>(9));
  REP(i, 9) {
    REP(j, 9) {
      cin>>v[i][j];
    }
  }
  // 横チェック
  REP(i, 9) {
    set<int> s;
    REP(j, 9) {
      s.insert(v[i][j]);
    }
    if (s.size() != 9) {
      cout << "No" << endl;
      return 0;
    }
  }
  // 縦チェック
  REP(i, 9) {
    set<int> s;
    REP(j, 9) {
      s.insert(v[j][i]);
    }
    if (s.size() != 9) {
      cout << "No" << endl;
      return 0;
    }
  }

  // 3*3チェック
  if (!san_san(0,0,v) || !san_san(0,3,v) || !san_san(0,6,v)) {
    cout << "No" << endl;
    return 0;
  }
  if (!san_san(3,0,v) || !san_san(3,3,v) || !san_san(3,6,v)) {
    cout << "No" << endl;
    return 0;
  }
  if (!san_san(6,0,v) || !san_san(6,3,v) || !san_san(6,6,v)) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  return 0;
}

