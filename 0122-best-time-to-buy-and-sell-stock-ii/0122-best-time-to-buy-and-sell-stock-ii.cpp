class Solution {
public:
    
   /* 
   //this is top down approach
   int solve(vector<int> &prices, int i,int buy, vector<vector<int>> & dp){
        if(i==prices.size())
            return 0;
        
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        
        int profit;
        
        if(!buy){
            profit=max(-prices[i]+solve(prices,i+1,1,dp),solve(prices,i+1,0,dp));
            
        }
        else{
            profit=max(prices[i]+solve(prices,i+1,0,dp),solve(prices,i+1,1,dp));
        }
        
        return dp[i][buy]=profit;
    }
    */
    
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        
       // return solve(prices,0,0,dp);
        
      /*  dp[n][0]=dp[n][1]=0;
        int buy=0;
        int profit;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(!j){
                    profit =max(-prices[i]+dp[i+1][1],dp[i+1][0]);   
                }
                else
                    profit=max(prices[i]+dp[i+1][0],dp[i+1][1]);
                
                dp[i][j]=profit;
            }
        }
        */
        
        //this is space optimized version
        
        vector<int> ahead(2,0),cur(2,0);
        ahead[0]=ahead[1]=0;
         for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                
                int profit=0;
                if(!j){
                    profit =max(-prices[i]+ahead[1],ahead[0]);   
                }
                else
                    profit=max(prices[i]+ahead[0],ahead[1]);
                
                cur[j]=profit;
            }
             ahead=cur;
        }
        
        return ahead[0];
    }
};