#include<bits/stdc++.h>
using namespace std;

int main() 
{

	int arr[] = {2,4,1,3,8};
	int size = 5;
	int k = 1;

	int prefixArr[size]; //to count number 
						//of odds upto that index.


	prefixArr[0] = arr[0] % 2; 
	for(int i = 1 ; i < size ; i++)
	{
		prefixArr[i] = prefixArr[i-1] + arr[i] % 2; 
	}

	for(int i = 0 ; i < size ; i++)
	{
		cout<<prefixArr[i]<<" ";
	}
	cout<<endl;

	int ans = 0;

	unordered_map<int,int> mp;
	mp[0]=1;
	for(int i = 0 ; i < size; i++)
	{
		if(mp.find(prefixArr[i]-k)!=mp.end())
		{
			ans += mp[prefixArr[i]-k];
		}
		mp[prefixArr[i]]++;
	}

	cout<<ans<<endl;
	return 0;
}