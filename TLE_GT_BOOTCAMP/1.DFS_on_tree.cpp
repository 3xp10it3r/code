#include <bits/stdc++.h>

using namespace std;

void dfs(int currentNode, int parent, vector<vector<int>>& adj, vector<int>& ans){
	ans.push_back(currentNode);
	for(auto neighbour: adj[currentNode]){
		if(parent != neighbour){
			dfs(neighbour,currentNode,adj,ans);
		}
	}
}

int main(){

	int n;
	cin>>n;

	vector<vector<int>> adj(n,vector<int>());
	for(int i = 0 ; i < n - 1 ; i++){  //as we have only n-1 edges for n nodes
		int u,v;
		cin>>u>>v;
		 u--,v--; //if we have given one based.
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int root = 0;
	int parent = -1;

	vector<int> dfs_traversal;
	dfs(root,parent,adj,dfs_traversal);

	for(auto e: dfs_traversal){
		cout<<e+1<<" ";
	}
	return 0;
}


// 8
// 1 2
// 5 6
// 1 3
// 1 4
// 6 7
// 6 8
// 1 6