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

3.两个数组的交集

题意：给定两个数组，编写一个函数来计算它们的交集。

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set;
        unordered_set<int> nums_set(nums1.begin(), nums1.end());

        for (int num : nums2) {
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }};

4.快乐数

编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。

如果 可以变为  1，那么这个数就是快乐数。

如果 n 是快乐数就返回 True ；不是，则返回 False 。

输入：19
输出：true
解释：
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1

class Solution {
public:
    int getSum(int n) {
        int sum = 0; 
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
    }

    bool isHappy(int n) {
        unordered_set<int> set;

        while (1) {
            int sum = getSum(n);
            if (sum == 1) {
                return true;
            }
            // 如果这个sum曾经出现过，说明已经陷入了无限循环了，立刻return false
            if (set.find(sum) != set.end()) {
                return false;
            } else {
                set.insert(sum);
            }
            n = sum;
        }

    }
};
