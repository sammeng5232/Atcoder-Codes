#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vd;
typedef vector<int> vi;
typedef stack<ll> sd;
typedef stack<int> si;
typedef queue<ll> qd;
typedef queue<int> qi;
typedef map<int, int> mii;

ll n, m[200010];
string s;

int main() {
  cin >> n >> s;
  m[0] = s[0] - '0';
  for (int i = 1; i < n; i++)
    m[i] = m[i - 1] + (s[i] - '0') * (i + 1);
  for (int i = n - 1; i > 0; i--)
    m[i - 1] += m[i] / 10, m[i] %= 10;
  for (int i = 0; i < n; i++)
    cout << m[i];
  return 0;
}