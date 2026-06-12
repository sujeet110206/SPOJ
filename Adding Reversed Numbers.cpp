#include<bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    string num1, num2;
    cin >> num1 >> num2;
    string ans = "";
    int i = 0;
    int j = 0;
    int carry = 0;
    while (i < (int)num1.length() || j < (int)num2.length() || carry) {
      int sum = carry;
      if (i < (int)num1.length()) sum += (num1[i++] - '0');
      if (j < (int)num2.length()) sum += (num2[j++] - '0');
      ans += to_string(sum % 10);
      carry = sum / 10;
    }
    int firstNonZero = ans.find_first_not_of('0');
    if (firstNonZero == string::npos) {
      cout << "0\n";
    }
    cout << ans.substr(firstNonZero) << "\n";
  }
  return 0;
}
