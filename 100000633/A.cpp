#include <iostream>
#include <vector>
#include <string>
#include <utility> 
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const LL P = 1e7 + 19;
const LL MAXN = 1e3 + 10;

struct node{
	int hashValue, len, s, t;
	node(){}
	node(int _h, int _len, int _s, int _t): hashValue(_h), len(_len), s(_s), t(_t){}
};


LL powP[MAXN], H1[MAXN], H2[MAXN];
vector<node> pr1, pr2;
string str1, str2;

void init(){
	powP[0] = 1;
	for(int i = 1; i < MAXN; i++){
		powP[i] = (powP[i - 1] * P) % MOD;
	}
}

void calH(LL H[], string &str){
	H[0] = str[0];
	for(int i = 0; i < str.length(); i++){
		H[i] = (H[i - 1] * P + str[i]) % MOD;
	}
}

int calSingleSubH(LL H[], int i, int j){
	if(i == 0){
		return H[j];
	}
	else{
		return ((H[j] - H[i - 1] * powP[j - i + 1]) % MOD + MOD) % MOD;
	}
}

void calSubH(LL H[], int len, vector<node> &pr){
	for(int i = 0; i < len; i++){
		for(int j = 0; j < len; j++){
			pr.push_back(node(calSingleSubH(H, i, j), j - i + 1, i, j));
		}
	}
}

void getMax(){
	int maxLen = 0, s, t;
//	printf("pr1.size=%d, pr2.size=%d\n", pr1.size(), pr2.size());
	for(int i = 0; i < pr1.size(); i++){
		for(int j = 0; j < pr2.size(); j++){
			if(pr1[i].hashValue == pr2[j].hashValue){
				if(maxLen < pr1[i].len){
					maxLen = pr1[i].len;
					s = pr1[i].s;
					t = pr1[i].t;
				}
			}
		}
	}
//	printf("maxLen=%d, s=%d, t=%d\n", maxLen, s, t);
	cout << str1.substr(s, t - s + 1) << endl;
}


int main(){
	init();	
	while(cin >> str1 >> str2){
		init();
		calH(H1, str1);
		calH(H2, str2);
		pr1.clear();
		pr2.clear();
		calSubH(H1, str1.length(), pr1);
		calSubH(H2, str2.length(), pr2);
		getMax();
	}
	return 0;
}
