#include <bits/stdc++.h>

using namespace std;

void dfs(int currentNode, int parent, vector<vector<int>>& adj, vector<int>& children){
	for(auto neighbour: adj[currentNode]){
		if(parent != neighbour){
			children[currentNode]++;
			dfs(neighbour,currentNode,adj,children);
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

	vector<int> children(n,0);
	dfs(root,parent,adj,children);
	for(auto e: children){
		cout<<e<<" ";
	}
	cout<<"\n";
	cout<<"\n";
	//or
	// size of adj list  - 1 , except for root node.

	for(int i = 0; i < n; i++){
		if(i==0) cout<< adj[0].size()<<" "; else cout<<adj[i].size() -1 <<" ";
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