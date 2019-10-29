#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
//��������̵�.��������������
//��������ΪR, L, ��ǰ���Ʋ���
//���ΪR�� ���޸�ΪR
//�Ҳ�ΪL���޸�ΪL
//����ΪL, R�� �������в��� 

class Solution {
public:
    string pushDominoes(string d) {
        
		d = 'L' + d + 'R';
		string res = "";
		int i=0;
		for(int j=1; j<d.length(); j++){
			if(d[j] == '.') continue;
			int middle = j-i-1; // j = R or L , middle=(i, j)֮��ľ��룬 ������i��j 
			if(i>0) res += d[i];
			if(d[i] == d[j]){
				res += string(middle, d[i]); //�ó�����ȫΪ	L or R 
			}	
			else if(d[i] == 'L' && d[j] == 'R'){
				res += string(middle, '.');
			}
			else{
				res += string(middle/2, 'R') + string(middle%2, '.') + string(middle/2, 'L');
			}
			i = j;
			//i jΪһ������.���������� 
		}
		return res;
    }
};
