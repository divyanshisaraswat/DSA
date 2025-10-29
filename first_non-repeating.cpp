class Solution {
  public:
    string firstNonRepeating(string &s) {
        unordered_map<char,int> count;
        queue<int> q;
        string ans="";
        
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            
            //increase count
            count[ch]++;
            
            //push in queue
            q.push(ch);
            
            while(!q.empty()){
              if(count[q.front()] > 1){
                  //repeating character
                  q.pop();
              } 
              else {
                  //non repeating
                  ans.push_back(q.front());
                  break;
              }
            }
            if(q.empty()){
                ans.push_back('#');
            }
           
        }
             return ans;
        
    }
};
