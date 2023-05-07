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


6.四数相加II

给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。

为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -2^28 到 2^28 - 1 之间，最终结果不会超过 2^31 - 1 。

例如:

输入:

A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]
输出:

2

解释:

两个元组如下:

(0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
(1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> umap;
        for (int a : A) {
            for (int b : B) {
                umap[a + b]++;
            }
        }

        int count = 0;

        for (int c : C) {
            for (int d : D) {
                if (umap.find(0 - (c + f)) != umap.end()) {
                    count += umap[0 - (c + d)];
                }
            }
        }

        return count;
    }
};

7.赎金信

给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串 ransom 能不能由第二个字符串 magazines 里面的字符构成。如果可以构成，返回 true ；

否则返回 false。

(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。杂志字符串中的每个字符只能在赎金信字符串中使用一次。)

注意：

你可以假设两个字符串均只含有小写字母。

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};

        if (ransomNote.size() > magazine.size()) {
            return false;
        }

        for (int i = 0 ; i < magazine.length() ; i ++) {
            records[magazine[i] - 'a'] ++;
        }

        for (int i = 0 ; i < ransom.length() ; i ++) {
            records[ransom[i] - 'a'] --;
            if (records[ransom[i] - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};

8.三数之和

给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意： 答案中不可以包含重复的三元组。

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为： [ [-1, 0, 1], [-1, -1, 2] ]

--双指针
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        for (int i = 0 ; i < nums.size() ; i ++) {
            
            if (nums[i] >= 0) {
                return result;
            }

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] > 0) {
                    right --;
                } else if (nums[i] + nums[left] + nums[right] < 0) {
                    left ++;
                } else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]})
                    while (right > left && nums[right] == nums[right - 1]) {
                        right --
                    }
                    while (right > left && nums[left] == nums[left + 1]) {
                        left ++
                    }

                    left ++;
                    right --;
                }
            }
        }

        return result;
    }
};

9.四数之和

题意：给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？

找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例： 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。 满足要求的四元组集合为： [ [-1, 0, 0, 1], [-2, -1, 1, 2], [-2, 0, 0, 2] ]


