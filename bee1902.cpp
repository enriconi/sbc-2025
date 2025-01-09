#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define endl '\n'
#define EPS 1e-9
#define x first
#define y second
#define mp make_pair

const int INF = 1000000010;

#define MAX 112345
#define MOD 1000000007

int n, nei[MAX], vis[MAX];
map<string, int> s2i;

int dfs(int u, int i) {
  if (vis[u]) return vis[u] == i;
  vis[u] = i;
  return dfs(nei[u], i);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int u, v, ans = 0;
  n = 0;
  string sA, sB;
  while (cin >> sA >> sB) {
    u = s2i.find(sA) == s2i.end() ? (s2i[sA] = n++) : s2i[sA];
    v = s2i.find(sB) == s2i.end() ? (s2i[sB] = n++) : s2i[sB];
    nei[u] = v;
  }
  memset(vis, 0, sizeof(vis));
  for (u = 0; u < n; u++) ans += dfs(u, u + 1);
  cout << ans << endl;

  return 0;
}