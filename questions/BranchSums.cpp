#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* Insert(int data, Node* R){
    if (R == NULL){
        Node *k = new Node(data);
        return k;
    }

    queue<Node*> q;
    q.push(R);

    while(!q.empty()){
        Node *a = q.front();
        q.pop();
        
        if (a -> left != NULL){
            q.push(a -> left);
        }
        else{
            a -> left = new Node(data);
            return R;
        }

        if (a -> right != NULL){
            q.push(a -> right);
        }
        else {
            a -> right = new Node(data);
            return R;
        }
    }
    return 0;
}

void Inorder(Node *R){
    if (R == NULL){
        return;
    }
    Inorder(R -> left);
    cout << R -> data << ' ';
    Inorder(R -> right);
}

void calBranchSums(Node *R, int sum){
    if (R == NULL){
        return;
    }
    
    int new_sum = sum + R -> data;

    if (R -> left == NULL && R -> right == NULL){
        cout << new_sum << ' ';
        return;
    }

    calBranchSums(R -> left, new_sum);
    calBranchSums(R -> right, new_sum);
}

void printL(Node* R){
    if (R == NULL){
        return;
    }
    cout << R -> data << ' ';
    printL(R -> left);
}

/*
vector<int> BranchSums(Node* R){
    vector<int> sums;
    calBranchSums(R, sums, 0);
    return sums;
}
*/
signed main(){
    Node *R = NULL;
    R = Insert(1, R);
    Insert(2, R);
    Insert(3, R);
    Insert(4, R);
    Insert(5, R);
    Insert(6, R);
    Insert(7, R);
    Insert(8, R);
    Insert(9, R);
    Insert(10, R);
    //printL(R);
    calBranchSums(R, 0);
    return 0;
}