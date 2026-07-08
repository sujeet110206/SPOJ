#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define sp ' '
#define pb push_back
#define inf 1e18
#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> primes;
void generatePrimes(int limit) {
  vector<bool> sieve(limit + 1, true);
  sieve[0] = sieve[1] = false;
  for (int i = 2; i * i <= limit; i++) {
    if (sieve[i]) {
      for (int j = i * i; j <= limit; j += i)
        sieve[j] = false;
    }
  }
  for (int i = 2; i <= limit; i++) {
    if (sieve[i])
      primes.pb(i);
  }
}
void solve() {
  ll l, r;
  cin >> l >> r;
  if (l < 2)
    l = 2;
  vector<int> dummy(r - l + 1, 1);
  for (auto p : primes) {
    int start = (l / p) * p;
    if (start < l)
      start += p;
    for (int i = max(start, p * p); i <= r; i += p)
      dummy[i - l] = 0;
  }
  for (int i = l; i <= r; i++) {
    if (dummy[i - l] == 1)
      cout << i << " ";
  }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int maxLimit = sqrt(1e9) + 1;
  generatePrimes(maxLimit);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
