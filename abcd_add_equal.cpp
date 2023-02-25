#include<bits/stdc++.h>

using namespace std;

int main() {

	int arr[] = {2,2,2};

	unordered_map<int,pair<int,int>> mp;

	for(int i = 0 ; i < *(&arr + 1) - arr -1 ; i++){
		for(int j = i+1; j < *(&arr + 1) - arr; j++)
		{
			if(mp.find(arr[i]+arr[j]) != mp.end())
			{
				if(mp[arr[i]+arr[j]].first != i &&  mp[arr[i]+arr[j]].second != j)
				{
					cout<<"True";
					return 1;
				}
			}
			mp[arr[i]+arr[j]] = {i,j};
		}
	}
	cout<<"False";
	return 0;
}