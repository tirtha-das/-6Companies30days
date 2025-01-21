#define PSI pair<string,int>

class Solution {
public:
     static bool compare(const vector<int>&a,const vector<int>&b){
        if(a[1]==b[1]){
            return a[0]>b[0];
        }
        return a[1]>b[1];
     }
    
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<vector<int>>vect;
        for(int i=0;i<queries.size();i++){
            vector<int>cur = queries[i];
            cur.push_back(i);
            vect.push_back(cur);
        }
        sort(vect.begin(),vect.end(),compare);

        // for(auto it :vect){
        //     cout<<it[0]<<" "<<it[1]<<endl;
        // }

        int idx=0;
        vector<int>ans(vect.size());

        while(idx<vect.size()){
            priority_queue<PSI>pq;

           for(int i=0;i<nums.size();i++){
            pq.push({nums[i].substr(nums[i].size()-vect[idx][1]),i});

           // cout<<nums[i].substr(nums[i].size()-vect[idx][1])<<endl;
            if(pq.size()>vect[idx][0]){
                pq.pop();
            }
           }
          ans[vect[idx][2]] = pq.top().second;

          while(idx+1!=vect.size() && vect[idx][1]==vect[idx+1][1]){
            idx++;
            while(pq.size()>vect[idx][0]){
               pq.pop();
            }
            ans[vect[idx][2]] = pq.top().second;
          }

          idx++;

        }
        
        


       
        return ans;
    }
};