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