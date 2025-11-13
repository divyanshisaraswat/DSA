/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    private:
    int height(Node* root) {
        // base case
        if(root==NULL){
            return -1;
        }
        
        int left=height(root->left);
        int right=height(root->right);
        
        return max(left,right) +1 ;
        
    }
    
  public:
    int diameter(Node* root) {
        // base case
        if(root == NULL){
            return 0;
        }
        
        int op1=diameter(root->left);
        int op2=diameter(root->right);
        int op3=height(root->left) + height(root->right) +2;
        
        return max(op1, max(op2,op3));
        
        
    }
};
