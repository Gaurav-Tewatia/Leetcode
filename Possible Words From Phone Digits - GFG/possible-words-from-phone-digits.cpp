//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

char letter[][10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

class Solution
{   private:
 
 void helper(int i,int N,int *a,vector<string> &ans,string s){
        if(i==N){
            s.push_back('\0');
            ans.push_back(s);
            return;
        }
        
        int digit=a[i];
        if(digit==0 or digit==1)
        helper(i+1,N,a,ans,s);
        for(int k=0;letter[digit][k]!='\0';k++){
            s.push_back(letter[digit][k]);
            helper(i+1,N,a,ans,s);
            s.pop_back();
        }
    }
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        vector<string> ans;
        string s="";
        helper(0,N,a,ans,s);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends