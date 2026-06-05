struct TrieNode{
    TrieNode* node[26];
    bool isEnd;

};
class PrefixTree {
public:

    TrieNode* root;

    PrefixTree() {
        root = new TrieNode();    
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for(char ch : word){
            if(temp->node[ch - 'a'] == NULL)temp->node[ch - 'a'] = new TrieNode();
            temp = temp->node[ch - 'a'];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for(char ch : word){
            if(temp->node[ch - 'a'] == NULL)return 0;
            temp = temp->node[ch - 'a'];
        }
        if(temp->isEnd)return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(char ch : prefix){
            if(temp->node[ch - 'a'] == NULL)return 0;
            temp = temp->node[ch - 'a'];
        }
        return 1;
    }
};
