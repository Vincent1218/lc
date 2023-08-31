// 102. Binary Tree Level Order Traversal

// DFS
vector<vector<int>> ret;

void buildVector(TreeNode *root, int depth)
{
    if(root == NULL) return;
    if(ret.size() == depth)
        ret.push_back(vector<int>());
    
    ret[depth].push_back(root->val);
    buildVector(root->left, depth + 1);
    buildVector(root->right, depth + 1);
}

vector<vector<int> > levelOrder(TreeNode *root) {
    buildVector(root, 0);
    return ret;
}

// BFS
vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> result;
    if(!root)
        return result;

    queue<TreeNode*> s;
    vector<int> level;
    queue<TreeNode*> nodes;
    s.push(root);
    while(!s.empty())
    {
        TreeNode* n = s.front();
        s.pop();
        level.push_back(n->val);
        if(n->left)
            nodes.push(n->left);
        if(n->right)
            nodes.push(n->right);

        if(s.empty())
        {
            s.swap(nodes);
            result.push_back(level);
            level.clear();
        }
    }
    
    return result;
}