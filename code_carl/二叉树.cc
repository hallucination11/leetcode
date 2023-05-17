2.1
递归法
前序遍历

class Solution {
public:
    void traversal(TreeNode* cur, vector<int>& vec) {
    	if (cur == NULL) {
    		return;
    	}

    	vec.push_back(cur->val);
    	traversal(cur->left, vec);
    	traversal(cur->right, vec);
    }

    vector<int> preorderTraversal(TreeNode* root) {
    	vector<int> result;
    	traversal(root, result);
    	return result;
    }
};

中序遍历

class Solution {
public:
    void traversal(TreeNode* cur, vector<int>& vec) {
    	if (cur == NULL) {
    		return;
    	}

    	traversal(cur->left, vec);
    	vec.push_back(cur->val);
    	traversal(cur->right, vec);
    }
};


后序遍历

class Solution {
public:
    void traversal(TreeNode* cur, vector<int>& vec) {
    	if (cur == NULL) {
    		return;
    	}

    	traversal(cur->left, vec);
    	traversal(cur->right, vec);
    	vec.push_back(cur->val);  	
    }
};



迭代法
中序遍历

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root != NULL) st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop(); // 将该节点弹出，避免重复操作，下面再将右中左节点添加到栈中
                if (node->right) st.push(node->right);  // 添加右节点（空节点不入栈）

                st.push(node);                          // 添加中节点
                st.push(NULL); // 中节点访问过，但是还没有处理，加入空节点做为标记。

                if (node->left) st.push(node->left);    // 添加左节点（空节点不入栈）
            } else { // 只有遇到空节点的时候，才将下一个节点放进结果集
                st.pop();           // 将空节点弹出
                node = st.top();    // 重新取出栈中元素
                st.pop();
                result.push_back(node->val); // 加入到结果集
            }
        }
        return result;
    }
};

5.二叉树的层序遍历

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) queue.push(root);
        vector<vector<int>> result;
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;

            for (int i = 0 ; i < size ; i ++) {
                TreeNode* node = que.front();
                vec.push_back(node->val);
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right); 
            }
            result.push_back(vec);
    }
    return result;
};

6.翻转二叉树

翻转一棵二叉树
递归法
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root; 
    }
};

迭代法

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            swap(root->left, root->right);
            if (root->right) st.push(node->right);   
            if(node->left) st.push(node->left);  
        }
        
        return root; 
    }
};



































