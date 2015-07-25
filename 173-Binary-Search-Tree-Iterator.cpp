/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        cur_ = findMostLeft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return  cur_ != NULL;
    }

    /** @return the next smallest number */
    int next() {
        if (cur_ == NULL) return 0;
        int val = cur_->val;
        if (cur_->right != NULL)
            cur_ = findMostLeft(cur_->right);
        else{
            if (!stack_.empty()){
                cur_ = stack_.top();
                stack_.pop();
            } else
                cur_ = NULL;
        }
        return val;
    }

    TreeNode* findMostLeft(TreeNode* root){
        if (root == NULL) return NULL;
        while (root->left != NULL){
            stack_.push(root);
            root = root->left; 
        }
        return root;
    }
    
private:
    stack<TreeNode*> stack_;
    stack<bool> is_right_;
    TreeNode* cur_;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
