class WordDictionary {
public:

        
    
        
    
    struct Node{
        Node* child['a'] = {};
        bool end = false;
    };
    Node *root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {    
        Node *cur = root;
        for(char c : word){
            if(!(cur->child[c - 'a'])){
                cur->child[c - 'a'] = new Node();
            }
            cur = cur->child[c - 'a'];
        }
        cur -> end = true;
        
    }
    
    bool search(string word) {
        Node *cur = root;
        return isPossible(cur , word , 0);

    }
    bool isPossible(Node *cur , string &word , int i){
        if(i == word.size()){
            return cur->end;
        }
        if(cur == NULL)return 0;
        int pos = 0;
        if(word[i] == '.'){
            for(int j = 0 ; j < 'a' ; j++){
                if(cur->child[j] != NULL)
                pos|=isPossible(cur->child[j] , word , i + 1);
            }
        }
        else if(cur->child[word[i] - 'a'] != NULL)pos|= isPossible(cur->child[word[i] - 'a'] , word , i + 1);
        return pos;
    }
};
