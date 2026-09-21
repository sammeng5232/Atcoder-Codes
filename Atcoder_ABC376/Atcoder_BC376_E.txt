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

int t;
ll n, k, currsum, currmin;
multiset<ll> mini;

struct S {
  ll a, b;
} s[200010];

bool cmp(S x, S y) { return x.a < y.a; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    mini.clear();
    currsum = 0;
    currmin = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
      cin >> s[i].a;
    for (int i = 1; i <= n; i++)
      cin >> s[i].b;
    sort(s + 1, s + 1 + n, cmp);
    for (int i = 1; i <= k; i++) {
      mini.insert(s[i].b);
      currsum += s[i].b;
    }
    currmin = s[k].a * currsum;
    for (int j = k + 1; j <= n; j++) {
      if (s[j].b < *mini.rbegin()) {
        currsum += s[j].b - *mini.rbegin();
        mini.erase(--mini.end());
        // this is also ok:
        // mini.erase(mini.lower_bound(*mini.rbegin()));
        mini.insert(s[j].b);
        currmin = min(currmin, s[j].a * currsum);
      }
    }
    cout << currmin << "\n";
  }
  return 0;
}