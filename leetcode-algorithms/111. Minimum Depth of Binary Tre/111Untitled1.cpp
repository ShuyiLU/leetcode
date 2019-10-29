vector<int> get_factor(int cur) {
	vector<int> res;
	int ed = sqrt(cur) + 1;
	for (int i = 2; i <= ed; i++) {
		if (cur % i == 0) {
			res.push_back(i);
			while (cur % i == 0) {
				cur /= i;
			}
		}
	}
	if (cur != 1) res.push_back(cur);
	return res;
} 

int calculateTotalRotorConfiguration(int rotorCount, int minRotorValue, int maxRotorValue) {
	int res = 0;
	const int MOD_NUM = 1000000000 + 7; 
	
	for (int cur = minRotorValue; cur <= maxRotorValue; cur++) {
		vector<int> prime_factor = get_factor(cur);
		long long num = 0;
		for (int s = 0; s < (1 << prime_factor.size()); s++) {
			int tmp = s;
			int prod = 1;
			int cnt = 0;
			int k = 1;
			while (tmp > 0) {
				if (tmp & 1) {
					prod *= prime_factor[cnt];
				}
				tmp >>= 1;
				cnt++;
				k = -k;
			}
			num += k * (maxRotorValue / prod - (minRotorValue - 1) / prod);
		}
		
		
		long long cur_res = 1;
		for (int i = 0; i < rotorCount - 1; i++) {
			cur_res = cur_res * num % MOD_NUM;
		}
		res = (res + cur_res) % MOD_NUM;
	}
	return res;
} 
