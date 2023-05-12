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


4.有效的括号

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。
示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true



class Solution {
public:
    bool isValid(string s) {
    	if (s.size() % 2 != 0) return false;
    	stack<char> st;
    	for (int i = 0 ; i < s.size() ; i ++) {
    		if (s[i] == '(') st.push('(');
    		else if (s[i] == '{') st.push('{');
    		else if (s[i] == '[') st.push('[');
    		else if (st.empty() || s[i] != st.top()) return false;
    		else st.pop();
    	}
    	return st.empty();
    }
};


5.删除字符串中的所有相邻重复项

给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。

在 S 上反复执行重复项删除操作，直到无法继续删除。

在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

示例：

输入："abbaca"
输出："ca"
解释：例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
提示：

1 <= S.length <= 20000
S 仅由小写英文字母组成。

class Solution {
public:
    string removeDuplicates(string S) {
    	stack<int> st;
  
    	for (int i = 1 ; i < s.szie() ; i ++) {
    		if (st.empty() || s[i] != st.top()) {
    			st.pust(s[i]);
    		} else st.pop();
    	}

    	string result = "";

    	while (!st.empty()){
    		result += st.top();
    		st.pop();
    	}

    	reverse(result.begin(), result.end());

    	return result;
    }
};

6.逆波兰表达式求值

根据 逆波兰表示法，求表达式的值。

有效的运算符包括 + ,  - ,  * ,  / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

说明：

整数除法只保留整数部分。 给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

示例 1：

输入: ["2", "1", "+", "3", " * "]
输出: 9
解释: 该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
示例 2：

输入: ["4", "13", "5", "/", "+"]
输出: 6
解释: 该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
示例 3：

输入: ["10", "6", "9", "3", "+", "-11", " * ", "/", " * ", "17", "+", "5", "+"]

输出: 22

解释:该算式转化为常见的中缀算术表达式为：

((10 * (6 / ((9 + 3) * -11))) + 17) + 5       
= ((10 * (6 / (12 * -11))) + 17) + 5       
= ((10 * (6 / -132)) + 17) + 5     
= ((10 * 0) + 17) + 5     
= (0 + 17) + 5    
= 17 + 5    
= 22    

逆波兰表达式：是一种后缀表达式，所谓后缀就是指运算符写在后面。

平常使用的算式则是一种中缀表达式，如 ( 1 + 2 ) * ( 3 + 4 ) 。

该算式的逆波兰表达式写法为 ( ( 1 2 + ) ( 3 4 + ) * ) 。

逆波兰表达式主要有以下两个优点：

去掉括号后表达式无歧义，上式即便写成 1 2 + 3 4 + * 也可以依据次序计算出正确结果。

适合用栈操作运算：遇到数字则入栈；遇到运算符则取出栈顶两个数字进行计算，并将结果压入栈中

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    	
    }
};