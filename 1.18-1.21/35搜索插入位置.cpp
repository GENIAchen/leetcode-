#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target){
		int size = nums.size();
		if(size == 0){
			return 0;
		}
		else if(target <= nums[0]){
			return 0;
		}
		else if(nums[size-1] < target){
			return size;
		}
		else{
			for(int i = 0;i<size-1;i++){
				if(nums[i] < target && nums[i+1] >= target){
					return i+1;
				}
			}
		}
		return -1;
    }
};

int main(){
	Solution solution;
	vector<int>origin = {1,3,5,6};
	int target = 7;
	int out = solution.searchInsert(origin,target);
	cout << out << endl;
	return 0;
}