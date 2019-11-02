class Solution {
public:
    int longestLine(vector<vector<int> >& M) {
    	if(M.empty()) return 0;
    	int max = 0;
		int max_h = 0;
		int max_v = 0;
		int max_d = 0;
		int max_a = 0;
		for(int i=0; i<M.size(); i++){
			int tmp = 0;
			for(int j=0; j<M[i].size(); j++){	
				if(M[i][j] == 0) {
					if(tmp  > max_h) max_h = tmp;
					tmp = 0;
				}
				else{
					tmp = tmp + 1;
				}
			}
			if(tmp  > max_h) max_h = tmp;
		}
		if(max_h > max)  max = max_h;
	//	cout << max_h << endl;
		for(int j=0; j<M[0].size(); j++){
				int tmp = 0;
				for(int i=0; i<M.size(); i++){
					if(M[i][j] == 0) {
						if(tmp  > max_v) max_v = tmp;
						tmp = 0;
					}
					else{
						tmp = tmp + 1;
					}
				}
				if(tmp  > max_v) max_v = tmp;
		}
		if(max_v > max)  max = max_v;
//		cout << max_v << endl;
		/*
		int k = M.size()-1;
		int a,b;
		while(k>=0){
			a = k;
			b = 0;
			int tmp = 0;
			while((a+1)<=M.size() && (b+1)<=M[0].size()&&a>=0&&b>=0){
				if(M[a][b] == 1){
					tmp++;
					a++;
					b++;
				}
				else{
					if(tmp  > max_d) max_d = tmp;
					tmp = 0;
					a++;
					b++;
				}
			}
			k--;
		}
	//	cout << max_d << endl;
		int k2 = 1;
		int a2,b2;
		while(k2<M[0].size()){
			a2 = 0;
			b2 = k2;
			int tmp = 0;
			while((a2+1)<=M.size() && (b2+1)<=M[0].size()&&a2>=0&&b2>=0){
				if(M[a2][b2] == 1){
					tmp++;
					a2++;
					b2++;
				}
				else{
					if(tmp  > max_d) max_d = tmp;
					tmp = 0;
					a2++;
					b2++;
				}
			}
			if(tmp  > max_d) max_d = tmp;
			k2++;
		}
		*/
		for(int k=M.size()-1; k>=0; k--){
			int tmp = 0;
			for(int i=k, j=0; i<M.size()&&j<M[0].size(); i++, j++){
				if(M[i][j] == 1){
					tmp++;
				}
				else{
					if(tmp  > max_d) max_d = tmp;
					tmp = 0;
				}
			}
			if(tmp  > max_d) max_d = tmp;
		}
		for(int k=1; k<M[0].size(); k++){
			int tmp = 0;
			for(int i=0, j=k; i<M.size()&&j<M[0].size(); i++, j++){
				if(M[i][j] == 1){
					tmp++;
				}
				else{
					if(tmp  > max_d) max_d = tmp;
					tmp = 0;
				}
			}
			if(tmp  > max_d) max_d = tmp;
		}
		
		if(max_d>max) max = max_d;
//		cout << max_d << endl;
		/*
		int k3=0;
		int a3, b3;
		while(k3<M[0].size()){
			a3 = 0;
			b3 = k3;
			int tmp = 0;
			while(a3>=0 && b3>=0 && a3<M.size()&&b3<M[0].size()){
				if(M[a3][b3] == 1){
					tmp++;
					a3++;
					b3--;
				}
				else{
					if(tmp  > max_a) max_a = tmp;
					tmp = 0;
					a3++;
					b3--;
				}
			}
			if(tmp  > max_a) max_a = tmp;
			k3++;
		}
		
//		cout << max_a << endl;
		int k4=1;
		int a4, b4;
		while(k4<M.size()){
			a4 = k4;
			b4 = M[0].size();
			int tmp = 0;
			while(a4>=0 && b4>=0&& a4<M.size()&&b4<M[0].size()){
				if(M[a4][b4] == 1){
					tmp++;
					a4++;
					b4--;
				}
				else{
					if(tmp  > max_a) max_a = tmp;
					tmp = 0;
					a4++;
					b4--;
				}
			}
			if(tmp  > max_a) max_a = tmp;
			k4++;
		}
		*/
		for(int k=M.size()-1; k>=0; k--){
			int tmp=0;
			for(int i=0, j=k; i<M.size()&&j>=0; i++, j--){
				if(M[i][j] == 1){
					tmp++;
				}
				else{
					if(tmp  > max_a) max_a = tmp;
					tmp = 0;
				}
			}
			if(tmp  > max_a) max_a = tmp;
		}
		for(int k=0; k<M.size(); k++){
			int tmp=0;
			for(int i=k, j=M[0].size(); i<M.size()&&j>=0; i++, j--){
				if(M[i][j] == 1){
					tmp++;
				}
				else{
					if(tmp  > max_a) max_a = tmp;
					tmp = 0;
				}
			}
			if(tmp  > max_a) max_a = tmp;
		}
		
		if(max_a > max) max = max_a;
	//	cout << max_a << endl;
		return max;

    }
};
