#include <iostream>
using namespace std;

class MyLinkedList {
private:
    struct Node {
        int val;
        Node* prev;
        Node* next;
        Node(int x) : val(x), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    MyLinkedList() {
        head = new Node(0); 
        tail = new Node(0); 
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* curr = head->next;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;

        Node* pred = head;
        for (int i = 0; i < index; i++) {
            pred = pred->next;
        }
        Node* succ = pred->next;

        Node* newNode = new Node(val);
        newNode->prev = pred;
        newNode->next = succ;
        pred->next = newNode;
        succ->prev = newNode;

        ++size;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        Node* curr = head->next;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        Node* pred = curr->prev;
        Node* succ = curr->next;

        pred->next = succ;
        succ->prev = pred;

        delete curr;
        size--;
    }

    ~MyLinkedList() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};
