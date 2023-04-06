#1.最长平衡子字符串

给你一个仅由 0 和 1 组成的二进制字符串 s 。  

如果子字符串中 所有的 0 都在 1 之前 且其中 0 的数量等于 1 的数量，则认为 s 的这个子字符串是平衡子字符串。请注意，空子字符串也视作平衡子字符串。 

返回  s 中最长的平衡子字符串长度。

子字符串是字符串中的一个连续字符序列。

示例 1：

输入：s = "01000111"
输出：6
解释：最长的平衡子字符串是 "000111" ，长度为 6 。

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int res = 0, one = 0, zero = 0;
        for (int i = 0 ; i < s.size(); i ++) {
            if (s[i] == '0') {
                if (one) one = 0, zero = 1;
                else zero ++;
            }
            else {
                one ++;
                res = max(res, min(one, zero));
            }
        }
        return res * 2;
    }
};

2.转换二维数组

给你一个整数数组 nums 。请你创建一个满足以下条件的二维数组：

二维数组应该 只 包含数组 nums 中的元素。
二维数组中的每一行都包含 不同 的整数。
二维数组的行数应尽可能 少 。
返回结果数组。如果存在多种答案，则返回其中任何一种。

请注意，二维数组的每一行上可以存在不同数量的元素。

示例 1：

输入：nums = [1,3,4,1,2,3,1]
输出：[[1,3,4,2],[1,3],[1]]
解释：根据题目要求可以创建包含以下几行元素的二维数组：
- 1,3,4,2
- 1,3
- 1
nums 中的所有元素都有用到，并且每一行都由不同的整数组成，所以这是一个符合题目要求的答案。
可以证明无法创建少于三行且符合题目要求的二维数组。

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ret;
        unordered_map<int, int> mp;
        sort(nums.begin(), nums.end());
        for (auto x : nums) {
            mp[x] ++;
            int v = mp[x] - 1;
            if (v == ret.size()) ret.push_back(vector<int>());
            ret[v].push_back(x);
        }
        return ret
    }
}


