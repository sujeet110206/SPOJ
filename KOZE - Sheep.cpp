#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
vector<vector<bool>> vis;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool is_valid(int r, int c) {
  if (r < 0 || r >= n || c < 0 || c >= m) return false;
  if (grid[r][c] == '#' || vis[r][c]) return false;
  return true;
}

void dfs(int r, int c, int& sheeps, int& wolves, bool& can_escape) {
  vis[r][c] = true;
  if (r == 0 || r == n - 1 || c == 0 || c == m - 1) can_escape = true;
  if (grid[r][c] == 'k') sheeps++;
  if (grid[r][c] == 'v') wolves++;
  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i];
    int nc = c + dc[i];
    if (is_valid(nr, nc))
      dfs(nr, nc, sheeps, wolves, can_escape);
  }
}

void solve() {
  cin >> n >> m;
  grid.resize(n);
  vis.assign(n, vector<bool> (m, false));
  for (int i = 0; i < n; i++) cin >> grid[i];
  int total_surviving_sheeps = 0;
  int total_surviving_wolves = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] != '#' && !vis[i][j]) {
          int sheeps = 0;
        int wolves = 0;
        bool can_escape = false;
        dfs(i, j, sheeps, wolves, can_escape);
        if (can_escape) {
          total_surviving_sheeps += sheeps;
          total_surviving_wolves += wolves;
        } else {
          if (sheeps > wolves) total_surviving_sheeps += sheeps;
          else total_surviving_wolves += wolves;
        }
      }
    }
  }
  cout << total_surviving_sheeps << " " << total_surviving_wolves << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
