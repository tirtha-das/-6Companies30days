class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
     int n = aliceValues.size();

        if(aliceValues.size()==1){
            return 1;
        }

        priority_queue<pair<int,pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            pq.push({aliceValues[i]+bobValues[i],{aliceValues[i],bobValues[i]}});
        }

        int a=0,b=0;
        while(pq.size()>0){
            auto cur = pq.top();
                pq.pop();
            
              a+=cur.second.first;
              
            
            if(pq.size()){
                auto cur2 = pq.top();
               pq.pop();
                    b+=cur2.second.second;
            }
        
        }

        if(a==b) return 0;
        else if(a>b) return 1;
        return -1;
    }
};