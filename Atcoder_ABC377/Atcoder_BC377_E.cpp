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

ll n, m;
struct P {
  ll l, r;
} p[200010];
multiset<ll> endpt;
ll cnt;
ll currp = 1;

bool cmp(P x, P y) { return x.l < y.l; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].l >> p[i].r;
    endpt.insert(p[i].r);
  }
  sort(p + 1, p + n + 1, cmp);
  for (int i = 1; i <= m; i++) {
    cnt += ((endpt.empty()) ? m + 1 - i : (*(endpt.begin())) - i);
    while (i == p[currp].l) {
      auto itr = endpt.find(p[currp].r);
      endpt.erase(itr);
      currp++;
    }
  }
  cout << cnt << "\n";
  return 0;
}
