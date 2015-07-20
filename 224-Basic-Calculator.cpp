
class Solution {
public:
    int calculate(string s) {
        stack<string> tokens;
        int pos = 0;
        string token;
        while (findNextToken(s, token, pos)){
            if (token == ")"){
                int val = calSimple(tokens);
                tokens.pop(); // "("
                ostringstream oss;
                oss << val;
                tokens.push(oss.str());
            }else{
                tokens.push(token);
            }
        }
        return calSimple(tokens);
    }
    
    int calSimple(stack<string>& tokens){
        int result = 0;
        for (;;){
            int  num = strtoul(tokens.top().c_str(), NULL, 10);
            tokens.pop();
            if (tokens.empty() || tokens.top() == "("){
                return result + num;
            }
            string op = tokens.top();
            tokens.pop();
            result = (op == "+")? result + num : result - num;
        }
        return result;
    }
    
    bool findNextToken(string& s, string& token, int& pos){
        for (int i = pos; i < s.size(); i++){
            if (s[i] == ' ') continue;
            if (!('0' <= s[i] && s[i] <= '9')){
                // +, -, (, )
                token = s.substr(i,1);
                pos = i + 1;
                return true;
            }
            // num
            int end = i;
            while ( end + 1 < s.size() && '0' <= s[end + 1] && s[end + 1] <= '9') ++end;
            token = s.substr(i, end - i + 1);
            pos = end + 1;
            return true;
        }
        return false;
    }
};
