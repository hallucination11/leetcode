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

3.设计链表
在链表类中实现这些功能：

get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。

4.反转链表

题意：反转一个单链表。

示例: 输入: 1->2->3->4->5->NULL 输出: 5->4->3->2->1->NULL

--双指针
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = NULL;
        while (cur != NULL) {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};


--递归法
class Solution {
public:
    ListNode* reverse(ListNode* pre, ListNode* cur) {
        if (cur == NULL) return pre;
        ListNode* temp = cur->next;
        cur->next = pre;
        return reverse(cur, temp);

    }


    ListNode* reverseList(ListNode* head) {
        return reverse(NULL, head);
    }
};


5.两两交换链表中的节点

给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyNode = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while(cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tmp = cur->Next;
            ListNode* tmp1 = cur->next->next->next;
            cur->next = cur->next->next;
            cur->next->next = tmp;
            cur->next->next->next = tmp1;
            cur = cur->next->next;
        }
        return dummyHead->next;

    }
};


6.删除链表的倒数第N个节点

给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

进阶：你能尝试使用一趟扫描实现吗？

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;

        while (fast != null && n--) {
            fast = fast->next;
        }

        fast = fast->next;

        while (fast != null) {
            fast = fast->next;
            slow = slow->next;
        } 

        slow->next = slow->next->next;
        
        return dummyHead->next;
    }
};