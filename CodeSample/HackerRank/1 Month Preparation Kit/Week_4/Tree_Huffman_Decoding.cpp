void decode_huff(node * root, string s) {
    int i =0; //position in s
    int n = s.size();
    node* current_node = root;
    string answer = "";
    while (i<n) {
        if (s[i]=='0') {
            current_node = current_node->left;
        } else {
            current_node = current_node->right;
        }
        if (current_node->data != NULL) {
            answer += current_node->data;
            current_node = root;
        }
        i++;
    }
    
    cout << answer << endl;
    
    return;
}