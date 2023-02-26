#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> v = {10,45,33,37,97};
	int n = v.size();

	sort(v.begin(),v.end());
	int ans  = INT_MAX;
	int diff = INT_MAX;
	for(int i = 0 ; i < n-1 ; i++)
	{
		if(diff > abs(v[i]-v[i+1]))
		{
			diff  = abs(v[i]-v[i+1]);
			ans = i;
		}
	}
	cout<<ans;
	return 0;
}