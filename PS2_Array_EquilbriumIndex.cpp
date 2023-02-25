#include <bits/stdc++.h>
using namespace std;

// int pivotIndex(vector<int>& nums) {
//         vector<int> prefixSum;
//         prefixSum.push_back(0);
//         int n = nums.size();

//         for(int i=0; i<n; i++)
//         {
//             prefixSum.push_back(prefixSum[i]+nums[i]);
//         }

//          for(int i=0; i<n; i++)
//         {
//             cout<<prefixSum[i];
//         }
//  }

int main() {
	int arr[] = {-7,1,5,2,-4,3};
	int n = 6;
	int prefixSum[n];

	prefixSum[0] = arr[0];
	for(int i = 1 ; i < n ; i++)
	{
		prefixSum[i] = prefixSum[i-1] + arr[i];
	}

	for(int i = 1 ; i < n ; i++)
	{
		if(prefixSum[i-1] == prefixSum[n-1] - prefixSum[i])
		{
			cout<<i<<" ";
		}
	}
	vector<int> v = {1,2,3,4};
	pivotIndex(v);

}