#include <bits/stdc++.h>
using namespace std;

int main()
{
	int arr[] = {1,2,6,4,6,3,6,4,6}; // 123446666
	int size = 9;


	sort(arr,arr+size);

	for(int i = 0; i < size ; i++)
	{
		if( i+1 < size && arr[i] == arr[i+1])
		{
			
			continue;
		}
		else{
			if(arr[i] == size - i - 1)
			{
				cout<<arr[i]<<endl;
			}
		}
	}
}