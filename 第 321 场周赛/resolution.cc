# 1.找出中枢整数

给你一个正整数 n ，找出满足下述条件的 中枢整数 x ：

1 和 x 之间的所有元素之和等于 x 和 n 之间所有元素之和。

返回中枢整数 x 。如果不存在中枢整数，则返回 -1 。题目保证对于给定的输入，至多存在一个中枢整数。


class Solution {
public:
    int pivotInteger(int n) {
		x = sqrt((n * n + n) / 2);       
		if (2 * x * x == n * n + n) return x;
		else return -1;
    }
};


# 2.追加字符以获得子序列

给你两个仅由小写英文字母组成的字符串 s 和 t 。

现在需要通过向 s 末尾追加字符的方式使 t 变成 s 的一个 子序列 ，返回需要追加的最少字符数。

子序列是一个可以由其他字符串删除部分（或不删除）字符但不改变剩下字符顺序得到的字符串。

示例 1：
输入：s = "coaching", t = "coding"
输出：4
解释：向 s 末尾追加字符串 "ding" ，s = "coachingding" 。
现在，t 是 s ("coachingding") 的一个子序列。
可以证明向 s 末尾追加任何 3 个字符都无法使 t 成为 s 的一个子序列。

示例 2：
输入：s = "z", t = "abcde"
输出：5
解释：向 s 末尾追加字符串 "abcde" ，s = "zabcde" 。
现在，t 是 s ("zabcde") 的一个子序列。 
可以证明向 s 末尾追加任何 4 个字符都无法使 t 成为 s 的一个子序列。


解析：本题中说的是子序列而非子串，故可以不连续，我们只需要从头开始贪心的匹配t串中的字符，最后剩余的不能匹配的就是需要添加的。

class Solution {
public:
    int appendCharacters(string s, string t) {
		 int m = 0;
		 for (char c : s) {
		 	if (c == t[m] && m < t.length()) {
		 		m ++;
		 	}
		 }
		 return t.length() - m;
    }
};