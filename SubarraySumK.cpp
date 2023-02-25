#include<bits/stdc++.h>

using namespace std;

int main() {

	int arr[] = {10,2,-2,-20,10};
	int k = -10;
	int size = 5;

	int prefixArr[size];
	int prev = 0;
	for(int i = 0; i < size; i++)
	{
		prefixArr[i] = prev + arr[i];
		prev = prefixArr[i];
	}

	for(int i = 0; i < size; i++)
	{
		cout<<prefixArr[i]<<" ";
	}

	cout<<endl;

	unordered_map<int,int> mp;

	int countSub = 0;

	mp[0] = 1;
	for(int i = 0; i < size; i++)
	{
		if(mp.find(prefixArr[i] - k)!=mp.end())
		{
			countSub+=mp[prefixArr[i] - k];
		}
		mp[prefixArr[i]]++;
	}
	cout<<countSub<<endl;
	return 0;
}