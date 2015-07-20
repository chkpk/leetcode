/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    int countNodes(TreeNode* root) {
      if (root == NULL) return 0;
      int result = 1;
      return findLast(root, result, getH(root));
    }
    
    int findLast(TreeNode* root, int& result, int H) {
      if (root->left == NULL && root->right == NULL)
        return result;
      int Hr = getH(root->right);
      if (Hr + 1 == H){
        result = result * 2 + 1;
        return findLast(root->right, result, Hr);
      }else{
        result = result * 2;
        return findLast(root->left, result, H - 1);
      }
    }
    
    int getH(TreeNode* root){
      if (root == NULL) return 0;
      int result = 1;
      while (root->left != NULL){
        ++ result;
        root = root->left;
      }
      return result;
    }
};
