#include <stdio.h>
#include <stack>
#include <string>
#include <iostream>
#include <map>
using namespace std;

int main(){
	map<char, char> mp;
	mp[')'] = '(';
	mp['}'] = '{';
	mp[']'] = '['; 
	int n;
	scanf("%d", &n);
	while(n--){
		string s;
		cin >> s;
		stack<char> st;
		int flag = 1;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
				st.push(s[i]);
			}
			else if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
				if(st.empty()){
					flag = 0;
					break;
				}
				else if(mp[s[i]] != st.top()){
					flag = 0;
					break;
				}
				else{
					st.pop();
				}
			}
		}
		if(st.empty() && flag){
			cout << "yes" << endl;
		}
		else{
			cout << "no" << endl;
		}
	} 
	return 0;
}
