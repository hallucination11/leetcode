2.移除链表元素

题意：删除链表中等于给定值 val 的所有节点。

示例 1： 输入：head = [1,2,6,3,4,5,6], val = 6 输出：[1,2,3,4,5]

示例 2： 输入：head = [], val = 1 输出：[]

示例 3： 输入：head = [7,7,7,7], val = 7 输出：[]

-- 直接使用原来的链表来进行移除节点操作：
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    	# 删除头结点
    	while (head != NULL && head->val == val) {
    		ListNode* cur = head;
    		head = head->next;
    		del cur;
    	}

    	ListNode* cur = head;
    	# 删除非头节点
    	while (cur != NULL && cur->next != NULL) {
    		if (cur->next->next == val) {
    			ListNode* tmp = cur->next;
    			cur->next = cur->next->next;
    			del tmp;
    		} else {
    			cur = cur->next;
    		}
    	}
    	return head;
    }
};

-- 设置一个虚拟头结点在进行移除节点操作：
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    	ListNode* dummyHead = new ListNode(0);
    	dummyHead->next = head;
    	ListNode* cur = dummyHead;
    	while (cur->next != NULL) {
    		if (cur->next->val == val) {
    			ListNode* tmp = cur->next;
    			cur->next = cur->next->next;
    			del tmp;
    		} else {
    			cur = cur->next;
    		}
    	head = dummyHead->next;
    	del dummyHead;
    	return head;
    	}
    }
};