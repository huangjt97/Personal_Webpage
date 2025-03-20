#include<iostream>
#include<vector>

using namespace std;

class SinglyLinkedListNode {
    private:
        int data;
        SinglyLinkedListNode* next;
    public:
        SinglyLinkedListNode() {
            data = 0;
            next = nullptr;
        }

        SinglyLinkedListNode(int d, SinglyLinkedListNode* n) {
            data = d;
            next = n;
        }

        void changeNext(SinglyLinkedListNode* n) {
            next = n;
        }

        int getData() {
            return data;
        }

        SinglyLinkedListNode* getNext() {
            return next;
        }
};


SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    if (llist->getNext() == nullptr) {
        return llist;
    } else {
        SinglyLinkedListNode* root_node = reverse(llist->getNext());
        SinglyLinkedListNode* next_node = llist->getNext();
        next_node->changeNext(llist);
        llist->changeNext(nullptr);
        return root_node;
    }
}

int main() {
    SinglyLinkedListNode* root = new SinglyLinkedListNode(1,nullptr);
    SinglyLinkedListNode* current = root;
    for (int i = 2; i<6; i++) {
        SinglyLinkedListNode* new_node = new SinglyLinkedListNode(i,nullptr);
        current->changeNext(new_node);
        current = new_node;
    }

    SinglyLinkedListNode* answer = reverse(root);

    cout << answer->getData();

    while (answer->getNext() != nullptr) {
        answer = answer->getNext();
        cout << " " << answer->getData();
    }

    cout << endl;

    return 0;

}
