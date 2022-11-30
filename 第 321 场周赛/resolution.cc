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


# 3.从链表中移除节点

给你一个链表的头节点 head 。

对于列表中的每个节点 node ，如果其右侧存在一个具有 严格更大 值的节点，则移除 node 。

返回修改后链表的头节点 head 。

示例 1：
输入：head = [5,2,13,3,8]
输出：[13,8]
解释：需要移除的节点是 5 ，2 和 3 。
- 节点 13 在节点 5 右侧。
- 节点 13 在节点 2 右侧。
- 节点 8 在节点 3 右侧。


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* dfs(ListNode* u) {
        if (u->next == nullptr) return u;
        u->next = dfs(u->next);
        auto nxt = u->next;
        if (nxt->val > u->val) return nxt;
        return u;
    }

    ListNode* removeNodes(ListNode* head) {
            ListNode *nd = new ListNode(1e9, head);
            return dfs(nd)->next;
    }
};


# 4.统计中位数为 K 的子数组

给你一个长度为 n 的数组 nums ，该数组由从 1 到 n 的 不同 整数组成。另给你一个正整数 k 。

统计并返回 num 中的 中位数 等于 k 的非空子数组的数目。

注意：

数组的中位数是按 递增 顺序排列后位于 中间 的那个元素，如果数组长度为偶数，则中位数是位于中间靠 左 的那个元素。
例如，[2,3,1,4] 的中位数是 2 ，[8,4,3,5,1] 的中位数是 4 。
子数组是数组中的一个连续部分。

示例 1：

输入：nums = [3,2,1,4,5], k = 4
输出：3
解释：中位数等于 4 的子数组有：[4]、[4,5] 和 [1,4,5] 。
示例 2：

输入：nums = [2,3,1], k = 3
输出：1
解释：[3] 是唯一一个中位数等于 3 的子数组。


class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
                
    }
};
