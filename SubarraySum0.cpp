#include<bits/stdc++.h>

using namespace std;

int main() {

	int arr[] = {5,7,5,13};
	int size = sizeof(arr)/sizeof(arr[0]);

	set<int> st;
	st.insert(0);

	int prefixArr[size];

	prefixArr[0] = arr[0];
	for(int i = 1 ; i < size; i++)
	{
		prefixArr[i] = arr[i]+ prefixArr[i-1];
	}

	for(int i = 0 ; i < size; i++)
	{
		cout<< prefixArr[i] << " " ;
	}
	cout<<endl;

	for(int i = 0 ; i < size; i++)
	{
		if(st.find(prefixArr[i])!=st.end()){
			cout<<"TRUE"<<endl;
			return 1;
		}
		st.insert(prefixArr[i]);
	}



	for(int i = 0 ; i < size ; i++)
	{
		int sum = arr[i];
		for(int j = i+1; j < size; j++)
		{
			if(sum == 0){
				cout<<"YES"<<endl;
				return 1;
			}
			sum+=arr[j];
		}
	}
	cout<<"NO";
	return 0;

}