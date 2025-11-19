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

int n, q, l, r, x, y;
ll a[200010], b[200010], psa[200010], psb[200010];

ll randomize(ll l) {
  l = ((l >> 16) ^ l - 2023) * 19999999;
  l = ((l >> 16) ^ l - 2023) * 19999999;
  l = ((l >> 16) ^ l - 2023) * 19999999;
  l = ((l >> 16) ^ l - 2023) * 19999999;
  return l;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = randomize(a[i]);
    psa[i] = psa[i - 1] + a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    b[i] = randomize(b[i]);
    psb[i] = psb[i - 1] + b[i];
  }
  for (int i = 1; i <= q; i++) {
    cin >> l >> r >> x >> y;
    cout << ((psa[r] - psa[l - 1] == psb[y] - psb[x - 1]) ? "Yes\n" : "No\n");
  }
  return 0;
}
