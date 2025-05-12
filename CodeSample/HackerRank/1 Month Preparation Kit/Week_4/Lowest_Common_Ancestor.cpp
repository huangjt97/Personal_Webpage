Node *lca(Node *root, int v1,int v2) {
    // Write your code here.
    Node* current_1 = root;
    Node* current_2 = root;
    while (current_1 == current_2) {
        if ((current_1->data < v1) && (current_2->data < v2)) {
            current_1 = current_1->right;
            current_2 = current_2->right;
        } else if ((current_1->data > v1) && (current_2->data > v2)) {
            current_1 = current_1->left;
            current_2 = current_2->left;
        } else {
            return current_1;
        }
    }
    
    return current_1;
    
}