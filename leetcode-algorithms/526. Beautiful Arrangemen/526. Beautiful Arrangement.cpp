class Solution {
public:
    int countArrangement(int N) {
		if(N<=2) return N;
		vector<int> visit(N+1, 0); //前面是否选择过某个数字
		int res = 0;
		getCnt(N, visit, 1, res); //从第一个位置开始枚举（1~N）
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
