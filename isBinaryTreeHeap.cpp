/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
    public:
    int countNode(struct Node* root){
        //base case
        if(root == NULL)
            return 0;
            
        int ans= 1 + countNode(root->left) + countNode(root->right);
    
        return ans;
    }
    
    bool isCBT(struct Node* root,int index,int count){
        if(root==NULL){
            return true;
        }
        
        if(index >= count){
            return false;
        }
        else {
            bool left=isCBT(root->left,2*index+1,count);
            bool right=isCBT(root->right,2*index+2,count);
            return (left && right);
        }
    }
    
    bool isMaxOrder(struct Node* root){
     //leaf node
     if(root->left == NULL && root->right == NULL){
         return true;
     }
     if(root->right==NULL){
         return (root->data > root->left->data);
     }
     else {
         bool left=isMaxOrder(root->left);
         bool right=isMaxOrder(root->right);
         
         if(left && right && (root->data > root->left->data)  && (root->data > root->right->data)){
             return true;
         }
         else 
         return false;
     }
    }
    
    bool isHeap(Node* tree) {
        int index=0;
        int totalCount=countNode(tree);
        if(isCBT(tree,index,totalCount) && isMaxOrder(tree)){
            return true;
        }
        else 
        return false;
    }
};
