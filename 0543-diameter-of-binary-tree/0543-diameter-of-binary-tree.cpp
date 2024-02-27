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
    int height(TreeNode* root,int & dia) {
        if(root==NULL) return 0;
        int lh=height(root->left,dia);
        int rh=height(root->right,dia);
        dia = max(dia,lh+rh);
        return 1+max(lh,rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
          //diameter of binary tree is distance between two nodes
          //for any node if i find the left height and i find the right height
          //and i add them up thats my length . and i have to return maximum length
           int dia=0;
           height(root,dia);
           return dia;
    }
};