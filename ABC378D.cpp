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

int h, w, k;
char mp[15][15];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool vis[15][15];
int dep;
ll cnt;

void dfs(int x, int y) {
  if (dep == k)
    cnt++;
  else {
    for (int r = 0; r < 4; r++)
      if (x + dir[r][0] >= 0 && x + dir[r][0] < h && y + dir[r][1] >= 0 &&
          y + dir[r][1] < w && mp[x + dir[r][0]][y + dir[r][1]] == '.' &&
          !vis[x + dir[r][0]][y + dir[r][1]]) {
        dep++;
        vis[x + dir[r][0]][y + dir[r][1]] = 1;
        dfs(x + dir[r][0], y + dir[r][1]);
        vis[x + dir[r][0]][y + dir[r][1]] = 0;
        dep--;
      }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> h >> w >> k;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      cin >> mp[i][j];
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      if (mp[i][j] == '.') {
        dep = 0;
        memset(vis, 0, sizeof(vis));
        vis[i][j] = 1;
        dfs(i, j);
        vis[i][j] = 0;
      }
  cout << cnt << "\n";
  return 0;
}