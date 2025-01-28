class Solution {
public:
    int countCollisions(string d) {
        vector<pair<char,int>>freq;
        for(int i=0;i<d.size();i++){
            int cnt = 1;
            while(i+1<d.size() && d[i]==d[i+1]){
                cnt++;
                i++;
            }
            freq.push_back({d[i],cnt});
        }

        int ans = 0;
        for(int i=0;i<freq.size()-1;i++){
            if(freq[i].first=='R' && freq[i+1].first =='L'){
                ans += (freq[i].second+freq[i+1].second);
            }else if(freq[i].first=='S' && freq[i+1].first=='L'){
                ans+= freq[i+1].second;
            }else if(freq[i].first=='R' && freq[i+1].first=='S'){
                ans+=freq[i].second;
            }
        }

        return ans;
    }
};