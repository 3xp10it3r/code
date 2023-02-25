#include <bits/stdc++.h>
using namespace std;

//max sum choosing K elements from both ends of the Array

int main(int argc, char const *argv[])
{
	int arr[] = {-2,200,100,1,2};
	int k = 3;
	int mx = INT_MIN;

	int n = sizeof(arr)/sizeof(arr[0]);

	int prefixSum[n];
	prefixSum[0] = arr[0]; 
	for(int i = 1 ; i < n ; i++)
	{
		prefixSum[i] = prefixSum[i-1] + arr[i];
	}


	for(int i = k ; i >=0 ; i--)
	{
		int left,right;
		left  = (i-1 >= 0) ? prefixSum[i-1] : 0 ;
		right = prefixSum[n-1] - prefixSum[n-k+i-1];
		cout<<"left :"<<left << " right :"<<right<<endl;
		mx = max(mx,left+right);
	}

	cout<<"ans:"<<mx;

	return 0;
}