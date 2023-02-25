#include <iostream>
using namespace std;

// sum of even index elements and sum of odd 
// index element should be same after removing the element.

int main() {

	int arr[] = {2,4,2,3,3};
	int  n = 5;

	int evenSum[n];
	int oddSum[n];

	evenSum[0] = arr[0];
	oddSum[0]=0;

	for(int i = 1 ; i < n; i++)
	{
		if(i%2 == 1)
		{
			oddSum[i] = oddSum[i-1] + arr[i];
			evenSum[i] = evenSum[i-1];
		}else{
			
			evenSum[i] = evenSum[i-1]+ arr[i];
			oddSum[i] = oddSum[i-1];
		}
	}

	for(int i = 1 ; i < n; i++)
	{
		if(evenSum[i-1] + oddSum[n-1] - oddSum[i] == oddSum[i-1] + evenSum[n-1] - evenSum[i])
		{
			cout<<i<<" ";
		}
	}



}