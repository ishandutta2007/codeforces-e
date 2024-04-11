#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 4e6;
int dig[N];
int ans[10][151];
int ans1[] = {-1,0,-1,1,-1,2,-1,3,-1,4,9,5,19,6,29,7,39,8,49,18,59,28,69,38,79,48,89,58,189,68,289,78,389,88,489,98,589,198,689,298,789,398,889,498,989,598,1989,698,2989,798,3989,898,4989,998,5989,1998,6989,2998,7989,3998,8989,4998,9989,5998,19989,6998,29989,7998,39989,8998,49989,9998,59989,19998,69989,29998,79989,39998,89989,49998,99989,59998,199989,69998,299989,79998,399989,89998,499989,99998,599989,199998,699989,299998,799989,399998,899989,499998,999989,599998,1999989,699998,2999989,799998,3999989,899998,4999989,999998,5999989,1999998,6999989,2999998,7999989,3999998,8999989,4999998,9999989,5999998,19999989,6999998,29999989,7999998,39999989,8999998,49999989,9999998,59999989,19999998,69999989,29999998,79999989,39999998,89999989,49999998,99999989,59999998,199999989,69999998,299999989,79999998,399999989,89999998,499999989,99999998,599999989,199999998,699999989,299999998,799999989,399999998,899999989};
ll ans0[151];

void pre(){
	dig[0] = 0;
	for(int n = 1; n < N; n++){
		dig[n] = dig[n/10] + n%10;
	}
	for(int k = 2; k <= 9; k++){
		for(int x = 0; x <= 150; x++){
			ans[k][x] = -1;
		}
		for(int x = 0; x + k < N; x++){
			int sum = 0;
			for(int i = 0; i <= k; i++){
				sum += dig[x + i];
			}
			if(sum <= 150 && ans[k][sum] == -1)ans[k][sum] = x;
		}
	}
	for(int x = 0; x <= 150; x++){
		ans0[x] = 0;
		vector<int> dig;
		int y = x;
		while(y){
			if(y >= 9){
				dig.push_back(9);
				y -= 9;
			}else{
				dig.push_back(y);
				y = 0;
			}
		}
		reverse(dig.begin(), dig.end());
		for(int i = 0; i < dig.size(); i++){
			ans0[x] = ans0[x]*10 + dig[i];
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	pre();
	int t;
	cin>>t;
	while(t--){
		int k, n;
		cin>>n>>k;
		if(k >= 2)cout<<ans[k][n]<<'\n';
		else if(k == 1)cout<<ans1[n]<<'\n';
		else cout<<ans0[n]<<'\n';
	}

	return 0;
}