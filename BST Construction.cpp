#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};


class BST{
    private:
        node *R;

        node* Insert(int n, node *R){
            if (R == NULL){
                R = new node;
                R -> data = n;
                R -> left = NULL;
                R -> right = NULL;
            }

            else if (R -> data > n){
                R -> left = Insert(n, R -> left);
            }

            else {
                R -> right = Insert(n, R -> right);
            }
            return R;
        }

        node* Find(int n, node *R){
            if (R -> data == n){
                return R;
            }
            else if (R -> data < n){
                Find(n , R -> right);
            }
            else {
                Find(n, R -> left);
            }
            return R;
        } 

        node* InorderSucc(node *R){
            node *curr = R;
            while (curr -> left != NULL){
                curr = curr -> left;
            }
            return curr;
        }

        node* Remove(int n, node *R){
            if (R -> data > n){
                R -> left = Remove(n, R -> left);
            }
            else if (R -> data < n){
                R -> right = Remove(n, R -> right);
            }
            else{
                if (R -> left == NULL){
                    node *a = R -> right;
                    free(R);
                    return a;
                }
                else if (R -> right == NULL){
                    node *a = R -> left;
                    free(R);
                    return a;
                }

                node *a = InorderSucc(R -> right);
                R -> data = a -> data;
                R -> right = Remove(a -> data, R -> right);
            }
            return R;
        }

        void Inorder(node *R){
            if (R == NULL){
                return;
            }
            Inorder(R -> left);
            cout << R -> data << ' ';
            Inorder(R -> right);
        }

    public:
        BST(){
            R = NULL;
        }

        void insert(int n){
            R = Insert(n, R);
        }

        void inorder(){
            Inorder(R);
            cout << endl;
        }

        void remove(int n){
            R = Remove(n, R);
        }

        void find(int n){
            R = Find(n, R);
        }
};

signed main(){
    BST bst;
    bst.insert(5);
    bst.insert(8);
    bst.insert(1);
    bst.insert(0);
    bst.insert(2);
    bst.inorder();
    bst.remove(1);
    bst.inorder();
    return 0;
}