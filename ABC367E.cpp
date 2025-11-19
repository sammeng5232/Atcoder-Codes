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
typedef map<int, int> mii;

int n, a[200010], x[200010][70];
ll k;

int f(int s) {
  for (int j = 0; j <= 60; j++)
    if ((k >> j) & 1)
      s = x[s][j];
  return s;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> x[i][0];
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int j = 1; j <= 60; j++)
    for (int i = 1; i <= n; i++)
      x[i][j] = x[x[i][j - 1]][j - 1];
  for (int i = 1; i < n; i++)
    cout << a[f(i)] << " ";
  cout << a[f(n)] << "\n";
  return 0;
}
