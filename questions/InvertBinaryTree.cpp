#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};


node* insert(int k, node *R){
    if (R == NULL){
        return new node(k);
    }

    queue<node*> q;
    q.push(R);

    while (!q.empty()){
        node *a = q.front();
        q.pop();

        if (a -> left != NULL){
            q.push(a -> left);
        }

        else {
            a -> left = new node(k);
            return R;
        }

        if (a -> right != NULL){
            q.push(a -> right);
        }

        else {
            a -> right = new node(k);
            return R;
        }
    }
    return R;
}

void Swap(node *a){
    node *temp;
    temp = a -> left;
    a -> left = a -> right;
    a -> right = temp;
}


void bfs(node *R){
    queue<node*> q;
    q.push(R);
    while (!q.empty()){
        node *a = q.front();
        q.pop();
        
        if (a == NULL){
            continue;
        }

        Swap(a);
        q.push(a -> left);
        q.push(a -> right);
    }

}

void inorder(node *R){
    if (R == NULL){
        return;
    }
    inorder(R -> left);
    cout << R -> data << ' ';
    inorder(R -> right);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    node *R = NULL;
    R = insert(1, R);
    insert(2, R);
    insert(3, R);
    insert(4, R);
    insert(5, R);
    insert(6, R);
    insert(7, R);
    //inorder(R);
    bfs(R);
    inorder(R);
}
