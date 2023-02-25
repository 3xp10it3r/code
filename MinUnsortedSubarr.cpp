#include <bits/stdc++.h>
using namespace std;

int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        int left = -1, right = -1;
        //find fishy indexes from left and right

        for(int i = 0; i < n-1 ; i++)
        {
            if(nums[i]>nums[i+1])
            {
                left = i;
                break;
            }
        }

        for(int i  = n-1 ; i > 0; i--)
        {
            if(nums[i] < nums[i-1])
            {
                right = i;
                break;
            }
        }

        if(left == -1 or right == -1)
        {
        	return 0;
        }

        // find if there is any more .
        int mx = INT_MIN;
        int mn = INT_MAX;

        for(int i = left ; i <= right ; i++)
        {
            mx = max(mx,nums[i]);
            mn = min(mn,nums[i]);
        }

        for(int i = 0 ; i <= left ; i++)
        {
            if(mn < nums[i])
            {
                left = i;
                break;
            }
        }

        for(int i = n-1 ; i >= right ; i--)
        {
            if(mx < nums[i])
            {
                right = i;
                break;
            }
        }
        

        return right-left+1;
    }

int main(int argc, char const *argv[])
{
	vector<int> nums = {2,6,4,8,10,9,15};

	cout<< findUnsortedSubarray(nums) << endl;
	
	return 0;
}