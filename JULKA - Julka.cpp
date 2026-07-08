#include<bits/stdc++.h>
using namespace std;

string add(string num1, string num2) {
  string ans = "";
  int i = (int) num1.length() - 1;
  int j = (int) num2.length() - 1;
  int carry = 0;
  while (i >= 0 || j >= 0 || carry) {
    int sum = carry;
    if (i >= 0) sum += num1[i--] - '0';
    if (j >= 0) sum += num2[j--] - '0';
    ans += to_string(sum % 10);
    carry = sum / 10;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
string dividedByTwo(string num) {
  string ans = "";
  int rem = 0;
  for (char c : num) {
    int cur = rem * 10 + (c - '0');
    ans += to_string(cur / 2);
    rem = cur % 2;
  }
  size_t firstNonZero = ans.find_first_not_of('0');
  if (firstNonZero == string::npos) return "0";
  return ans.substr(firstNonZero);
}
string subtraction(string num1, string num2) {
  string ans = "";
  int i = (int) num1.length() - 1;
  int j = (int) num2.length() - 1;
  int borrow = 0;
  while (i >= 0) {
    int sub = (num1[i] - '0') - borrow;
    if (j >= 0) sub -= num2[j--] - '0';
    if (sub < 0) {
      sub += 10;
      borrow = 1;
    } else {
      borrow = 0;
    }
    ans += to_string(sub);
    i--;
  }
  reverse(ans.begin(), ans.end());
  size_t firstNonZero = ans.find_first_not_of('0');
  if (firstNonZero == string::npos) return "0";
  return ans.substr(firstNonZero);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 10;
  while (t--) {
    string tot, diff;
    cin >> tot >> diff;
    string klaudia = dividedByTwo(add(tot, diff));
    string natalia = subtraction(klaudia, diff);
    cout << klaudia << endl << natalia << endl;
  }
  return 0;
}
