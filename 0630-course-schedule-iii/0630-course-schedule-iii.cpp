class Solution {
   static  bool compare(const vector<int> &a, const vector<int> &b){
        return a[1]<b[1];
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        
        // auto compare=[](const vector<int> &a,vector<int> &b){
        //     return a[1]<b[1];
        // };
        sort(courses.begin(),courses.end(),compare);
        
        int sum=0;
        priority_queue<int> pq;
        for(auto &it:courses){
            sum+=it[0];
            pq.push(it[0]);
            
            if(sum>it[1]){
                sum-=pq.top();
                pq.pop();
            }
        }
        
        return pq.size();
    }
};