#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            int larger;
            int j = i;
            while (j <= len-1 && nums[j] == nums[i]) {
                j++;
            }
            //如果不存在比当前值更大的数，直接返回
            if (j == len)
                return i+1;
            //如果存在比当前值大的数，先找到比当前值大最邻近数是多少
            else {
                larger = nums[j];
                if (j - i > 1) {
                    for (int k = i + 1; k < j; k++) {
                        nums[k] = larger;
                    }
                }
            }
        }
        return 0;
    }
};


int main(){
	Solution solution;
	vector<int> nums = {1};
	int out = solution.removeDuplicates(nums);
	cout << out << endl;
	return 0;
}