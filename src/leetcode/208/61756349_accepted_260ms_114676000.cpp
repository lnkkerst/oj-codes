class Trie {
public:
    /** Initialize your data structure here. */
    unordered_map<string, bool> b1, b2;
    Trie() {
        b1.clear();
        b2.clear();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        b1[word] = 1;
        for(int i = 1; i <= (int)word.size(); ++i)
            b2[word.substr(0, i)] = 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return b1[word];
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return b2[prefix];
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */