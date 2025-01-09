class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        if(k==1){
           // vector<int>ans = arr;
            return arr;
        }
            vector<int>ans;
            
            multiset<int>sorted;
            int left = 0;
            
            for(int i=0;i<arr.size();i++){
                sorted.insert(arr[i]);
                
                if(i+1>=k){
                    auto it = sorted.rbegin();
                    ans.push_back(*it);
                    auto it2 = sorted.find(arr[left]);
                    sorted.erase(it2);
                    left++;
                }
                
                
            }
            
            
            
            return ans;
        
    }
};