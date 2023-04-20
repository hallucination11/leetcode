#1.对角线上的质数

给你一个下标从 0 开始的二维整数数组 nums 。

返回位于 nums 至少一条 对角线 上的最大 质数 。如果任一对角线上均不存在质数，返回 0 。

注意：

如果某个整数大于 1 ，且不存在除 1 和自身之外的正整数因子，则认为该整数是一个质数。
如果存在整数 i ，使得 nums[i][i] = val 或者 nums[i][nums.length - i - 1]= val ，则认为整数 val 位于 nums 的一条对角线上。

示例 1：

输入：nums = [[1,2,3],[5,6,7],[9,10,11]]
输出：11
解释：数字 1、3、6、9 和 11 是所有 "位于至少一条对角线上" 的数字。由于 11 是最大的质数，故返回 11 。


class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        vector<int> q;
        for (int i = 0, j = nums.size() - 1 ; i < nums.length; i ++, j --) {
            q.push_back(nums[i][i]);
            q.push_back(nums[i][j]);
        }
        sort(q.behin(), q.end());

        for (int i = q.size() - 1 l i >= 0; i --) {
            if (q[i] < 2) return 0;
            for (int j = 2 ; j <= q[i] / j ; j ++) {
                if (q[i] % j == 0) {
                    q[i] = -1;
                    continue;
                }
            }
            if (q[i] != -1) return q[i];
        }
        return 0;
    }
};

2.等值距离和
给你一个下标从 0 开始的整数数组 nums 。现有一个长度等于 nums.length 的数组 arr 。对于满足 nums[j] == nums[i] 且 j != i 的所有 j ，
arr[i] 等于所有 |i - j| 之和。如果不存在这样的 j ，则令 arr[i] 等于 0 。

返回数组 arr 。

示例 1：

输入：nums = [1,3,1,1,2]
输出：[5,0,3,4,0]
解释：
i = 0 ，nums[0] == nums[2] 且 nums[0] == nums[3] 。因此，arr[0] = |0 - 2| + |0 - 3| = 5 。 
i = 1 ，arr[1] = 0 因为不存在值等于 3 的其他下标。
i = 2 ，nums[2] == nums[0] 且 nums[2] == nums[3] 。因此，arr[2] = |2 - 0| + |2 - 3| = 3 。
i = 3 ，nums[3] == nums[0] 且 nums[3] == nums[2] 。因此，arr[3] = |3 - 0| + |3 - 2| = 4 。 
i = 4 ，arr[4] = 0 因为不存在值等于 2 的其他下标。

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0 ; i < nums.length - 1 ; i ++) mp[nums[i]].push_back(i);
    }
};






