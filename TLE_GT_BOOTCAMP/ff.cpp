// C++ Program for Floyd Warshall Algorithm
#include <bits/stdc++.h>
using namespace std;


#define INF 100


// Solves the all-pairs shortest path
// problem using Floyd Warshall algorithm
void floydWarshall(vector<vector<int>>& dist, long long V)
{
	int i, j, k;
	for (k = 1; k < V; k++) {
		for (i = 1; i < V; i++) {
			for (j = 1; j < V; j++) {
				if (dist[i][j] > (dist[i][k] + dist[k][j])
					&& (dist[k][j] != INF
						&& dist[i][k] != INF))
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> cost(n+1);
	for(int i = 1 ; i <= n ; i++) {
		cin >> cost[i];
	}
	vector<vector<int>> graph(n+1, vector<int>(n+1,INF));
	for(int i = 1 ; i <= m; i++){
		int u, v;
		cin >> u >> v;
		graph[u][v] = abs(cost[u]-cost[v]);
		graph[v][u] = abs(cost[u]-cost[v]);
	}
	for(auto it: graph){
		for(auto it1: it) {
			cout << it1 << " ";
		}
		cout << "\n";
	}
	floydWarshall(graph,n);
	for(auto it: graph){
		for(auto it1: it) {
			cout << it1 << " ";
		}
		cout << "\n";
	}
	long long q;
	cin >> q;
	for(int i = 0 ; i < q ; i++){
		int a,b,e;
		cin >> a >> b >> e;
		if(graph[a][b] <= e) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}

// This code is contributed by Mythri J L
