class TrieNode{
    public:
    unordered_map<char,TrieNode*>next;
     set<string> tracker;
    TrieNode(){
        
    }
    
    bool isContainKey(char ch){
        if(this->next.find(ch)==this->next.end())
             return false;
             
        return true;
    }
    
    void putKey(char ch, TrieNode* newNode){
        this->next[ch] = newNode;
       
    }
    
    void matchContact(string& st){
         if(this->tracker.find(st)==this->tracker.end()){
            this->tracker.insert(st);
        }
    }
    
    TrieNode* getKey(char ch){
        return this->next[ch];
    }
    
    vector<string> getMatch(){
        vector<string>res;
        for(auto it=this->tracker.begin();it!=this->tracker.end();it++){
            res.push_back(*it);
        }
        return res;
    }
};


class Trie{
    public:
    TrieNode* head;
    
    Trie(){
        head = new TrieNode();
    }
    
    void insertContact(string& st){
        TrieNode* cur = head;
        int i=0;
        while(i<st.size()){
            if(!cur->isContainKey(st[i])){
                cur->putKey(st[i],new TrieNode());
            }
            
            cur = cur->getKey(st[i]);
            cur->matchContact(st);
            i++;
        }
        
    }
    
     vector<vector<string>> getContact(string& st){
         vector<vector<string>>ans ;
         TrieNode* cur = head;
         int i=0;
         while(i<st.size()){
             if(cur->isContainKey(st[i])){
                // cout<<"hello";
                 cur = cur->getKey(st[i]);
                 ans.push_back(cur->getMatch());
                 i++;
                 
             }else{
                 break;
             }
         }
         
         while(ans.size()<st.size()){
             ans.push_back({"0"});
         }
         
         return ans;
         
     }
    
    
};

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        Trie t;
        for(int i=0;i<n;i++){
            t.insertContact(contact[i]);
        }
        
        return t.getContact(s);
    }
};