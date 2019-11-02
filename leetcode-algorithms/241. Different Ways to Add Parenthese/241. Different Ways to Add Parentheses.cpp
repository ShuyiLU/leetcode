class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int size = input.size();
        vector<int> res;
        for(int i=0; i<size; i++){
            if(input[i] == '+' || input[i] == '-' || input[i] == '*'){
                vector<int> re1 = diffWaysToCompute(input.substr(0, i));
                vector<int> re2 = diffWaysToCompute(input.substr(i+1));
                for(int j=0; j<re1.size(); j++){
                    for(int k=0; k<re2.size(); k++){
                        if(input[i] == '+') res.push_back(re1[j] + re2[k]);
                        else if(input[i] == '-') res.push_back(re1[j] - re2[k]);
                        else if(input[i] == '*') res.push_back(re1[j] * re2[k]);
                    }
                }
            }
        }
        if(res.empty()) res.push_back (atoi(input.c_str()));
        return res;
    }
};
