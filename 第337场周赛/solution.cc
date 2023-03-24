#1.奇偶位数

给你一个 正 整数 n 。

用 even 表示在 n 的二进制形式（下标从 0 开始）中值为 1 的偶数下标的个数。

用 odd 表示在 n 的二进制形式（下标从 0 开始）中值为 1 的奇数下标的个数。

返回整数数组 answer ，其中 answer = [even, odd] 。

示例 1：

输入：n = 17
输出：[2,0]
解释：17 的二进制形式是 10001 。 
下标 0 和 下标 4 对应的值为 1 。 
共有 2 个偶数下标，0 个奇数下标。

class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ret(2, 0);
        for (int i = 0; i < 10; i++) {
            if (n & (1 << i)) {
                ret[i % 2]++;
            }
        }
        return ret;
        
    }
};
