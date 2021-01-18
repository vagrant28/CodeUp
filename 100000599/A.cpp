#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
using namespace std;

bool isChar(char c){
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

char low(char c){
	if(c >= 'A' && c <= 'Z'){
		return c - 'A' + 'a';
	}
	else{
		return c;
	}
}

int main(){
	string s;
	while(getline(cin, s)){
		map<string, int> mp;
		string word;
		// 原本的错误在于，最后结尾的单词（即后面不跟随非字母数字符号），会不计入统计。 
		for(int i = 0; i < s.length(); i++){
			if(isChar(s[i])){
				word.push_back(low(s[i]));
			}
			if(!isChar(s[i]) || i == s.length() - 1){
				if(word.length() > 0){
					map<string, int>::iterator it = mp.find(word);
					if(it != mp.end()){
						mp[word]++;
					}
					else{
						mp[word] = 1;
					}
				}
				word.clear();
			}
		}
//		cout << mp.size() << endl; 
//		for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++){
//			cout << it->first << " " << it->second << endl;
//		}
		string ans; 
		int max = 0;
		for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++){
			if(it->second > max){
				max = it->second;
				ans = it->first;
			}
		}
		cout << ans << " " << max << endl;
	}
	return 0;
}
