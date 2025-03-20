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

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    if (position == 0) {
        SinglyLinkedListNode* root = new SinglyLinkedListNode{data, llist};
        return root;
    } else {
        int current = 0;
        int p = position;
        SinglyLinkedListNode* current_node = llist;
        while (p-1 != current) {
            current += 1;
            current_node = current_node->next;
        }

        SinglyLinkedListNode* new_node = new SinglyLinkedListNode{data, current_node->next};
        current_node->next = new_node;

        return llist;
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