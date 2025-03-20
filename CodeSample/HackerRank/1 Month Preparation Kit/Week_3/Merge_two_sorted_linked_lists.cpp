#include<iostream>
#include<vector>
using namespace std;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    SinglyLinkedListNode* current_1 = head1;
    SinglyLinkedListNode* current_2 = head2;
    SinglyLinkedListNode* new_root = new SinglyLinkedListNode{0,nullptr};
    SinglyLinkedListNode* new_list = new_root;
    while ((current_1 !=nullptr) && (current_2 != nullptr)) {
        if (current_1->data<current_2->data) {
            new_list->next = current_1;
            new_list = current_1;
            current_1 = current_1->next;
        } else {
            new_list->next = current_2;
            new_list = current_2;
            current_2 = current_2->next;
        }
    }
    if (current_1 == nullptr) {
        new_list->next = current_2;
        new_list = current_2;
        while (current_2->next != nullptr) {
            current_2 = current_2->next;
            new_list->next = current_2;
            new_list = current_2;
        }
    } else {
        new_list->next = current_1;
        new_list = current_1;
        while (current_1->next != nullptr) { 
            current_1 = current_1->next;
            new_list->next = current_1;
            new_list = current_1;
        }
    }

    return new_root->next;
}

int main() {
    int t;
    cin >> t;
    for (int l = 0; l<t; l++) {
        vector<int> a = {};
        vector<int> b = {};
        int temp,n,m;
        cin >> n;
        for (int i =0; i<n; i++) {
            cin >> temp;
            a.push_back(temp);
        }
        cin >> m;
        for (int i =0; i<m; i++) {
            cin >> temp;
            b.push_back(temp);
        }

        SinglyLinkedListNode* root = new SinglyLinkedListNode{a[0],nullptr};
        SinglyLinkedListNode* current = root;
        for (int i = 1; i<a.size(); i++) {
            SinglyLinkedListNode* new_node = new SinglyLinkedListNode{a[i],nullptr};
            current->next = new_node;
            current = new_node;
        }

        SinglyLinkedListNode* root_2 = new SinglyLinkedListNode{b[0],nullptr};
        SinglyLinkedListNode* current_2 = root_2;
        for (int i = 1; i<b.size(); i++) {
            SinglyLinkedListNode* new_node = new SinglyLinkedListNode{b[i],nullptr};
            current_2->next = new_node;
            current_2 = new_node;
        }

        SinglyLinkedListNode* answer = mergeLists(root, root_2);

        cout << answer->data;

        while (answer->next != nullptr) {
            answer = answer->next;
            cout << " " << answer->data;
        }

        cout << endl;

    }

    return 0;
}