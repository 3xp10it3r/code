#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s = "zyabxcax";
	string newString = "";
	int freqArr[26] = {0};
	for(int i=0; i < s.size(); i++)
	{
		freqArr[s[i]-'a']++;
	}

	for(int i=25; i >= 0 ; i--)
	{
		for(int j = 0 ; j < freqArr[i] ; j++)
		{
			newString += (i + 'a');
		}
	}

	for(int i=0; i < s.size(); i++)
	{
		if(s[i]!=newString[i])
		{
			for(int j = s.size(); j > i; j--)
			{
				if(s[j] == newString[i])
				{
					swap(s[i],s[j]);
					break;
				}
			}
			break;
		}
	}

	cout<<s<<endl;
	return 0;
}