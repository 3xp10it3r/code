#include<bits/stdc++.h>

using namespace std;

int main()
{
	int arr[] = {3,2,1,4,6};
	int size = 5;

	sort(arr,arr+size); //1,2,3,5,6

	vector<pair<int,int>> li;
	int min_d = INT_MAX;
	for(int i = 0  ; i < size -1 ; i++)
	{
		int d = abs( arr[i+1] - arr[i]);

		if(d<min_d)
		{
			min_d = d;
			li.clear();
			li.push_back({arr[i],arr[i+1]});
		}
		else if(d == min_d)
		{
			li.push_back({arr[i],arr[i+1]});
		}
	}

	for(auto it: li)
	{
		cout<<it.first<<" "<<it.second<<endl;
	}

}