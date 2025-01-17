class ThroneInheritance {
public:
   vector<vector<int>>store;
   unordered_map<string,pair<int,int>>mp;
   unordered_map<int,string>mp2;
   int cnt;

    ThroneInheritance(string kingName) {
        store.resize(10e5+2);
        cnt = 0;
        mp[kingName] = {cnt,1};
        mp2[cnt] = kingName;
        cnt++;
        
    }
    
    void birth(string parentName, string childName) {
        int idx = mp[parentName].first;
        mp[childName] = {cnt,1};
        store[idx].push_back(cnt);
        mp2[cnt] = childName;
        cnt++;
    }
    
    void death(string name) {
        pair<int,int>cur = mp[name];
        cur.second=0;
        mp[name] = cur; 
    }

    void helper(int idx,vector<string>& ans){
        string cur = mp2[idx];
        if(mp[cur].second) ans.push_back(cur);

        for(auto next : store[idx]){
            helper(next,ans);
        }
    }
    
    vector<string> getInheritanceOrder() {
        vector<string>ans;
        helper(0,ans);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */