class Solution {
public:
    bool canBeValid(string s, string k) {
        stack<int> locked, free;
        for(int i = 0; i < s.size(); i++){
            if(k[i]=='0'){
                free.push(i);
            }
            else if(s[i]=='('){
                locked.push(i);
            }
            else{
                if(locked.empty() && free.empty()) return 0;
                if(locked.empty()) free.pop();
                else locked.pop();
            }
        }
        while(!locked.empty()){
            if(free.empty() || free.top() < locked.top()) return 0;
            free.pop();
            locked.pop();
        }
        return free.size() % 2 == 0;
    }
};
