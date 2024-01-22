#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		int len = nums.size();
		// 找出 val元素的个数
		int number = count(nums.begin(),nums.end(),val);
		if(number == 0){
			return len;
		}
		else{
			int tole = len;
			for(int i = 0;i < number;i++){
				int j = 0;
				while(nums[j]!=val){
					j++;
				}
				for(int k = j;k< tole -1;k++){
					swap(nums[k],nums[k+1]);
				}
				tole--;
			}
			return tole;
		}
		return 0;
    }
};

int main(){
	Solution solution;
	vector<int> origin = {3,2,2,3};
	int val = 3;
	int out = solution.removeElement(origin,val);
	cout << out << endl;
	return 0;
}


