#1.左右元素和的差值
给你一个下标从 0 开始的整数数组 nums ，请你找出一个下标从 0 开始的整数数组 answer ，其中：

answer.length == nums.length
answer[i] = |leftSum[i] - rightSum[i]|
其中：

leftSum[i] 是数组 nums 中下标 i 左侧元素之和。如果不存在对应的元素，leftSum[i] = 0 。
rightSum[i] 是数组 nums 中下标 i 右侧元素之和。如果不存在对应的元素，rightSum[i] = 0 。
返回数组 answer 。

示例 1：

输入：nums = [10,4,8,3]
输出：[15,1,11,22]
解释：数组 leftSum 为 [0,10,14,22] 且数组 rightSum 为 [15,11,3,0] 。
数组 answer 为 [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22] 。

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int lef[n+1], rig[n+1];
        memset(lef, 0, sizeof lef);
        memset(rig, 0, sizeof rig);

        lef[0] = 0;
        for (int i = 1 ; i < n ; i ++) {
            lef[i] = lef[0] + nums[i - 1];
        }
        right[n] = 0;
        for (int i = n - 1 ; i >= 0 ; i--) {
            right[i] = right[n] + nums[i + 1];
        }

        vector<int> res;
        for (int i = 0 ; i < n ; i++) {
            res.push_back(abs(lef[i] - right[i]));
        }
        return res;
    }
};