#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define sp ' '
#define pb push_back
#define inf 1e18
#define pii pair<int, int>
#define pll pair<ll, ll>

string makePalindrome(string s) {
  int n = s.length();
  for (int i = 0; i < n / 2; i++)
    s[n - i - 1] = s[i];
  return s;
}
void solve() {
  string s;
  cin >> s;
  string pal = makePalindrome(s);
  if (pal > s) {
    cout << pal << endl;
    return;
  }
  int n = s.length();
  int carry = 1;
  int mid = (n - 1) / 2;
  while (mid >= 0 && carry) {
    int digit = (s[mid] - '0') + carry;
    s[mid] = (digit % 10) + '0';
    carry = digit / 10;
    mid--;
  }
  if (carry) {
    cout << '1';
    for (int i = 0; i < n - 1; i++)
      cout << '0';
    cout << '1' << endl;
    return;
  }
  pal = makePalindrome(s);
  cout << pal << endl;
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
