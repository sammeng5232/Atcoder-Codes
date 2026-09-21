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

string s;
ll c, a[100][200010], siz[100];

int main() {
  cin >> s;
  int l = s.size();
  for (int i = 0; i < l; i++)
    a[(int)s[i]][++siz[(int)s[i]]] = i;
  for (int i = 65; i < 91; i++) {
    for (int j = 2; j <= siz[i]; j++)
      c += (j - 1) * (siz[i] + 1 - j) * (a[i][j] - a[i][j - 1]);
    c -= siz[i] * (siz[i] - 1) / 2;
  }
  cout << c << "\n";
  return 0;
}