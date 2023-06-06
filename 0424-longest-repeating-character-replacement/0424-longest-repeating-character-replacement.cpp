class Solution {
public:
     int characterReplacement(string s, int k) {
         int n=s.size();
        int i=0,j=0;
         int maxi=0;
         int maxf=0;
        vector<int> freq(26,0);
         while(j<n){
             freq[s[j]-'A']++;
             maxf=max(maxf,freq[s[j]-'A']);
            
             while((j-i+1)-maxf>k){
                 freq[s[i]-'A']--;
                 i++;
                 
                 maxf=*max_element(freq.begin(),freq.end());
             }
             maxi=max(maxi,j-i+1);
             j++;
         }
         return maxi;
     }
    
    // int characterReplacement(string s, int k) {
    //     vector<int> counts(26, 0);
    //     int start = 0;
    //     int maxCharCount = 0;
    //     int n = s.length();
    //     int result = 0;
    //     for(int end = 0; end < n; end++){
    //         counts[s[end]-'A']++;
    //         if(maxCharCount < counts[s[end]-'A']){
    //             maxCharCount = counts[s[end]-'A'];
    //         }
    //         while(end-start-maxCharCount+1 > k){
    //             counts[s[start]-'A']--;
    //             start++;
    //             for(int i = 0; i < 26; i++){
    //                 if(maxCharCount < counts[i]){
    //                     maxCharCount = counts[i];
    //                 }
    //             }
    //         }
    //         result = max(result, end-start+1);
    //     }
    //     return result;
    // }
};