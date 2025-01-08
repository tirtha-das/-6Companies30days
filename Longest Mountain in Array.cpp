class Solution {
public:
    int longestMountain(vector<int>& arr) {
         int ans = 0;
         for(int i=1;i<arr.size()-1;i++){
            int lb = i;
            int rb = i;
            while(lb-1>=0 && arr[lb]>arr[lb-1]){
                lb--;
            }
            while(rb+1<arr.size() && arr[rb]>arr[rb+1]){
                rb++;
            }
           if(lb!=i && rb!=i) ans = max(ans,(rb+1-lb));
           
         }
        
         return (ans>2?ans:0);
    }
};