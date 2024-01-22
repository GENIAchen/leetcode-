#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
		vector<char> str_arr(s.begin(),s.end());
		stack<char> st;
		int len  = str_arr.size();
		for(int i=0;i<len;i++){
			if(str_arr[i] == '(' || str_arr[i] == '[' || str_arr[i] == '{'){
				st.push(str_arr[i]);
			}
			if((str_arr[i] == ')' || str_arr[i] == ']' || str_arr[i] == '}')&&st.empty()){
				return false;
			}
			if(str_arr[i] == ')'&&!st.empty()){
				if(st.top()=='('){
					st.pop();
				}
				else{
					return false;
				}
			}
			if(str_arr[i] == ']'&&!st.empty()){
				if(st.top()=='['){
					st.pop();
				}
				else{
					return false;
				}
			}
			if(str_arr[i] == '}'&&!st.empty()){
				if(st.top()=='{'){
					st.pop();
				}
				else{
					return false;
				}
			}
		}
		if(st.empty()){
			return true;
		}
		return false;		
    }
};

int main(){
	Solution solution;
	string s = "()";
	bool out = solution.isValid(s);
	cout << out << endl;
	return 0;
}


