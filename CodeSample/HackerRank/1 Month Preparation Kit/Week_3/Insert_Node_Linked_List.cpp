#include<iostream>

using namespace std;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    if (llist->next == nullptr) {
        return llist;
    } else {
        SinglyLinkedListNode* root_node = reverse(llist->next);
        SinglyLinkedListNode* next_node = llist->next;
        next_node->next = llist;
        llist->next = nullptr;
        return root_node;
    }
}

SinglyLinkedListNode* insertNode(SinglyLinkedListNode* llist, int data, int position, int current) {
    if (position-1 == current) {
        SinglyLinkedListNode* new_node = new SinglyLinkedListNode{data, llist->next};
        llist->next = new_node;
        return llist;
    } else {
        insertNode(llist->next, data, position, current+1);
        return llist;
    }
}
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    if (position == 0) {
        SinglyLinkedListNode* root = new SinglyLinkedListNode{data, llist};
        return root;
    } else {
        return insertNode(llist, data, position, 0);
    }
}

int main() {
    SinglyLinkedListNode* root = new SinglyLinkedListNode{1,nullptr};
    SinglyLinkedListNode* current = root;
    for (int i = 2; i<6; i++) {
        SinglyLinkedListNode* new_node = new SinglyLinkedListNode{i,nullptr};
        current->next = new_node;
        current = new_node;
    }


    SinglyLinkedListNode* answer = insertNodeAtPosition(root, 6, 3);

    cout << answer->data;

    while (answer->next != nullptr) {
        answer = answer->next;
        cout << " " << answer->data;
    }

    cout << endl;
}