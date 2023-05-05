1. 有效的字母异位词

给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

示例 1: 输入: s = "anagram", t = "nagaram" 输出: true

示例 2: 输入: s = "rat", t = "car" 输出: false

说明: 你可以假设字符串只包含小写字母。

class Solution {
public:
    bool isAnagram(string s, string t) {
    	int records[26] = {0};
    	for (int i = 0 ; i < s.size() ; i ++) {
    		records[s[i] - 'A'] ++;
    	}

    	for (int i = 0 ; i < t.size() ; i ++) {
    		records[t[i] - 'A'] --;
    	}

    	for (int i = 0 ; i < records.size() ; i ++) {
    		if (records[i] != 0) {
    			return false;
    		}
    	}
    	return true;
    }
};