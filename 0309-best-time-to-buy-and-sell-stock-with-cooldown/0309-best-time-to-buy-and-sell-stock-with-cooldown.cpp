class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
//          vector<vector<int>> dp(n+2,vector<int>(3,0));
        
//         for(int i=n-1;i>=0;i--){
//             for(int j=0;j<=1;j++){
//                 int profit;
//                 if(!j){
//                     profit=max(-prices[i]+dp[i+1][1],dp[i+1][0]);
//                 }
//                 else
//                     profit=max(prices[i]+dp[i+2][0],dp[i+1][1]);
                
//                 dp[i][j]=profit;
//             }
//         }
        
//         return dp[0][0];
        
        
        //this is space optimized version
        
        vector<int> cur(2,0),front1(2,0),front2(2,0);
        
         for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int profit;
                if(!j){
                    profit=max(-prices[i]+front1[1],front1[0]);
                }
                else
                    profit=max(prices[i]+front2[0],front1[1]);
                
                cur[j]=profit;
            }
             front2=front1;
             front1=cur;
        }
        
        return cur[0];
        
        
    }
};