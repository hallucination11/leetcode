1.用栈实现队列

使用栈实现队列的下列操作：

push(x) -- 将一个元素放入队列的尾部。
pop() -- 从队列首部移除元素。
peek() -- 返回队列首部的元素。
empty() -- 返回队列是否为空。

class MyQueue {
public:
	stack<int> stIn;
	stack<int> stOut;

	MyQueue() {

	}

	void push(x) {
		stIn.push(x);
	}

	int pop() {
		if (stOut.empty()) {
			while (!stIn.empty()) {
				stOut.push(stIn.top());
				stIn.pop();
			}
		}
		int result = stOut.top();
		stOut.pop();
		return result;
	}

	int peek() {
		int res = this->pop(); // 直接使用已有的pop函数
        stOut.push(res); // 因为pop函数弹出了元素res，所以再添加回去
        return res;
	}

	bool empty() {
        return stIn.empty() && stOut.empty();
    }
};


3.用队列实现栈

使用队列实现栈的下列操作：

push(x) -- 元素 x 入栈
pop() -- 移除栈顶元素
top() -- 获取栈顶元素
empty() -- 返回栈是否为空

class MyStack {
public:
	queue<int> que1;
    queue<int> que2; // 辅助队列，用来备份
    /** Initialize your data structure here. */
    MyStack() {

    }

    void push(int x) {
        que1.push(x);
    }

    int pop() {
    	int size = que1.size();
    	size --;
    	while (size--) {
    		que2.push(que1.front());
    		que1.pop();
    	}
    	int result = que1.front();
    	que1.pop();
    	que1 = que2;
    	while (!que2) {
    		que2.pop();
    	}
    	return result;
    }

    int top() {
        return que1.back();
    }

    bool empty() {
        return que1.empty();
    }

};










