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

int main() {
    SinglyLinkedListNode* root = new SinglyLinkedListNode{1,nullptr};
    SinglyLinkedListNode* current = root;
    for (int i = 2; i<6; i++) {
        SinglyLinkedListNode* new_node = new SinglyLinkedListNode{i,nullptr};
        current->next = new_node;
        current = new_node;
    }

    SinglyLinkedListNode* answer = reverse(root);

    cout << answer->data;

    while (answer->next != nullptr) {
        answer = answer->next;
        cout << " " << answer->data;
    }

    cout << endl;
}