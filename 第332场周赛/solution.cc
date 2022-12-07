# 1.回环句

句子 是由单个空格分隔的一组单词，且不含前导或尾随空格。

例如，"Hello World"、"HELLO"、"hello world hello world" 都是符合要求的句子。

单词 仅 由大写和小写英文字母组成。且大写和小写字母会视作不同字符。

如果句子满足下述全部条件，则认为它是一个 回环句 ：

	单词的最后一个字符和下一个单词的第一个字符相等。

	最后一个单词的最后一个字符和第一个单词的第一个字符相等。

例如，"leetcode exercises sound delightful"、"eetcode"、"leetcode eats soul" 都是回环句。

然而，"Leetcode is cool"、"happy Leetcode"、"Leetcode" 和 "I like Leetcode" 都 不 是回环句。

给你一个字符串 sentence ，请你判断它是不是一个回环句。如果是，返回 true ；否则，返回 false 。

class Solution(object):
    def isCircularSentence(self, sentence):
        """
        :type sentence: str
        :rtype: bool
        """
        words = sentence.split(' ')
        n = len(words)
        for i in range(n):
        	next = (i + 1) % n
        	if words[i][-1] != words[next][0]:
        		return false
        return true



# 2.划分技能点相等的团队

给你一个正整数数组 skill ，数组长度为 偶数 n ，其中 skill[i] 表示第 i 个玩家的技能点。将所有玩家分成 n / 2 个 2 人团队，使每一个团队的技能点之和 相等 。

团队的化学反应等于团队中玩家的技能点乘积 。

返回所有团队的化学反应之和，如果无法使每个团队的技能点之和相等，则返回 -1 。

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long tot = 0;
        int n = skill.size();
        map<int, int> mp;
        for (auto x : skill) {
            tot += x;
            mp[x] += 1；
        }
        if (tot % n != 0) return -1;
        tot /= n
        for (auto x : skill) {
            if (mp[x] == 0) continue;
            if (mp.count(tot - x) && mp[tot-x] > 0) {
                mp[x] -= 1;
                mp[tot - x] -= 1;
                ret += (long long)x * (tot - x) 
            }
        }
        return ret;
    }
};
 