class Solution {
public:

    bool check(vector<int> piles, long int speed, int h){
        int count=0;
        for(int i=0;i<piles.size();i++){
            count+=piles[i]/speed+(piles[i]%speed!=0);
            
            if(count>h)
            return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        sort(piles.begin(),piles.end());
        int s=1,e=piles[piles.size()-1],ans=0;
        while(s<=e){
            long int mid=(s+e)/2;
            if(check(piles,mid,h)){
                ans=mid;
                e=mid-1;
            }
            else
            s=mid+1;
        }
        return ans;
    }
};