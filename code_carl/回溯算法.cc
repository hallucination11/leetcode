2.组合

给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例: 输入: n = 4, k = 2 输出: [ [2,4], [3,4], [2,3], [1,2], [1,3], [1,4], ]

class Solution {
	private:
		vector<vector<int>> result; // 存放符合条件结果的集合
    	vector<int> path; // 用来存放符合条件结果

    	void backtracking(int n, int k, int startIndex) {
    		if (path.size() == k) {
    			result.push_back(path);
    			return;
    		}
    		for (int i = startIndex; i <= n; i++) {
	            path.push_back(i); // 处理节点
	            backtracking(n, k, i + 1); // 递归
	            path.pop_back(); // 回溯，撤销处理的节点
        	} 
    	}


	public:
    vector<vector<int>> combine(int n, int k) {
    	result.clear();
    	path.clear();
    	backtracking(n, k, 1);
    	return result；
    }
};


4.组合总和III

找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。
示例 1: 输入: k = 3, n = 7 输出: [[1,2,4]]

示例 2: 输入: k = 3, n = 9 输出: [[1,2,6], [1,3,5], [2,3,4]]

class Solution {
	vector<vector<int>> result;
	vector<int> path;
	void backtracking(int targetSum, int k, int sum, int startIndex) {
		if (path.size() == k) {
            if (sum == targetSum) result.push_back(path);
            return; // 如果path.size() == k 但sum != targetSum 直接返回
        }

        for (int i = startIndex; i <= 9; i++) {
            sum += i; // 处理
            path.push_back(i); // 处理
            backtracking(targetSum, k, sum, i + 1); // 注意i+1调整startIndex
            sum -= i; // 回溯
            path.pop_back(); // 回溯
        }
	}

	public:
    vector<vector<int>> combinationSum3(int k, int n) {
    	result.clear();
    	path.clear();
    	backtracking(n, k, 0, 1);
        return result;
    }
};