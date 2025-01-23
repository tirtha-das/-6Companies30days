



int bfs(int start,unordered_set<int>seen,vector<vector<int>>&adjList){
    queue<int>pn;
    
    pn.push(start);
    seen.erase(start);
     int cnt = 0;
    while(pn.size()){
       int sz = pn.size();
       for(int i=0;i<sz;i++){
         int cur =pn.front();
         pn.pop();
         for(auto it2 : adjList[cur]){
            if(seen.find(it2)!=seen.end()){
                pn.push(it2);
                seen.erase(it2);
            }
         }
       }
       if(pn.size()) cnt++;
    }

    if(seen.size()>0) return INT_MAX;
    else return cnt-1;
}


class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adjList(n,vector<int>());
        for(auto it:edges){
            adjList[it[0]-1].push_back(it[1]-1);
            adjList[it[1]-1].push_back(it[0]-1);
        }

        int switchedNode = (1<<n)-1;
        vector<int>dist(n-1,0);

         for(int i=0;i<=switchedNode;i++){
             unordered_set<int>seen;
             for(int j = 0;j<n;j++){
                 if(i&(1<<j)) {
                    seen.insert(j);
                    }
             }

            if(seen.size()>1) {
                int idx = 0;
                for(auto it=seen.begin();it!=seen.end();it++){
                      idx = max(idx,bfs(*it,seen,adjList));
                     if(idx==INT_MAX) {
                      
                        break;
                     }
                }
               
                if(idx!=INT_MAX) {
                   
                    dist[idx]++;
                  
                }
               
            }   
         }

        return dist;
    }
};