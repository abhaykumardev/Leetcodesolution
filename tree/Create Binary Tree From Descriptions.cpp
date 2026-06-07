class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> child;

        for (auto &d : descriptions) {
            int parent = d[0];
            int ch = d[1];
            int isLeft = d[2];

            if (!mp.count(parent))
                mp[parent] = new TreeNode(parent);

            if (!mp.count(ch))
                mp[ch] = new TreeNode(ch);

            if (isLeft)
                mp[parent]->left = mp[ch];
            else
                mp[parent]->right = mp[ch];

            child.insert(ch);
        }

        for (auto &[val, node] : mp) {
            if (!child.count(val))
                return node;
        }

        return nullptr;
    }
};   

//leetcode  2196
