#include <bits/stdc++.h>
using namespace std;
void print(vector<int> x){for(auto e: x){cout<<e<<" ";}cout<<endl;}
void print2D(vector<vector<int>> x){for(auto v: x){for(auto e: v){cout<<e<<" ";}cout<<endl;}cout<<endl;}
int maxElement(vector<int> v){int mx = v[0];for(int i =1 ; i < v.size(); i++){mx = max(mx,v[i]);}return mx;}


void dfs(int currNode,int parent, vector<vector<int>>& adj,vector<int>& leafs){
	if(adj[currNode].size() == 0 && parent!=-1) leafs[parent]++;
	for(auto neighbour: adj[currNode]){
		if(parent!=neighbour){
			dfs(neighbour,currNode,adj,leafs);
		}
	}
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>> adj(n,vector<int>());
	for(int i = 0 ; i < n-1; i++){
		int u;
		cin>>u;
		u--;
		adj[u].push_back(i+1);
	}

	vector<int> leafs(n,0);
	
	dfs(0,-1,adj,leafs);
	bool flag = true;
	for(int i = 0 ; i < n; i++){
		if(adj[i].size() > 0 && leafs[i] < 3){
			flag = false;
			break;
		}
	}
	if(flag){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	// print(leafs);

	return 0;
}
