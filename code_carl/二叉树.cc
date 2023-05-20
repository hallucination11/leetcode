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
深度优先遍历
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


广度优先遍历

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0 ; i < size ; i ++) {
                TreeNode* node = que.front();
                que.pop();
                swap(node->left, node->right); // 节点处理
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return root;
    }
};


8.对称二叉树

class Solution {
public:
    bool compare(TreeNode* left, TreeNode* right) {
        if (left == NULL && right != NULL) return false;
        else if (left != NULL && right == NULL) return false;
        else if (left == NULL && right == NULL) return true;
        else if (left->val != right->val) return false;

        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left)

        return outside && inside;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return compare(root->left, root->right); 
    }
};


9.二叉树的最大深度

给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例： 给定二叉树 [3,9,20,null,null,15,7]，返回它的最大深度 3 。

class solution {
public:
    int maxdepth(treenode* root) {
        if (root == null) return 0;
        return 1 + max(maxdepth(root->left), maxdepth(root->right));
    }
};





























