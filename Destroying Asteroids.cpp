class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        int curMass = mass;
        for(auto ele:asteroids){
           if(curMass>=ele){
            curMass+=ele;
            if(curMass>=asteroids[asteroids.size()-1]) return true;
           }else{
            return false;
           }
        }
        return true;
    }
};