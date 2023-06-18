class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string>s(wordList.begin(),wordList.end());
        
        queue<pair<string,int>>q;
        
        q.push({beginWord,1});
        
        s.erase(beginWord);
       
        while(!q.empty()){
           string word=q.front().first;
           int steps=q.front().second;
           q.pop();
           cout<<word<<endl;
           if(word==endWord)
               return steps;
           
           for(int i=0;i<word.size();i++){
                char orginal=word[i];
               
               for(char ch='a';ch<='z';ch++ ){
                   word[i]=ch;
                   
                   if(s.find(word)!=s.end()){
                       cout<<"inside if";
                       q.push({word,steps+1});
                       s.erase(word);
                       
                   }
               }
               word[i]=orginal;
               
           }
           
           
       }
        return 0;
    }
};