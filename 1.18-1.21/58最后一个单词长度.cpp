#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<char> strs(s.begin(), s.end());
        // 将字符串逆置后存储在字符数组
        reverse(strs.begin(), strs.end());
        int len = strs.size();
        //从后往前定位到第一个非空字符
        int i = 0;
        while (strs[i] == ' ') {
            i++;
        }
        int count = 0;
        // 当前元素不为空并且不是最后一个元素时count继续相加
        while (strs[i] != ' ' && i!=len-1) {
            count++;
            i++;
        }
        if(strs[i]!=' '){
        	return count+1;
    	}
    	else{
    		return count;
		}
    }
};


int main(){
	Solution solution;
	string origin = " aa ";
	int out = solution.lengthOfLastWord(origin);
	cout << out << endl;
	return 0;
}