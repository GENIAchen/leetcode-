#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	//计算出字符串数组中最短字符串的长度
    	int num = strs.size();
    	int min_len = 201;
    	for(int i = 0;i < num;i++){
    		min_len = min(min_len,static_cast<int>(strs[i].length()));
		}
		
		vector<std::vector<char>> arr;
		//将字符串数组转化为二维数组
		for(int i = 0;i < num;i++){
			vector<char> tmp_arr(strs[i].begin(), strs[i].end());
			arr.push_back(tmp_arr);
		}

		string outcome;
		for(int j = 0;j < min_len;j++){
			for(int k = 0;k < num-1;k++){
				if(arr[k][j]!=arr[k+1][j]){
					return outcome;
				}
			}
			outcome.push_back(arr[0][j]);
		}
		return outcome;
    }
};

int main(){
	vector<string> strings = {"dog","racecar","car"};
	Solution solution;
	string out  = solution.longestCommonPrefix(strings);
	cout << '"' << out << '"' <<endl;
	return 0;
}