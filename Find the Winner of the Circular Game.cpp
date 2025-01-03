class Solution {
public:
    int solve(int n,int k){
        if(n==1) return 0;
        
        int prev = solve(n-1,k);
        return (prev+k)%n;
    }
    int findTheWinner(int n, int k) {
        // return solve(n,k)+1;

        int prev = 0;
        int cur;
        for(int i=2;i<=n;i++){
            cur = (prev+k)%i;
            prev = cur;
        }
        return prev+1;
    }
};