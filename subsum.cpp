#include <bits/stdc++.h>
using namespace std;

// Objective: find out if a subset of numbers can sum up to some target
// Method: Recursive Backtracking

vector<int> nums = {1, 3, 5};

bool subsum(int target, int idx=0)
{
    // Base case: we have found a subset that adds up to the target sum
    if(target==0)
        return true;
    // Base case: we have gone beyond the end of the vector or have exceeded the target sum
    if(target<0||idx>nums.size())
        return false;

    // Recursive case: we can either include or exclude the current number and try to find a solution
    bool without = subsum(target,idx+1);
    bool with = subsum(target-nums[idx],idx+1);

    // If either recursive call finds a solution, we return true
    return without||with;
}

int main()
{
    // Test the function with a target sum of 8
    cout<<subsum(8)<<"\n";
}
