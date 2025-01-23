class TrieNode{
    
    unordered_map<char,TrieNode*>next;
    bool end;
   public:
    TrieNode(){
        end = false;
    }

    bool containKey(char ch){
        if(next.find(ch)!=next.end()) return true;
        return false;
    }

    void putKey(char ch, TrieNode* loc){
        next[ch] = loc;
    }

    TrieNode* getKey(char ch){
        return next[ch];
    }

    void setEnd(){
        end = true;
    }

    bool getEnd(){
        return end;
    }
};



class WordDictionary {
    TrieNode* head;
public:
    WordDictionary() {
        head = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* temp = head;
        for(auto it:word){
            if(!temp->containKey(it)){
               temp->putKey(it,new TrieNode());
            }
            temp = temp->getKey(it);
        }
        temp->setEnd();
    }

    bool searchHelper(TrieNode* cur, int idx, string& word){
        if(idx==word.size()){
            return cur->getEnd();
        }

        if(word[idx]!='.'){
            if(cur->containKey(word[idx])){
                cur = cur->getKey(word[idx]);
                return searchHelper(cur,idx+1,word);
            }
            return false;
        }

        bool ans = false;
        for(int i=0;i<26;i++){
            char ch = 'a'+i;
            if(cur->containKey(ch)){
                TrieNode* temp = cur->getKey(ch);
                ans |= searchHelper(temp,idx+1,word);
            }
        }

        return ans;
    }
    
    bool search(string word) {
        TrieNode* cur = head;
        return searchHelper(cur,0,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */