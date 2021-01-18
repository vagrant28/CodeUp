#include <stdio.h>
#include <stack>
#include <map>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct item {
	double num;	// 记录操作数 
	char op;	// 记录操作符 
	bool flag;	// true表示操作数，false表示操作符 
};

double n;
string s;
stack<item> st;	// 后序表达式队列 
queue<item> q;	// 操作符栈 
map<char, int> mp;	// 存储操作符优先级，数字大的优先级高 

void change(){
	double num = 0;
	item tmp;
	int i = 0;
	while(i < s.length()){
//		cout << "*" << endl;
		double num = 0;
		while(s[i] >= '0' && s[i] <= '9' && i < s.length()){
			num = num * 10 + s[i] - '0';
			i++;
		}	
//		cout << num << endl; 
		tmp.num = num;
		tmp.flag = true;
		q.push(tmp);
		
		if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
			tmp.op = s[i];
//			cout << tmp.op << endl;
			tmp.flag = false;
			while(!st.empty() && mp[s[i]] <= mp[st.top().op]){
				q.push(st.top());
				st.pop();
			}
			st.push(tmp);
//			cout << "i = " << i << endl;
		}	
		i++;
	}
	while(!st.empty()){
		q.push(st.top());
		st.pop();
	}
//	cout << "size: " << q.size() << endl;
//	while(!q.empty()){
//		if(q.front().flag == true){
//			cout << q.front().num << " ";
//		}
//		else{
//			cout << q.front().op << " ";
//		}
//		q.pop(); 
//	} 
}

double cal(){
	double tmp1, tmp2;
	item cur, tmp;
	while(!q.empty()){
		cur = q.front();
		q.pop();
		if(cur.flag == true){
			st.push(cur);
		}
		else{
			tmp2 = st.top().num;
			st.pop();
			tmp1 = st.top().num;
			st.pop();
			tmp.flag = true;
			if(cur.op == '+'){
				tmp.num = tmp1 + tmp2;
			}
			else if(cur.op == '-'){
				tmp.num = tmp1 - tmp2;
			}
			else if(cur.op == '*'){
				tmp.num = tmp1 * tmp2;
			}
			else if(cur.op == '/'){
				tmp.num = tmp1 / tmp2;
			}
			st.push(tmp);
		}
	}
	return st.top().num;
}

int main(){
	mp['+'] = 1;
	mp['-'] = 1;
	mp['*'] = 2;
	mp['/'] = 2;
	while(1){
		getline(cin, s);
		if(s == "0"){
			break;
		}
		for(string::iterator it = s.end(); it != s.begin(); it--){
			if(*it == ' '){
				s.erase(it);
			}
		}
//		cout << s << endl;
		while(!st.empty()){
			st.pop();
		}
		change();
		double ans = cal();
		printf("%.2f\n", ans);
	} 
	return 0;
}
