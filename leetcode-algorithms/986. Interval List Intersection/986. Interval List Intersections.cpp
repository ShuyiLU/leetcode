#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*
class Solution {
public:
    vector<vector<int> > intervalIntersection(vector<vector<int> >& A, vector<vector<int> >& B) {
        int start=0, end=0;
        if(A.size() == 0 || B.size() == 0) return vector<vector<int> > {};
        
        vector<int> tmp;
        vector<vector<int> > res;
        
        int j;
        
        for(int i=0; i<A.size(); i++){
        	j = 0;
        	while(j<B.size() && A[i].back() >= B[j].front()){
        		start = max(A[i].front(), B[j].front());
        		end = min(A[i].back(), B[j].back());
        		if(start <= end){
        			tmp.push_back(start);
        			tmp.push_back(end);
        			res.push_back(tmp);
        			tmp.clear();
				}
				j++;
			}
		}
       return res;
    }
};
*/

class Solution {
public:
    vector<vector<int> > intervalIntersection(vector<vector<int> >& A, vector<vector<int> >& B) {
        if(A.size() == 0 || B.size() == 0) return vector<vector<int> > {};
        int i=0, j=0;
        vector<vector<int> > res;
        while(i<A.size() && j<B.size()){
        	if(A[i].back() < B[j].front()) i++;
        	else if(A[i].front() > B[j].back()) j++;
        	else{
        		res.push_back({max(A[i].front(), B[j].front()), min(A[i].back(), B[j].back())});
        		if(A[i].back() < B[j].back()) i++;
        		else j++;
			}
		}
		return res;
    }
};
