class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_set<string>seen;
        for(int i=0;i<nums.size();i++){
            int cnt = 0;
            string cur = "";
            for(int j=i;j<nums.size();j++){
                cur += to_string(nums[j])+",";
                if(nums[j]%p==0){
                    cnt++;
                }
                if(cnt>k){
                    break;
                }
                else if(seen.find(cur)==seen.end()){
                   // cout<<cur<<endl;
                    seen.insert(cur);
                }
            }
        }

        return seen.size();
    }
};