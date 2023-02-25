#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,j;
	cin>>n;	

	int arr[n];
	unordered_map<int,pair<int,int>> mp;
	
	for(int i=0; i < n ; i++)
	{
		cin>>arr[i];
	}

	for(int i=0; i < n-1 ; i++)
	{
		for(int j = i+1; j < n ; j++ )
		{
			if(mp.find(arr[i]+arr[j])!=mp.end() && i!=mp[arr[i]+arr[j]].first && j!=mp[arr[i]+arr[j]].second)
			{
				cout<<"true"<<endl;
				return 1;
			}else{
				mp[arr[i]+arr[j]] = {i,j};
			}

		}
	}
	

}

//a+b = c+d  for all i!=j!=k!=l