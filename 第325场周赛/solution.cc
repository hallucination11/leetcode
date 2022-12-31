# 1.到目标字符串的最短距离

给你一个下标从 0 开始的环形字符串数组 words 和一个字符串 target 。环形数组 意味着数组首尾相连。

形式上， words[i] 的下一个元素是 words[(i + 1) % n] ，而 words[i] 的前一个元素是 words[(i - 1 + n) % n] ，其中 n 是 words 的长度。
从 startIndex 开始，你一次可以用 1 步移动到下一个或者前一个单词。

返回到达目标字符串 target 所需的最短距离。如果 words 中不存在字符串 target ，返回 -1 。


示例 1：

输入：words = ["hello","i","am","leetcode","hello"], target = "hello", startIndex = 1
输出：1
解释：从下标 1 开始，可以经由以下步骤到达 "hello" ：
- 向右移动 3 个单位，到达下标 4 。
- 向左移动 2 个单位，到达下标 4 。
- 向右移动 4 个单位，到达下标 0 。
- 向左移动 1 个单位，到达下标 0 。
到达 "hello" 的最短距离是 1 。


示例 2：

输入：words = ["a","b","leetcode"], target = "leetcode", startIndex = 0
输出：1
解释：从下标 0 开始，可以经由以下步骤到达 "leetcode" ：
- 向右移动 2 个单位，到达下标 3 。
- 向左移动 1 个单位，到达下标 3 。
到达 "leetcode" 的最短距离是 1 。


示例 3：

输入：words = ["i","eat","leetcode"], target = "ate", startIndex = 0
输出：-1
解释：因为 words 中不存在字符串 "ate" ，所以返回 -1 。


我们只需要枚举一下移动的次数，再使用两个变量分别记录往左和往右移动i步之后的下标即可


class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int l = startIndex - 1, r = startIndex + 1;
        int n = words.size();

        for (int i = 0 ; i < n ; i ++) {
            l = (l+1) % n;
            r = (r-1+n) % n;
            if (words[l] == target || words[r] == target) return i;
        }
        return -1;
            
    }
};

# 2.每种字符至少取 K 个

给你一个由字符 'a'、'b'、'c' 组成的字符串 s 和一个非负整数 k 。每分钟，你可以选择取走 s 最左侧 还是 最右侧 的那个字符。

你必须取走每种字符 至少 k 个，返回需要的 最少 分钟数；如果无法取到，则返回 -1 。

示例 1：

输入：s = "aabaaaacaabc", k = 2
输出：8
解释：
从 s 的左侧取三个字符，现在共取到两个字符 'a' 、一个字符 'b' 。
从 s 的右侧取五个字符，现在共取到四个字符 'a' 、两个字符 'b' 和两个字符 'c' 。
共需要 3 + 5 = 8 分钟。
可以证明需要的最少分钟数是 8 。

示例 2：

输入：s = "a", k = 1
输出：-1
解释：无法取到一个字符 'b' 或者 'c'，所以返回 -1 。

class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();
        if (k == 0) return -1;
        int a = 0 , b = 0 , c = 0;
        int l = 0;
        bool flag = false;
        for (int i = 0 ; i < n ; i ++) {
            if (s[i] == 'a') a ++;
            if (s[i] == 'b') b ++;
            if (s[i] == 'c') c ++;

            if (a >= k && b >= k && c >= k) {
                flag = true;
                break;
            }
        }
        int ret = l + 1;
        int r = n;
        while (l >= 0) {
            if (s[l] == 'a') a --;
            if (s[l] == 'b') b --;
            if (s[l] == 'c') c --;
            l --;

            while (l < n && (a < k || b < k || c < k)) {
                if (s[r] == 'a') a ++;
                if (s[r] == 'b') b ++;
                if (s[r] == 'c') c ++;

                if (a >= k && b >= k && c >= k) {
                    return min(ret, l + 1 + n - r);
                }
            }
        }
        return ret;

    }
};
