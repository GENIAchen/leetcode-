#include<iostream>
#include<vector>

using namespace std;

// 暴力循环求解
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i+1 ; j < n; j++) {
                if (nums[i] + nums[j] == target){
                    result[0] = i;
                    result[1] = j;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    vector<int> result = solution.twoSum(nums, target);

    if (result[0] != -1 && result[1] != -1) {
        cout << "[" << result[0] << "," << result[1] << "]" << endl;
    } else {
        cout << "No found." << endl;
    }

    return 0;
}
