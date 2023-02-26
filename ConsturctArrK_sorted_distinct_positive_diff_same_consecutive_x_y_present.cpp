#include <bits/stdc++.h>
using namespace std;

// Given some information, construct an array of size k.
// 1.Array should be sorted.
// 2.All element should be distinct and positive (>=1)
// 3.Difference between 2 consecutive element should be same.
// 4.X and y should be present in the array. (x<y).

// Objective: The last element of the array is as minimum as possible.


// naive approach
// int main()
// {
// 	int k=5,x=20,y=30;
// 	cin>>k>>x>>y;
// 	vector<int> temp(k);
// 	vector<int> ans;
// 	int mn = INT_MAX;

// 	//AP
// 	// a  a+d  a+2d a+3d .... a + (n-1)d --> AP series

// 	// a starting term.. [ 1 , x]
// 	// d common diff.. [ 1, y-x]

// 	for(int a  = 1 ; a <= x; a++)
// 	{
// 		for(int d = 1 ; d <= (y-x); d++)
// 		{
// 			bool xF = false, yF = false;
// 			for(int i = 0 ; i < k ; i++)
// 			{
// 				temp[i] = a + i*d;
// 				if(temp[i] == x)
// 				{
// 					xF = true;
// 				}
// 				if(temp[i] == y)
// 				{
// 					yF = true;
// 				}
// 			}
// 			if(xF && yF && temp[k-1] < mn)
// 			{
// 				mn = temp[k-1];
// 				ans = temp;
// 			}
// 		}
// 	}
// 	cout<<mn<<"\n";
// 	for(int i= 0 ; i < ans.size(); i++)
// 	{
// 		cout<<ans[i]<<" ";
// 	}
// }


//efficient approach.

int main(int argc, char const *argv[])
{
	int k,x,y;
	cin>>k>>x>>y;


	vector<int> temp(k);
	vector<int> ans;
	int mn = INT_MAX;

	for(int d = 1 ; d <= (y-x); d++)
	{
		if((y-x) % d == 0)
		{
			if(((y-x)/d)+ 1 > k)
			{
				continue;
			}
			int remaining = k - ((y-x)/d) + 1;
			// cout<<remaining<<" d"<<d<<endl;
			int i=1;
			for(; i < k ; i++)
			{
				if(i*d <=x && remaining > 0 && i*d > 0)
				{
					temp[i-1] = i*d;
					remaining--;
				}else{
					break;
				}
			}
			for(; i<k; i++)
			{
				if(i*d <= y )
				{
					temp[i-1] = i*d;
				}else{
					break;
				}
			}
			for(; i<k; i++)
			{
				if(remaining > 0)
				{
					temp[i-1] = i*d;
					remaining--;
				}
			}
			for(int i= 0 ; i < k; i++)
			{
				cout<<temp[i]<<" ";
			}
			cout<<endl;
		}
		
	}




	return 0;
}