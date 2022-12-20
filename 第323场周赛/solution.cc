# 1.给你一个 m x n 大小的矩阵 grid ，由若干正整数组成。

执行下述操作，直到 grid 变为空矩阵：

从每一行删除值最大的元素。如果存在多个这样的值，删除其中任何一个。
将删除元素中的最大值与答案相加。
注意 每执行一次操作，矩阵中列的数据就会减 1 。

返回执行上述操作后的答案。

示例1：

输入：grid = [[1,2,4],[3,3,1]]

输出：8

解释：上图展示在每一步中需要移除的值。

- 在第一步操作中，从第一行删除 4 ，从第二行删除 3（注意，有两个单元格中的值为 3 ，我们可以删除任一）。在答案上加 4 。
- 在第二步操作中，从第一行删除 2 ，从第二行删除 3 。在答案上加 3 。
- 在第三步操作中，从第一行删除 1 ，从第二行删除 1 。在答案上加 1 。

最终，答案 = 4 + 3 + 1 = 8 。

看起来很花哨，但实际上是对每一行进行排序之后，选取每一列的最大值作为得分。最后返回的分之和即可

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0 ; i < n ; i ++) sort(grid[i].begin(), grid[i].end())

        int ret = 0;
        int m = grid[0].size();

        for (int j = 0 ; j < m. j ++) {
            int tmp = 0;
            for (int i = 0 ; i < n ; i ++) {
                tmp = max(tmp, grid[i][j])
            }
            ret += tmp;
        }
        return ret;
    }
};


# 2.数组中最长的方波

给你一个整数数组 nums 。如果 nums 的子序列满足下述条件，则认为该子序列是一个 方波 ：

子序列的长度至少为 2 ，并且
将子序列从小到大排序 之后 ，除第一个元素外，每个元素都是前一个元素的 平方 。
返回 nums 中 最长方波 的长度，如果不存在 方波 则返回 -1 。

子序列 也是一个数组，可以由另一个数组删除一些或不删除元素且不改变剩余元素的顺序得到。

示例 1 ：

输入：nums = [4,3,6,16,8,2]
输出：3
解释：选出子序列 [4,16,2] 。排序后，得到 [2,4,16] 。
- 4 = 2 * 2.
- 16 = 4 * 4.
因此，[4,16,2] 是一个方波.
可以证明长度为 4 的子序列都不是方波。

示例2

输入：nums = [2,3,5,6,7]
输出：-1
解释：nums 不存在方波，所以返回 -1 。

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        map<int, int> mp;

        for (auto x : nums) mp[x] = 1;

        int ret = 1;

        for (auto x : nums) {

            int rt = int(sqrt(x));

            if (rt * rt == x && mp.count(rt))
            {
                int cur = mp[rt] + 1;
                mp[x] = cur;
                ret = max(cur, ret);
            }
        }
        return ret > 1 ? ret : -1;
    }
};