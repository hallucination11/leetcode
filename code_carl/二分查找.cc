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




