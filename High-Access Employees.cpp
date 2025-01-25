

class Solution {
    static bool cmp(vector<string>&a,vector<string>&b){
        return a[1]<b[1];
    }

    bool isOutOfRange(int left, int right,vector<vector<string>>&s){
        int start = stoi(s[left][1]);
        int end = stoi(s[right][1]);
        if(end-start>=100) return true;
        return false; 
    }
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> ans;
        if(access_times.size()<3) return ans;

        sort(access_times.begin(),access_times.end(),cmp);
        unordered_map<string,int>freq;
        unordered_set<string> seen;
        int left = 0;
        for(int right=0;right<access_times.size();right++){
            freq[access_times[right][0]]++;
            while(left<right && isOutOfRange(left,right,access_times)){
                freq[access_times[left][0]]--;
                left++;
            }
            for(auto it = freq.begin();it!=freq.end();it++){
                if(it->second>=3 && seen.find(it->first)==seen.end()){
                    seen.insert(it->first);
                }
            }

        }

        for(auto it=seen.begin();it!=seen.end();it++){
            ans.push_back(*it);
        }

        return ans;
    }
};