#include<iostream>
#include<vector>

using namespace std;


class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

class Solution {
private:
	int re = 0;		
	
public:	
	Employee findEmployee(vector<Employee*> employees, int id){
		Employee e;
		for(int i=0; i<employees.size(); i++){
        	if((*employees[i]).id == id) {
        		e = *employees[i];
        		break;
			}
        	else continue;
		}
		return e;
	}
	
    int getImportance(vector<Employee*> employees, int id) {
    	if(employees.empty()) return 0;
        Employee e;
        e = findEmployee(employees, id);
		DFS(employees, e);
		return re;
    }
    
    void DFS(vector<Employee*> employees, Employee e){
    	re += e.importance;
		if(e.subordinates.empty()) {
    		return;
		}
    	else{
    		for(int i=0; i<e.subordinates.size(); i++){
    			Employee temp = findEmployee(employees, e.subordinates[i]);
    			DFS(employees, temp);
			}
		}
		//return re;
	}   
};

int main(){
}
