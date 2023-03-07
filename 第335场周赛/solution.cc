#1.递枕头

n 个人站成一排，按从 1 到 n 编号。

最初，排在队首的第一个人拿着一个枕头。每秒钟，拿着枕头的人会将枕头传递给队伍中的下一个人。一旦枕头到达队首或队尾，传递方向就会改变，
队伍会继续沿相反方向传递枕头。

例如，当枕头到达第 n 个人时，TA 会将枕头传递给第 n - 1 个人，然后传递给第 n - 2 个人，依此类推。
给你两个正整数 n 和 time ，返回 time 秒后拿着枕头的人的编号。

示例 1：

输入：n = 4, time = 5
输出：2
解释：队伍中枕头的传递情况为：1 -> 2 -> 3 -> 4 -> 3 -> 2 。
5 秒后，枕头传递到第 2 个人手中。

class Solution {
public:
    int passThePillow(int n, int time) {
        int result = 0;
        int t = time / (n - 1), mod = time % (n - 1);
        if (t % 2 == 0) {
            result = mod + 1;
        } 
        else {
            result = n - mod;
        }
        return result;
    }
};

#2.二叉树中的第 K 大层和

给你一棵二叉树的根节点 root 和一个正整数 k 。

树中的 层和 是指 同一层 上节点值的总和。

返回树中第 k 大的层和（不一定不同）。如果树少于 k 层，则返回 -1 。

注意，如果两个节点与根节点的距离相同，则认为它们在同一层。

输入：root = [5,8,9,2,1,3,7,4,6], k = 2
输出：13
解释：树中每一层的层和分别是：
- Level 1: 5
- Level 2: 8 + 9 = 17
- Level 3: 2 + 1 + 3 + 7 = 13
- Level 4: 4 + 6 = 10
第 2 大的层和等于 13 。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* u, int l, map<int, long long>&mp) {
        mp[l] += u->val;
        if (u->left != nullptr) {
            dfs(u->left, l+1, mp);
        }
        if (u->right != nullptr) {
            dfs(u->right, l+1, mp);
        }
    }
    
    long long kthLargestLevelSum(TreeNode* root, int k) {
        map<int, long long> mp;
        dfs(root, 1, mp);
        if (mp.size() < k) return -1;
        vector<long long> vt;
        for (auto it: mp) {
            vt.push_back(it.second);
        }
        sort(vt.begin(), vt.end(), greater<>());
        return vt[k-1];
    }
};
