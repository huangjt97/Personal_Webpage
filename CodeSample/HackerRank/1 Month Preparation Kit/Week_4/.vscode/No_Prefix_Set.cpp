
void noPrefix(vector<string> words) {
    struct Node {
        char data = ' ';
        Node* left = nullptr; //next position character;
        Node* right = nullptr; //same position character;
        bool end = false;
    };  
    Node* root = new Node;
    Node* current;
    int j;
    bool flag;
    for (int i = 0; i< words.size(); i++) {
        current = root;
        j = 0;
        flag = true;
        while ((j<words[i].size()) && (flag)) {
            
            if (current->data != words[i][j]) {
                if (current->right != nullptr) {
                    current = current->right;
                } else {
                    flag = false;
                    Node* new_Node = new Node;
                    new_Node->data = words[i][j];
                    current->right = new_Node;
                    current = new_Node;
                    j++;
                }
            } else {
                if (current->left!=nullptr) {
                    current = current->left; 
                } else {
                    if (current->end) {
                        cout << "BAD SET" << endl;
                        cout << words[i] << endl;
                        return;
                    } else {
                        flag =true;
                    }
                    Node* new_Node = new Node;
                    new_Node->data = words[i][j];
                    current->left= new_Node;
                    current = new_Node;
                }
                j++;
            }
        }
        
        if (flag) {
            cout << "BAD SET" << endl;
            cout << words[i] << endl;
            return;
        }
        
        
        while (j<words[i].size()) {
            Node* new_Node = new Node;
            new_Node->data = words[i][j];
            current->left = new_Node;
            current = new_Node;
            j++;
        }
        current->end = true;
        
        
    }
    
    cout << "GOOD SET" << endl;
    
    return;
}
