#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define sp ' '
#define pb push_back
#define inf 1e18
#define pii pair<int, int>
#define pll pair<ll, ll>

void solve() {
  string s;
  cin >> s;
  stack<char> st;
  string res = "";
  for (auto ch : s) {
    if (isalpha(ch))
      res.push_back(ch);
    else if (ch == '(')
      st.push(ch);
    else if (ch == ')') {
      res.push_back(st.top());
      st.pop();
      st.pop();
    } else {
      st.push(ch);
    }
  }
  cout << res << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
