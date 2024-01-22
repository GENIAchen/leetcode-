#include<iostream>
#include<vector>
#include<stack>
#include<map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
		map<char,int> dic;
		dic['I'] = 1;
		dic['V'] = 5;
		dic['X'] = 10;
		dic['L'] = 50;
		dic['C'] = 100;
		dic['D'] = 500;
		dic['M'] = 1000;
		// 范围构造函数
		vector<char> str0(s.begin(), s.end());
		int n = str0.size();
		stack<char> str1;
		for(int i=0;i<n;i++){
			str1.push(str0[i]);
		}
		int outcome = 0;
		while(!str1.empty()){
			char tmp = str1.top();
			str1.pop();
			if(!str1.empty() && dic[tmp] <= dic[str1.top()]){
				outcome += dic[tmp];
			}
			else{
				if(str1.empty()){
					outcome += dic[tmp];
				}
				else{
				outcome += dic[tmp] - dic[str1.top()];
				str1.pop();
				}
			}
		}
		return outcome;
    }
};

int main(){
	Solution solution;
	string s;
	cin >> s;
	int out = solution.romanToInt(s);
	cout << out << endl;
	return 0;
	
}