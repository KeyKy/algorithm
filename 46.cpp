/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

class Solution {
public:
    
    void swap(vector<int>& nums, int k, int p) {
        int tmp = nums[k];
        nums[k] = nums[p];
        nums[p] = tmp;
    }
    
    void perm(vector<int>& nums, int k, vector<vector<int>> &result) {
        if (k > nums.size()-1) {
            result.push_back(nums);
        }
            
        for (int i = k; i < nums.size(); i++) {
            swap(nums, i, k);
            perm(nums, k+1, result);
            swap(nums, i, k);
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        perm(nums, 0, result);
        return result;
    }
};
