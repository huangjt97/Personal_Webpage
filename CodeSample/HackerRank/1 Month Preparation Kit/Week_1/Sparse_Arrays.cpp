#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TreeNode {
private:
    int count;
    char data;
    TreeNode* left;
    TreeNode* right;

public:

    TreeNode(char val): count(0), data(val), left(nullptr), right(nullptr) {}

    int get_count() {
        return count;
    }

    char get_data() {
        return data;
    }

    TreeNode* get_left() {
        return left;
    }

    TreeNode* get_right() {
        return right;
    }

    void add_count() {
        count++;
        return;
    }

    void set_data(char t) {
        data = t;
        return;
    }

    void set_left(TreeNode* temp) {
        left = temp;
        return;
    }

    void set_right(TreeNode* temp) {
        right = temp;
        return;
    }

};

class Tree {
private:
    TreeNode* root;

public:
    Tree() : root() {}

    TreeNode* get_root() {
        return root;
    }

    void set_root(TreeNode* r) {
        root = r;
        return;
    }

    void Add_Word(string word, TreeNode* cur_Node) {
        
        if (word.size()==0) {
            return;
        }

        TreeNode* temp = cur_Node;
        string temp_word = word;
        if (cur_Node != nullptr) {
            
            if (temp->get_data() == word[0]) {
                if (word.size()==1) {
                    temp->add_count();
                } else {
                    Add_Word(word.substr(1), temp->get_left());
                }
                return;
            }
            while (temp->get_right() != nullptr) {
                
                temp = temp->get_right();
                if (temp->get_data() == word[0]) {
                    if (word.size()==1) {
                        temp->add_count();
                    } else {
                        Add_Word(word.substr(1), temp->get_left());
                    }
                    return;
                }
            }
            
            TreeNode* new_Node = new TreeNode(temp_word[0]);
            temp->set_right(new_Node);
            temp = temp->get_right();

            while (temp_word.size()>1) {
            
                temp_word = temp_word.substr(1);
                TreeNode* new_Node = new TreeNode(temp_word[0]);
                temp->set_left(new_Node);
                temp = temp->get_left();

            }
            
            temp->add_count();

        } else {
            TreeNode* new_Node = new TreeNode(temp_word[0]);
            temp = new_Node;
            set_root(new_Node);
            
            while (temp_word.size()>1) {
            
                temp_word = temp_word.substr(1);
                TreeNode* new_Node = new TreeNode(temp_word[0]);
                temp->set_left(new_Node);
                temp = temp->get_left();

            }
            
            temp->add_count();

        }

        return;
    }
    
    int Check_Word(string word, TreeNode* cur_Node) {

        if (word.size()==0) {
            return 0;
        } else {
            TreeNode* temp = cur_Node;
            if (temp->get_data() == word[0]) {
                if (word.size()==1) {
                    return temp->get_count();
                } else {
                    return Check_Word(word.substr(1), temp->get_left());
                }
            }
            while (temp->get_right() != nullptr) {
                temp = temp->get_right();
                if (temp->get_data() == word[0]) {
                    if (word.size()==1) {
                        return temp->get_count();
                    } else {
                        return Check_Word(word.substr(1), temp->get_left());
                    }
                }
            }
            
        }

        return 0;
    }
};

vector<int> matchingStrings(vector<string> strings, vector<string> queries) {

    Tree t = Tree();

    vector<int> answer;

    for (string s : strings) {
        t.Add_Word(s, t.get_root());
    }

    for (string s : queries) {
        answer.push_back(t.Check_Word(s, t.get_root()));
    }

    return answer;
}

int main() {
    vector<int> answer = matchingStrings({"aba", "baba", "aba", "xzxb"}, {"aba", "xzxb", "ab"});
    for (int i: answer) {
        cout << i << " ";
    }

    return 0;

}