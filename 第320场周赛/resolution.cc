# 1.数组中不等三元组的数目

给你一个下标从 0 开始的正整数数组 nums 。请你找出并统计满足下述条件的三元组 (i, j, k) 的数目：

0 <= i < j < k < nums.length

nums[i]、nums[j] 和 nums[k] 两两不同 。换句话说：nums[i] != nums[j]、nums[i] != nums[k] 且 nums[j] != nums[k] 。

返回满足上述条件三元组的数目。


class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int ret = 0, n = nums.size();

        for (int i = 0 ; i < n ; i ++) {
            for (int j = i + 1 ; j < n ; j ++) {
                for (int k = j + 1 ; k < n ; k ++) {
                    if (nums[i] != nums[j] && nums[i] != nums[k] && nums[j] != nums[k]) ret ++;
                }
            }
        }

        return ret; 
    }
};
