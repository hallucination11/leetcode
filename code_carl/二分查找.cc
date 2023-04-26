--二分查找(区间左闭右闭)
class Solution {
	public:
		int search(vector<int>& nums, int target) {
			int right = nums.size() - 1, left = 0;
			while(left <= right) {
				int middle = left + (right - left) / 2;
				if (nums[middle] > target) {
					right = middle - 1;
				} else if (nums[middle] < target) {
					left = middle + 1;
				} else return middle;
			}
			return -1;
		}
};
--二分查找(左闭右开)
class Solution {
	public:
		int search(vector<int>& nums, int target) {
			int right = nums.size(), left = 0;
			while (left < right) {
				int middle = left + (right - left) / 2;
				if (nums[middle] > target) {
					right = middle;
				} else if (nums[middle] < target) {
					left = middle + 1;
				} else {
					return middle
				}
			}
			return -1;
		}
};

1.搜索插入位置
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
输入: [1,3,5,6], 7
输出: 4
暴力解
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    	for (int i = 0 ; i < nums.size() ; i ++) {
    		if (nums[0] > target) {
    			return 0;
    		}
    		if (nums[i] == target) {
    			return i;
    		}
    		if (i < (nums.size() - 1) & target > nums[i] & target < nums[i + 1]) {
    			return i + 1;
    		}
    	}
    	return nums.size();
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    	for (int i = 0 ; i < nums.size() ; i ++) {
    		if (nums[i] >= target) { // 一旦发现大于或者等于target的num[i]，那么i就是我们要的结果
                return i;
            }
    	}
    	return nums.size();
    }
};

二分法
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		int left = 0 , right = nums.size() - 1;
		while(left <= right) {
				int middle = left + (right - left) / 2;
				if (nums[middle] > target) {
					right = middle - 1;
				} else if (nums[middle] < target) {
					left = middle + 1;
				} else return middle;
		}
		return right + 1;   	
    }
};

2.在排序数组中查找元素的第一个和最后一个位置

给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

示例 1：

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	int leftBorder = getLeftBorder(nums, target);
        int rightBorder = getRightBorder(nums, target);

        if (leftBorder == -2 || rightBorder == -2) return {-1, -1};

        if (rightBorder - leftBorder > 1) return {leftBorder + 1, rightBorder - 1};

        return {-1, -1};
    }

    int getRightBorder(vector<int>& nums, int target) {
    	int right = nums.size() - 1, left = 0, rightBorder = -2;
    	while (left <= right) {
    		int middle = left + ((right - left) / 2);
    		if (nums[middle] > target) {
    			right = middle - 1;
    		} else {
    			left = middle + 1;
    			rightBorder = left;
    		} 
    	}
    	return rightBorder;
    }

    int getLeftBorder(vector<int>& nums, int target) {
    	int right = nums.size() - 1, left = 0, leftBorder = -2;
    	while (left <= right) {
    		int middle = left + ((right - left) / 2);
    		if (nums[middle] >= target) {
    			right = middle - 1;
    			leftBorder = right;
    		} else {
    			left = middle + 1;
    		} 
    	}
    	return leftBorder;
    }
};



--移除元素

给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并原地修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

示例 1: 给定 nums = [3,2,2,3], val = 3, 函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。 你不需要考虑数组中超出新长度后面的元素。

示例 2: 给定 nums = [0,1,2,2,3,0,4,2], val = 2, 函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。


暴力解法
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    	int size = nums.size();
    	for (int i = 0 ; i < nums.size() ; i ++) {
    		if (nums[i] == val) {
    			for (int j = i ; j < nums.size() - 1 ; j ++) {
    				nums[j] = nums[j + 1]
    			}
    		}
    		i --;
    		size ++;
    	}
    	return size;
    }
};


--双指针
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    	int slowIndex = 0;
    	for (int fastIndex = 0 ; fastIndex < nums.size() ; fastIndex ++) {
    		if (nums[fastIndex] != val) {
    			nums[slowIndex++] = nums[fastIndex];
    		}
    		
    	}
    	return size;
    }
};
注意这些实现方法并没有改变元素的相对位置


4.有序数组的平方

给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

示例 1： 输入：nums = [-4,-1,0,3,10] 输出：[0,1,9,16,100] 解释：平方后，数组变为 [16,1,0,9,100]，排序后，数组变为 [0,1,9,16,100]

示例 2： 输入：nums = [-7,-3,2,3,11] 输出：[4,9,9,49,121]

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
    	int k = A.size() - 1;
    	vector<int> res(A.size(), 0);
    	for (int i = 0, j = A.size() - 1 ; i <= j ; ) {
    		if (A[i] * A[i] >= A[j] * A[j]) {
    			res[k--] = A[i] * A[i];
    			i ++;
    		} else {
    			res[k--] = A[j] * A[j];
    			j --
    		}
    	}
    	return res;
    }
}；


5.长度最小的子数组(滑动窗口)

给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。

示例：

输入：s = 7, nums = [2,3,1,2,4,3] 输出：2 解释：子数组 [4,3] 是该条件下的长度最小的子数组。

提示：

1 <= target <= 10^9
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^5


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
    	int result = INT32_MAX;
    	int sum = 0;
    	for (int i = 0 ; i < nums.size() - 1; i ++) {
    		sum = 0;
    		for (int j = i ; j < nums.size() - 1 ; j ++) {
    			sum += nums[j];
    			if (sum >= s) {
    				subLength = j - i + 1;
    				result = result < subLength ? result : subLength;
    				break;
    			}
    		}
    	}
    	return result == INT32_MAX ? 0 : result;
    }
};

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
    	int result = INT32_MAX;
    	int sum = 0;
    	int subLength = 0;
    	int i = 0;
    	for (int j = 0 ; j < nums.size() - 1; j ++) {
    		sum += nums[j];
    		while (sum >= s) {
    			subLength = j - i + 1;
    			result = result < subLength ? result : subLength;
    			sum -= nums[i++]; 
    		}

    	}
    	return result == INT32_MAX ? 0 : result;
    }
};


6.螺旋矩阵II 

给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3 输出: [ [ 1, 2, 3 ], [ 8, 9, 4 ], [ 7, 6, 5 ] ]

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    	vector<vector<int>> res(n, vector<int>(n, 0)); // 使用vector定义一个二维数组
        int startx = 0, starty = 0; // 定义每循环一个圈的起始位置
        int loop = n / 2; // 每个圈循环几次，例如n为奇数3，那么loop = 1 只是循环一圈，矩阵中间的值需要单独处理
        int mid = n / 2; // 矩阵中间的位置，例如：n为3， 中间的位置就是(1，1)，n为5，中间位置为(2, 2)
        int count = 1; // 用来给矩阵中每一个空格赋值
        int offset = 1; // 需要控制每一条边遍历的长度，每次循环右边界收缩一位
        int i,j;
        while (loop --) {
            i = startx;
            j = starty;

            // 下面开始的四个for就是模拟转了一圈
            // 模拟填充上行从左到右(左闭右开)
            for (j = starty; j < n - offset; j++) {
                res[startx][j] = count++;
            }
            // 模拟填充右列从上到下(左闭右开)
            for (i = startx; i < n - offset; i++) {
                res[i][j] = count++;
            }
            // 模拟填充下行从右到左(左闭右开)
            for (; j > starty; j--) {
                res[i][j] = count++;
            }
            // 模拟填充左列从下到上(左闭右开)
            for (; i > startx; i--) {
                res[i][j] = count++;
            }

            // 第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
            startx++;
            starty++;

            // offset 控制每一圈里每一条边遍历的长度
            offset += 1;
        }

        // 如果n为奇数的话，需要单独给矩阵最中间的位置赋值
        if (n % 2) {
            res[mid][mid] = count;
        }
        return res;
    }
};




