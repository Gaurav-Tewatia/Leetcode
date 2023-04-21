class Solution {
public:
    
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        
        vector<vector<int>> ahead(2,vector<int>(k+1,0)),cur(2,vector<int>(k+1,0));
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int limit=1;limit<=k;limit++){
                    int profit=0;

                    if(!j)
                        profit=max(-prices[i]+ahead[1][limit],ahead[0][limit]);
                    else
                        profit=max(prices[i]+ahead[0][limit-1],ahead[1][limit]);

                    cur[j][limit]=profit;
                    
                }
            }
            ahead=cur;
        }
        
        return ahead[0][k];
        
        
        
        
    }
};