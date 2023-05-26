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

