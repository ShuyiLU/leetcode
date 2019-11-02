class Solution {
public:
    int countArrangement(int N) {
		if(N<=2) return N;
		vector<int> visit(N+1, 0); //ǰ���Ƿ�ѡ���ĳ������
		int res = 0;
		getCnt(N, visit, 1, res); //�ӵ�һ��λ�ÿ�ʼö�٣�1~N��
		return res;
			
    }
	
	void getCnt(int N, vector<int> &visit, int pos, int &res){
		if(pos > N){
			res++;
			return;
		}
		for(int i = 1; i<=N; i++){
			if(visit[i] == 0 && ( i%pos == 0 || pos%i == 0)){
				visit[i] = 1;
				getCnt(N, visit, pos+1, res);
				visit[i] = 0;
			}
		}
	}
	
};
