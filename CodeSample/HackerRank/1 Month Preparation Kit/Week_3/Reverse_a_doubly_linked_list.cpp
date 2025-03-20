#include<iostream>

using namespace std;

struct DoublyLinkedListNode {
    int data;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* prev;
};

DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    if (llist->next == nullptr) {
        llist->prev = nullptr;
        return llist;
    } else {
        DoublyLinkedListNode* root_node = reverse(llist->next);
        DoublyLinkedListNode* next_node = llist->next;
        next_node->next = llist;
        llist->prev = next_node;
        llist->next = nullptr;
        return root_node;
    }
}

int main() {
    DoublyLinkedListNode* root = new DoublyLinkedListNode{1,nullptr,nullptr};
    DoublyLinkedListNode* current = root;
    for (int i = 2; i<7; i++) {
        DoublyLinkedListNode* new_node = new DoublyLinkedListNode{i,nullptr,nullptr};
        current->next = new_node;
        new_node->prev = current;
        current = new_node;
    }

    DoublyLinkedListNode* answer = reverse(root);

    cout << answer->data;

    while (answer->next != nullptr) {
        answer = answer->next;
        cout << " " << answer->data;
    }

    cout << endl;
}