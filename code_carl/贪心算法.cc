1.分发饼干

假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。

对每个孩子 i，都有一个胃口值  g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸 s[j] 。如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。

示例  1:

输入: g = [1,2,3], s = [1,1]
输出: 1 解释:你有三个孩子和两块小饼干，3 个孩子的胃口值分别是：1,2,3。虽然你有两块小饼干，由于他们的尺寸都是 1，你只能让胃口值是 1 的孩子满足。所以你应该输出 1。

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
    	sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = s.size() - 1; // 饼干数组的下标
        int result = 0;
        for (int i = g.size() - 1; i >=0 ; i --) {
        	if (g[i] <= s[index] && index >= 0) {
        		result ++;
        		index --;
        	}
        }
        return result;
    }
};

2.摆动序列

如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为摆动序列。第一个差（如果存在的话）可能是正数或负数。少于两个元素的序列也是摆动序列。

例如， [1,7,4,9,2,5] 是一个摆动序列，因为差值 (6,-3,5,-7,3)  是正负交替出现的。相反, [1,4,7,2,5]  和  [1,7,4,5,5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。

给定一个整数序列，返回作为摆动序列的最长子序列的长度。 通过从原始序列中删除一些（也可以不删除）元素来获得子序列，剩下的元素保持其原始顺序。

示例 1:

输入: [1,7,4,9,2,5]
输出: 6
解释: 整个序列均为摆动序列。
示例 2:

输入: [1,17,5,10,13,15,10,5,16,8]
输出: 7
解释: 这个序列包含几个长度为 7 摆动序列，其中一个可为[1,17,10,13,10,16,8]。
示例 3:

输入: [1,2,3,4,5,6,7,8,9]
输出: 2


class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int curDiff = 0; // 当前一对差值
        int preDiff = 0; // 前一对差值
        int result = 1;  // 记录峰值个数，序列默认序列最右边有一个峰值
        for (int i = 0; i < nums.size() - 1; i++) {
            curDiff = nums[i + 1] - nums[i];
            // 出现峰值
            if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0)) {
                result++;
                preDiff = curDiff; // 注意这里，只在摆动变化的时候更新prediff
            }
        }
        return result;
    }
};

3.最大子序和

给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释:  连续子数组  [4,-1,2,1] 的和最大，为  6。

暴力解法

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	int result = INT32_MIN;
        int count = 0;
        for (int i = 0 ; i < nums.size() ; i ++) {
        	int count = 0;
        	for (int j = i ; j < nums.size() ; j ++) {
        		count += nums[j];
        		result = count > result ? count : result;
        	}
        }
        return result;
    }
};

贪心

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	int result = INT32_MIN;
        int count = 0;
        for (int i = 0 ; i < nums.size() ; i ++) {
        	count += nums[i];
        	if (count > result) {
        		result = count;
        	} 

        	if (count < 0) {
        		count = 0;	
        	}
        }
        return result;
    }
};

6.买卖股票的最佳时机 II

给定一个数组，它的第  i 个元素是一支给定股票第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）

示例 1:

输入: [7,1,5,3,6,4]
输出: 7
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4。随后，
在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。

示例 2:

输入: [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int result = 0;
    	for (int i = 1 ; i < prices.size() ; i ++) {
    		result += max((prices[i] - prices[i - 1]), 0)
    	}
    	return result;
    }
};

7.跳跃游戏 

给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。

示例  1:

输入: [2,3,1,1,4]
输出: true
解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。

class Solution {
public:
    bool canJump(vector<int>& nums) {
    	int cover = 0;
    	if (nums.size() == 1) return true
    	for (int i = 0 ; i <= cover ; i ++) {
    		cover += max(i + nums[i], cover);
    		if (cover >= nums.size() - 1) return true;
    	}
    }
};


8.跳跃游戏 II

给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。从下标为 0 跳到下标为 1 的位置，跳  1  步，然后跳  3  步到达数组的最后一个位置。
说明: 假设你总是可以到达数组的最后一个位置。

class Solution {
public:
    int jump(vector<int>& nums) {
    	if (nums.size() == 1) return 0;
        int curDistance = 0;    // 当前覆盖最远距离下标
        int ans = 0;            // 记录走的最大步数
        int nextDistance = 0;   // 下一步覆盖最远距离下标

        for (int i = 0 ; i < nums.size() ; i ++) {
        	nextDistance = max(i + nums[i], nextDistance);
        	if (i == curDistance) {
        		ans ++;
        		curDistance = nextDistance;
        		if (nextDistance >= nums.size() - 1) break;
        	}
        }
        return ans;
    }
};


9.K次取反后最大化的数组和

给定一个整数数组 A，我们只能用以下方法修改该数组：我们选择某个索引 i 并将 A[i] 替换为 -A[i]，然后总共重复这个过程 K 次。（我们可以多次选择同一个索引 i。）

以这种方式修改数组后，返回数组可能的最大和。

示例 1：

输入：A = [4,2,3], K = 1
输出：5
解释：选择索引 (1,) ，然后 A 变为 [4,-2,3]。

示例 3：

输入：A = [2,-3,-1,5,-4], K = 2
输出：13
解释：选择索引 (1, 4) ，然后 A 变为 [2,3,-1,5,4]。

class Solution {
static cmp(int a, int b) {
	return abs(a) > abs(b);
}

public:
	int largestSumAfterKNegations(vector<int>& A, int K) {
		sort(A.begin(), A.end(), cmp);
		for (int i = 0 ; i < A.size() ; i ++) {
			if (A[i] < 0 && k > 0) {
				A[i] = -A[i];
				k --;
			}
		}
		if (k % 2 == 1) {
			A[A.size() - 1] *= -1;
		}
		int result = 0;
		for (int a : A) {
			result += a;
		}

		return result;
	}
};



11.加油站

在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。

你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。

如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。

说明:

如果题目有解，该答案即为唯一答案。
输入数组均为非空数组，且长度相同。
输入数组中的元素均为非负数。
示例 1: 输入:

gas = [1,2,3,4,5]
cost = [3,4,5,1,2]
输出: 3 解释:

从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
因此，3 可为起始索引。


暴力方法

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    	for (int i = 0 ; i < cost.size() ; i ++) {
    		int rest = gas[i] - cost[i];
    		int index = (i + 1) % cost.size();
    		while (rest > 0 && index != i) {
    			rest += gas[i] - cost[i];
    			index = (i + 1) % cost.size();
    		}
    		if (rest >= 0 && index == i) return i
    	}
    	return -1;
    }
};


方法一

直接从全局进行贪心选择，情况如下：

情况一：如果gas的总和小于cost总和，那么无论从哪里出发，一定是跑不了一圈的

情况二：rest[i] = gas[i]-cost[i]为一天剩下的油，i从0开始计算累加到最后一站，如果累加没有出现负数，说明从0出发，油就没有断过，那么0就是起点。

情况三：如果累加的最小值是负数，汽车就要从非0节点出发，从后向前，看哪个节点能把这个负数填平，能把这个负数填平的节点就是出发节点

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    	int curSum = 0;
    	int min = INT_MAX;

    	for (int i = 0 ; i < cost.size()i ++) {
    		int rest = gas[i] - cost[i];

    		curSum += rest;

    		if (curSum < min) {
    			min = curSum;
    		}
    	}

    	if (curSum < 0) return -1;
    	if (min >= 0) return 0;

    	for (int i = cost.size() - 1 ; i >= 0 ; i --) {
    		int rest = gas[i] - cost[i];
    		min += rest;
    		if (min >= 0) return i; 
    	} 

    	return -1;

    }
};


贪心算法（方法二）

可以换一个思路，首先如果总油量减去总消耗大于等于零那么一定可以跑完一圈，说明 各个站点的加油站 剩油量rest[i]相加一定是大于等于零的。

每个加油站的剩余量rest[i]为gas[i] - cost[i]。

i从0开始累加rest[i]，和记为curSum，一旦curSum小于零，说明[0, i]区间都不能作为起始位置，因为这个区间选择任何一个位置作为起点，到i这里都会断油，

那么起始位置从i+1算起，再从0计算curSum。


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    	int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
        	curSum += gas[i] - cost[-];
        	totalSum += gas[i] - cost[-];

        	if (curSum < 0) {
        		i = i + 1;
        		curSum = 0;
        	}
        }
        if (totalSum < 0) return -1;
    }
};



12.老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。

你需要按照以下要求，帮助老师给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
相邻的孩子中，评分高的孩子必须获得更多的糖果。
那么这样下来，老师至少需要准备多少颗糖果呢？

示例 1:

输入: [1,0,2]
输出: 5
解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candyVec(ratings.size(), 1);
        for (int i = 1 ; i < ratings.size() ; i ++) {
            if (ratings[i] > ratings[i - 1]) candyVec[i] = candyVec[i] + 1;
        }

        for (int i = ratings.size() - 2 ; i >= 0 ; i --) {
            if (ratings[i] > ratings[i + 1] ) {
                candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
            }
        }
        
        int result = 0;
        for (int i = 0; i < candyVec.size(); i++) result += candyVec[i];
        return result;
    }
};