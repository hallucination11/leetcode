#1.统计范围内的元音字符串数

给你一个下标从 0 开始的字符串数组 words 和两个整数：left 和 right 。

如果字符串以元音字母开头并以元音字母结尾，那么该字符串就是一个 元音字符串 ，其中元音字母是 'a'、'e'、'i'、'o'、'u' 。

返回 words[i] 是元音字符串的数目，其中 i 在闭区间 [left, right] 内。

 
示例 1：

输入：words = ["are","amy","u"], left = 0, right = 2
输出：2
解释：
- "are" 是一个元音字符串，因为它以 'a' 开头并以 'e' 结尾。
- "amy" 不是元音字符串，因为它没有以元音字母结尾。
- "u" 是一个元音字符串，因为它以 'u' 开头并以 'u' 结尾。
在上述范围中的元音字符串数目为 2 。

class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        set<string> s;
        s.insert('a');
        s.insert('e');
        s.insert('i');
        s.insert('o');
        s.insert('u');
        int res = 0;
        for (int i = left ; i <= right; i ++) {
            if (s.count(words[i].begin()) && s.count(words[i].end())) {
                res += 1;
            }
        }
        return res;
    }
};

#2.重排数组以得到最大前缀分数

给你一个下标从 0 开始的整数数组 nums 。你可以将 nums 中的元素按 任意顺序 重排（包括给定顺序）。

令 prefix 为一个数组，它包含了 nums 重新排列后的前缀和。换句话说，prefix[i] 是 nums 重新排列后下标从 0 到 i 的元素之和。

nums 的 分数 是 prefix 数组中正整数的个数。

返回可以得到的最大分数。

示例 1：

输入：nums = [2,-1,0,1,-3,3,-3]
输出：6
解释：数组重排为 nums = [2,3,1,-1,-3,0,-3] 。
prefix = [2,5,6,5,2,2,-1] ，分数为 6 。
可以证明 6 是能够得到的最大分数。

class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<>());
        int n = nums.size(), res = 0;
        long long tot = 0;
        for (int i = 0 ; i < n ; i ++) {
            tot += nums[i];
            if (tot > 0) res ++;
        }     
        return res;   
    }
};


#3.统计美丽子数组数目

给你一个下标从 0 开始的整数数组nums 。每次操作中，你可以：

选择两个满足 0 <= i, j < nums.length 的不同下标 i 和 j 。

选择一个非负整数 k ，满足 nums[i] 和 nums[j] 在二进制下的第 k 位（下标编号从 0 开始）是 1 。

将 nums[i] 和 nums[j] 都减去 2的k次方 。

如果一个子数组内执行上述操作若干次后，该子数组可以变成一个全为 0 的数组，那么我们称它是一个 美丽 的子数组。

请你返回数组 nums 中 美丽子数组 的数目。

子数组是一个数组中一段连续 非空 的元素序列。

示例 1：

输入：nums = [4,3,1,2,4]
输出：2
解释：nums 中有 2 个美丽子数组：[4,3,1,2,4] 和 [4,3,1,2,4] 。
- 按照下述步骤，我们可以将子数组 [3,1,2] 中所有元素变成 0 ：
  - 选择 [3, 1, 2] 和 k = 1 。将 2 个数字都减去 21 ，子数组变成 [1, 1, 0] 。
  - 选择 [1, 1, 0] 和 k = 0 。将 2 个数字都减去 20 ，子数组变成 [0, 0, 0] 。
- 按照下述步骤，我们可以将子数组 [4,3,1,2,4] 中所有元素变成 0 ：
  - 选择 [4, 3, 1, 2, 4] 和 k = 2 。将 2 个数字都减去 22 ，子数组变成 [0, 3, 1, 2, 0] 。
  - 选择 [0, 3, 1, 2, 0] 和 k = 0 。将 2 个数字都减去 20 ，子数组变成 [0, 2, 0, 2, 0] 。
  - 选择 [0, 2, 0, 2, 0] 和 k = 1 。将 2 个数字都减去 21 ，子数组变成 [0, 0, 0, 0, 0] 。

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        
    }
};
