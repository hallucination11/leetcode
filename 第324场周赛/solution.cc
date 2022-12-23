# 1.统计相似字符串对的数目
给你一个下标从 0 开始的字符串数组 words 。

如果两个字符串由相同的字符组成，则认为这两个字符串 相似 。

例如，"abca" 和 "cba" 相似，因为它们都由字符 'a'、'b'、'c' 组成。
然而，"abacba" 和 "bcfd" 不相似，因为它们不是相同字符组成的。
请你找出满足字符串words[i] 和 words[j] 相似的下标对 (i, j) ，并返回下标对的数目，其中 0 <= i < j <= word.length - 1 。


示例 1：

输入：words = ["aba","aabb","abcd","bac","aabc"]
输出：2
解释：共有 2 对满足条件：
- i = 0 且 j = 1 ：words[0] 和 words[1] 只由字符 'a' 和 'b' 组成。 
- i = 3 且 j = 4 ：words[3] 和 words[4] 只由字符 'a'、'b' 和 'c' 。 

示例 2：

输入：words = ["aabb","ab","ba"]
输出：3
解释：共有 3 对满足条件：
- i = 0 且 j = 1 ：words[0] 和 words[1] 只由字符 'a' 和 'b' 组成。 
- i = 0 且 j = 2 ：words[0] 和 words[2] 只由字符 'a' 和 'b' 组成。 
- i = 1 且 j = 2 ：words[1] 和 words[2] 只由字符 'a' 和 'b' 组成。 

示例 3：

输入：words = ["nba","cba","dba"]
输出：0
解释：不存在满足条件的下标对，返回 0 。

解析：

首先，我们将二十六个字母转化成0-26的数字。接着使用位运算操作，1 << x表示将1左移x位，
对应第x位二进制位为1的整数。我们在某个数上加上这个数就相当于将它的第x位标记成了1。通过这个技巧，我们只需要使用整数就可以表示一个字符串的构成。
那么我们在使用一个map来统计一下每个构成出现的次数，就可以很轻松地得到答案。


class Solution {
public:
    int similarPairs(vector<string>& words) {
        mp<int, int> mp;
        for (auto w : words) {
            int tmp = 0;
            for (auto c : w) {
                tmp |= 1 << (c - 'a') 
            }
            mp[tmp] ++;
        }
        int ret = 0;
        for (auto it : mp) {
            if (it.second > 1) {
                // 假设某一个构成出现x次，那么对应的字符串对数量为C(x, 2)，即x(x-1)/2
                ret += (it.second * (it.second - 1)) / 2;
            }
        }
        return ret;
    }
};


# 2.使用质因数之和替换后可以取到的最小值

给你一个正整数 n 。

请你将 n 的值替换为 n 的 质因数 之和，重复这一过程。

注意，如果 n 能够被某个质因数多次整除，则在求和时，应当包含这个质因数同样次数。
返回 n 可以取到的最小值。

示例 1：

输入：n = 15
输出：5
解释：最开始，n = 15 。
15 = 3 * 5 ，所以 n 替换为 3 + 5 = 8 。
8 = 2 * 2 * 2 ，所以 n 替换为 2 + 2 + 2 = 6 。
6 = 2 * 3 ，所以 n 替换为 2 + 3 = 5 。
5 是 n 可以取到的最小值。


示例 2：

输入：n = 3
输出：3
解释：最开始，n = 3 。
3 是 n 可以取到的最小值。


class Solution {
public:
    int smallestValue(int n) {
        vector<bool> is_prime(100050, 1);
        vector<int> prime;

        // 筛法，筛选出1e5范围内的所有素数
        const int N = 100001;
        for (int i = 2; i < N; i++) {
            if (is_prime[i]) {
                prime.push_back(i);
                for (int j = i * 2; j < N; j+=i) {
                    is_prime[j] = 0;
                }
            }
        }

        int ret = n;
        int tmp = 0;

        while(true) {
            tmp = 0;
            // 记录之前的n
            int cur = n;
            while (n > 1) {
                for (auto x : prime) {
                    while (n % x == 0) {
                        n = n / x;
                        tmp += x;
                    }
                }
            }
            // 如果变化前后一样，则break
            if (cur == tmp) break;
            n = tmp;
            ret = min(ret, tmp);
        }
        return ret;
    }
};









