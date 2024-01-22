#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
    	vector<char> son(needle.begin(),needle.end());
    	vector<char> father(haystack.begin(),haystack.end());
    	int len_son = son.size();
    	int len_father = father.size();
    	int time = len_father - len_son + 1;
    	for(int j = 0;j < time;j++){
    		int k;
    		for(k = 0;k<len_son;k++){
    			if(k!=len_son && father[j+k] != son[k]){
    				break;
				}
			}
			if(k == len_son){
				return j;
			}
		}
		return -1;
    }
};

int main(){
	Solution solution;
	string father = "leetcode";
	string son = "etck";
	int out = solution.strStr(father,son);
	cout << out << endl;
	return 0;
}


