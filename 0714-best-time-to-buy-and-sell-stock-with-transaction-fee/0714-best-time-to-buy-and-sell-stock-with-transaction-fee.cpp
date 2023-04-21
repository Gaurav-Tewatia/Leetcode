class Solution {
public:
    //this is the optimized version  for memoization and bottom up look the previous question of stock2
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        
        vector<int> ahead(2,0),cur(2,0);
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int profit;
                if(!j)
                    profit=max(-prices[i]+ahead[1],ahead[0]);
                else
                    profit=max(prices[i]-fee+ahead[0],ahead[1]);
                
                cur[j]=profit;
            }
            ahead=cur;
        }
        
        return ahead[0];
    }
    
    
};