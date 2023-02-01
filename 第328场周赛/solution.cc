# 1.数组元素和与数字和的绝对差

给你一个正整数数组 nums 。

元素和 是 nums 中的所有元素相加求和。
数字和 是 nums 中每一个元素的每一数位（重复数位需多次求和）相加求和。
返回 元素和 与 数字和 的绝对差。

注意：两个整数 x 和 y 的绝对差定义为 |x - y| 。

示例 1：

输入：nums = [1,15,6,3]
输出：9
解释：
nums 的元素和是 1 + 15 + 6 + 3 = 25 。
nums 的数字和是 1 + 1 + 5 + 6 + 3 = 16 。
元素和与数字和的绝对差是 |25 - 16| = 9 。

示例 2：

输入：nums = [1,2,3,4]
输出：0
解释：
nums 的元素和是 1 + 2 + 3 + 4 = 10 。
nums 的数字和是 1 + 2 + 3 + 4 = 10 。
元素和与数字和的绝对差是 |10 - 10| = 0 。

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int ele_sum = 0, num_sum = 0;
        for (int num : nums) {
            ele_sum += num;
            num_sum += getNumSum(num);
        }
        return abs(ele_sum - num_sum);
    }

public: 
    int getNumSum(int num) {
        int res = 0;
        while(num > 0) {
            res += num % 10;
            num /= 10;
        }
        return res;
    }
};


2.子矩阵元素加 1

给你一个正整数 n ，表示最初有一个 n x n 、下标从 0 开始的整数矩阵 mat ，矩阵中填满了 0 。

另给你一个二维整数数组 query 。针对每个查询 query[i] = [row1i, col1i, row2i, col2i] ，请你执行下述操作：

找出 左上角 为 (row1i, col1i) 且 右下角 为 (row2i, col2i) 的子矩阵，将子矩阵中的 每个元素 加 1 。

也就是给所有满足 row1i <= x <= row2i 和 col1i <= y <= col2i 的 mat[x][y] 加 1 。

返回执行完所有操作后得到的矩阵 mat 。

示例1：

输入：n = 3, queries = [[1,1,2,2],[0,0,1,1]]
输出：[[1,1,0],[1,2,1],[0,1,1]]
解释：上图所展示的分别是：初始矩阵、执行完第一个操作后的矩阵、执行完第二个操作后的矩阵。
- 第一个操作：将左上角为 (1, 1) 且右下角为 (2, 2) 的子矩阵中的每个元素加 1 。 
- 第二个操作：将左上角为 (0, 0) 且右下角为 (1, 1) 的子矩阵中的每个元素加 1 。 


示例2：

输入：n = 2, queries = [[0,0,1,1]]
输出：[[1,1],[1,1]]
解释：上图所展示的分别是：初始矩阵、执行完第一个操作后的矩阵。 
- 第一个操作：将矩阵中的每个元素加 1 。

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n+2, vector<int>(n+2, 0));
        
        for (auto &q: queries) {    
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
            diff[r1][c1]++; diff[r2+1][c2+1]++;
            diff[r1][c2+1]--; diff[r2+1][c1]--;
        }
        
        vector<vector<int>> ret(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) ret[i][j] = diff[i][j];
       // 先累加行，再累加列
        for (int i = 0; i < n; i++) for (int j = 1; j < n; j++) ret[i][j] += ret[i][j - 1];
        for (int i = 1; i < n; i++) for (int j = 0; j < n; j++) ret[i][j] += ret[i - 1][j];
  
        return ret;
    }
};

3.统计好子数组的数目

给你一个整数数组 nums 和一个整数 k ，请你返回 nums 中 好 子数组的数目。

一个子数组 arr 如果有 至少 k 对下标 (i, j) 满足 i < j 且 arr[i] == arr[j] ，那么称它是一个 好 子数组。

子数组 是原数组中一段连续 非空 的元素序列。

示例 1：

输入：nums = [1,1,1,1,1], k = 10
输出：1
解释：唯一的好子数组是这个数组本身。


class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ret = 0;
        
        int l = 0;
        int n = nums.size();
        
        map<int, int> mp;
        long long tmp = 0;
        for (int r = 0; r < n; r++) {
           // 配对数加上区间内元素的个数
            tmp += mp[nums[r]];
            mp[nums[r]]++;
           // 移动l之后，会减少区间内nums[l]个数-1的配对数，因此判断条件为tmp - (mp[nums[l]] - 1)
            while (l < r && tmp - mp[nums[l]] + 1 >= k) {
                tmp -= mp[nums[l]] - 1;
                mp[nums[l++]]--;            
            }
            if (tmp >= k)
                ret += l+1;
        }
        return ret;
    }
};











