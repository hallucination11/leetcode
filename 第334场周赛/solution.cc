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

2.找出字符串的可整除数组

给你一个下标从 0 开始的字符串 word ，长度为 n ，由从 0 到 9 的数字组成。另给你一个正整数 m 。

word 的 可整除数组 div  是一个长度为 n 的整数数组，并满足：

如果 word[0,...,i] 所表示的 数值 能被 m 整除，div[i] = 1
否则，div[i] = 0
返回 word 的可整除数组。

示例 1：

输入：word = "998244353", m = 3
输出：[1,1,0,0,0,1,1,0,0]
解释：仅有 4 个前缀可以被 3 整除："9"、"99"、"998244" 和 "9982443" 。

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ret;
        
        int n = word.length();
        long long md = 0;
            
        for (int i = 0; i < n; i++) {
            // word[i] - '0'，即将字符数字转成int
            // 加入一个新的数字，即md * 10再加上末尾数字
            md = (md * 10 + word[i] - '0') % m;
            ret.push_back(md % m == 0);
        }
        return ret;
    }
};