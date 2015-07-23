class WordDictionary {
public:

    class TreeNode {
        public:
            TreeNode() : count(0), end(0){
                for (int i = 0; i < 26; i++)
                    sub[i] = NULL;
            }
            TreeNode* sub[26];
            int count;
            int end;
    };
    
    WordDictionary() : root_(new TreeNode()){}
    
    // Adds a word into the data structure.
    void addWord(string word) {
        ++ root_->count;
        TreeNode* cur = root_;
        for (int i = 0; i < word.size(); i ++){
            int index = word[i] - 'a';
            TreeNode* node = cur->sub[index];
            if (node == NULL)
                node = cur->sub[index] = new TreeNode();
            cur = node;
            ++ cur->count;
        }
        ++ cur->end;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(root_, word, 0);
    }
    
    bool search(TreeNode* root, string word, int l) {
        if (root == NULL) return false;
        TreeNode* cur = root;
        for (int i = l; i < word.size(); i ++){
            if (word[i] != '.'){
                cur = cur->sub[word[i] - 'a'];
                if (cur == NULL) return false;
            }else
                return searchAll(cur, word, i);
        }
        return cur->end > 0;
    }
    
    bool searchAll(TreeNode* root, string word, int l){
        if (root == NULL) return false;
        for (int i = 0; i < 26; i ++){
            if (search(root->sub[i], word, l + 1))
                return true;
        }
        return false;
    }
    
private:
    TreeNode* root_;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
