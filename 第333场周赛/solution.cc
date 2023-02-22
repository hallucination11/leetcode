#1.合并两个二维数组 - 求和法

给你两个 二维 整数数组 nums1 和 nums2.

nums1[i] = [idi, vali] 表示编号为 idi 的数字对应的值等于 vali 。
nums2[i] = [idi, vali] 表示编号为 idi 的数字对应的值等于 vali 。
每个数组都包含 互不相同 的 id ，并按 id 以 递增 顺序排列。

请你将两个数组合并为一个按 id 以递增顺序排列的数组，并符合下述条件：

只有在两个数组中至少出现过一次的 id 才能包含在结果数组内。
每个 id 在结果数组中 只能出现一次 ，并且其对应的值等于两个数组中该 id 所对应的值求和。如果某个数组中不存在该 id ，则认为其对应的值等于 0 。
返回结果数组。返回的数组需要按 id 以递增顺序排列。

 
示例 1：

输入：nums1 = [[1,2],[2,3],[4,5]], nums2 = [[1,4],[3,2],[4,1]]
输出：[[1,6],[2,3],[3,2],[4,6]]
解释：结果数组中包含以下元素：
- id = 1 ，对应的值等于 2 + 4 = 6 。
- id = 2 ，对应的值等于 3 。
- id = 3 ，对应的值等于 2 。
- id = 4 ，对应的值等于5 + 1 = 6 。

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> result;
        unordered_map<int,int>mp;
        for (auto v : nums1) {
            mp[v[0]] = v[1];
        }
        for (auto vec : nums2) {
            if (mp[vec[0]] == 0) {
                result.push_back(vec);
            }
            else {
                int tmp = vec[1] + mp[vec[0]];
                result.push_back(vector<int>{vec[0], tmp});
                mp[vec[0]] = -1;
            }
        }

        for( auto [mpp,cnt] : mp ){
            if( cnt > 0 ){
                result.push_back(vector<int>{mpp,cnt});
            }
        }

        sort(result.begin(), result.end());
        return result;
    }
};

# 2.将整数减少到零需要的最少操作数
给你一个正整数 n ，你可以执行下述操作 任意 次：

n 加上或减去 2 的某个 幂
返回使 n 等于 0 需要执行的 最少 操作数。

如果 x == 2的i次幂 且其中 i >= 0 ，则数字 x 是 2 的幂。

示例 1：

输入：n = 39
输出：3
解释：我们可以执行下述操作：
- n 加上 (2的0次幂 = 1) ，得到 n = 40 。
- n 减去 (2的3次幂 = 8) ，得到 n = 32 。
- n 减去 (2的5次幂 = 32) ，得到 n = 0 。
可以证明使 n 等于 0 需要执行的最少操作数是 3 。

class Solution {
public:
    int minOperations(int n) {
        int count = 0;
        while (n != 0) {
            int p = round(log2(n));
            n = abs(n - pow(2, n));
            count ++;
        }
        return count;
    }
};









