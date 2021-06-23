#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class LinkedList{
    private:
        Node *head, *tail;
    public:
        LinkedList(){
            head = NULL;
            tail = NULL;
        }

        void PushFront(int data){
            Node *a = new Node;
            a -> data = data;
            a -> next = head;
            head = a;
            if (tail == NULL){
                tail = head;
            }
        }

        void PushBack(int data){
            Node *a = new Node;
            a -> data = data;
            a -> next = NULL;
            if (tail == NULL){
                head = tail = a;
            }
            else{
                tail -> next = a;
                tail = a;
            }
        }

        void print(){
            Node *a = new Node;
            a = head;
            while(a != NULL){
                cout << a -> data << ' ';
                a = a -> next;
            }
        }
};


int main(){
    LinkedList l;
    l.PushFront(2);
    l.PushFront(3);
    l.PushFront(4);
    l.PushFront(0);
    l.PushBack(1);
    l.PushBack(6);
    l.print();

    return 0;


}