#include <iostream>
#include <vector>

const int MOD = 998244353;

using namespace std;

vector<int> adj[200005];
int cnt[200005];
bool vis[200005];

void dfs(int u)
{
    vis[u] = true;
    cnt[u] = 1;
    for (int v : adj[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
        cnt[u] = (cnt[u] + cnt[v]) % MOD;
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    if (!vis[N])
    {
        cout << -1 << endl;
    }
    else
    {
        cout << cnt[1] << endl;
    }

    return 0;
}
