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









