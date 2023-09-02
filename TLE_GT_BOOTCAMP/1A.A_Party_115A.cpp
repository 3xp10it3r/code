#include<bits/stdc++.h>
using namespace std;

void print(vector<int> x){
	for(auto e: x){
		cout<<e<<" ";
	}
	cout<<endl;
}
void print2D(vector<vector<int>> x){
	for(auto v: x){
		for(auto e: v){
			cout<<e<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

int maxElement(vector<int> v){
	int mx = v[0];
	for(int i =1 ; i < v.size(); i++){
		mx = max(mx,v[i]);
	}
	return mx;
}

void dfs(int currNode, int parent, vector<vector<int>>& adj, vector<int>& level, int currentLevel){
	level[currNode] = currentLevel;
	for(auto neighbour: adj[currNode]){
		if(parent!=neighbour){
			dfs(neighbour,currNode,adj,level,currentLevel+1);
		}
	}
}

int main(){
	int n;
	bool flag = false;
	cin>>n;

	vector<vector<int>> adj(n,vector<int>());

	for(int i = 0 ; i < n ; i++){
		int x;
		cin>>x;
		x--;
		if(x==-2){
			flag = true;
		}else{
			adj[x].push_back(i);
		}
	}

	vector<int> level(n,-1);
	for(int i = 0 ; i < n; i++){
		if(level[i]==-1)
			dfs(i,-1,adj,level,0);
	}

	if(flag && maxElement(level) == -1)
		cout<< 1;
	else
		cout<<maxElement(level)+1;
	
	return 0;
}