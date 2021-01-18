#include <stdio.h>
#include <queue>
#include <string>
#include <iostream>
#include <map>
using namespace std;

struct task{
	string name;
	int priority;
	friend bool operator < (task a, task b){
		if(a.priority == b.priority){
			return a.name > b.name;		// 按名字的字典序升序 
		}
		else{
			return a.priority < b.priority;  // 按优先级降序 
		}
	}
};

int n, level;
map<string, int> mp;
priority_queue<task> q;

void deal(string str){
	
	string PreTask, BackTask;
	int i = 0;
	while(str[i] != '('){
		PreTask += str[i];
		i++; 
	} 
	if(!mp[PreTask]){
		// 写成 mp[PreTask] = level--也可以;
		mp[PreTask] = level;
	}
	i++;
	while(i < str.length()){
		while(str[i] != ',' && str[i] != ')'){
			BackTask += str[i++];
		}
		if(BackTask == "NULL"){
			return;
		}
		if(!mp[BackTask]){
			mp[BackTask] = (mp[BackTask] < mp[PreTask] - 1) ? mp[BackTask] : mp[PreTask] - 1;
		}
		else{
			mp[BackTask] = mp[PreTask] - 1;
		}
		BackTask.clear();
		i++;
	}
//	cout << level << endl;
}

int main(){
	while(cin >> n){
		level = n;
//		cout << level << endl;
		string str;
		for(int i = 0; i < n; i++){
			cin >> str;
			deal(str);
		}
//		for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++){
//			cout << it->first << " " << it->second << endl;
//		}
		for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++){
			task t;
			t.name = it->first;
			t.priority = it->second;
			q.push(t);
		}
		while(!q.empty()){
			cout << q.top().name;
			q.pop();
			if(q.size() > 0){
				cout << " ";
			}
			else{
				cout << endl;
			}
		}
	}
	return 0;
}
