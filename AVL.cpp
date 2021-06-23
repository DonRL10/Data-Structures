#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    int height;
    node *left;
    node *right;
};

class AVL{
    public:
        int height(node *R){
            if (R == NULL){
                return 0;
            }
            return R -> height;
        }


        node* RightRotate(node *y){
            node *x = y -> left;
            node *x_rc = x -> right;

            x -> right = y;
            y -> left = x_rc;

            y -> height = max(height(y -> left), height(y -> right)) + 1;
            x -> height = max(height(x -> left), height(x -> right)) + 1;

            return x;
        }


        node* LeftRotate(node *z){
            node *y = z -> right;
            node *y_rc = y -> left;

            y -> left = z;
            z -> right = y_rc;

            y -> height = max(height(y -> left), height(y -> right)) + 1;
            z -> height = max(height(z -> left), height(z -> right)) + 1;

            return y;
        }

        int GetBalance(node *n){
            if(n == NULL){
                return 0;
            }
            return height(n -> left) - height(n -> right);
        }

        node* insert(node *R, int key){
            
            node *k = new node;
            k -> data = key;
            k -> height = 1;
            k -> left = NULL;
            k -> right = NULL;

            if (R == NULL){
                return k;
            }

            else if (R -> data > key){
                R -> left = insert(R -> left, key);
            }
            else { 
                R -> right = insert(R -> right, key);
            }
            
            R -> height = max(height(R -> right), height(R -> left)) + 1;

            int balance = GetBalance(R);

            if (balance > 1 && key < R -> left -> data){
                return RightRotate(R);
            }

            if (balance < -1 && key > R -> right -> data){
                return LeftRotate(R);
            }

            if (balance > 1 && key > R -> left -> data){
                R -> left = LeftRotate(R -> left);
                return RightRotate(R);
            }
            
            if (balance < -1 && key < R -> right -> data){
                R -> right = RightRotate(R -> right);
                return LeftRotate(R);
            }

            return R;

        }

        void preorder(node *R){
            if (R == NULL){
                return;
            }
            cout << R -> data << ' ';
            preorder(R -> left);
            preorder(R -> right);
        }
};

signed main(){
    AVL tr;
    node *R = NULL;

    R = tr.insert(R, 10);
    R = tr.insert(R, 20);
    R = tr.insert(R, 30);
    R = tr.insert(R, 40);
    R = tr.insert(R, 50);
    R = tr.insert(R, 25); 
    tr.preorder(R);
    return 0;
}