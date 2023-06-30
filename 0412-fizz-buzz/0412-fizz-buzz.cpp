class Solution {
public:
    vector<string> fizzBuzz(int n) {
        int j=3,k=5,l=15;
        vector<string> ans;
        
        for(int i=1;i<=n;i++){
            if(i==l){
                ans.push_back("FizzBuzz");
                l+=15;
                j+=3;
                k+=5;
            }
            else if(i==j){
                ans.push_back("Fizz");
                j+=3;
            }
            else if(i==k){
                ans.push_back("Buzz");
                k+=5;
            }
            else{
                ans.push_back(to_string(i));
            }
        }
        return ans;
    }
};