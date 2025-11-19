#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<double> vd;
typedef vector<int> vi;
typedef stack<double> sd;
typedef stack<int> si;
typedef queue<double> qd;
typedef queue<int> qi;

int n, a, b, x[300010], l = 1e9, r = 0, mid, ans;

bool valid(int k) {
  ll c1 = 0, c2 = 0;
  for (int i = 0; i < n; i++) {
    if (x[i] < k)
      c1 += (k - x[i] + a - 1) / a;
    if (x[i] > k)
      c2 += (x[i] - k) / b;
  }
  return (c1 <= c2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    l = min(l, x[i]);
    r = max(r, x[i]);
  }
  while (l <= r) {
    mid = l + (r - l) / 2;
    if (valid(mid)) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  cout << ans << "\n";
  return 0;
}