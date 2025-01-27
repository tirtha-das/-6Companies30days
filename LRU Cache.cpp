class LRUCache {
    unordered_map<int,pair<int,int>>mp;
    set<pair<int,int>>seen;
    int capacity;
    int cnt;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        cnt = 0;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        else{
            pair<int,int>cur = mp[key];
            auto it = seen.find({cur.first,key});
            seen.erase(it);
            mp[key].first = cnt;
            seen.insert({cnt,key});
            cnt++; 
            return mp[key].second;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end()){
             mp[key] = {cnt,value};
             seen.insert({cnt,key});
             cnt++;
             if(seen.size()>capacity){
                auto it = seen.begin();
                int frontKey  = it->second;
                mp.erase(frontKey);
                seen.erase(it);
             }
        }else{
            auto it = seen.find({mp[key].first,key});
            seen.erase(it);
            mp[key].first = cnt;
            mp[key].second = value;
            seen.insert({mp[key].first,key});
            cnt++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */