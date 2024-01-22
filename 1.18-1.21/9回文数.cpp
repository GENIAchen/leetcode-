#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> nums(10, -1);
        if (x < 0)
            return false;
        else{
            while(x/10 != 0){
                nums.insert(nums.begin(),x%10);
                x /= 10;
            }
            nums.insert(nums.begin(),x);
            int len = 0;
            for(int k=0;k<10;k++){
            	if(nums[k]!= -1){
            		len ++;
				}
			}
            int p = 0;
            int q = len -1;
            while(p!=q && p < q){
                if(nums[p] == nums[q] ){
                    p += 1;
                    q -= 1;
                }
                else{
                    return false;
                }
            }
            if( p >= q){
                return true;
            }
        }
        return false;
    }
};


int main(){
	int k = 11;
	Solution solution;
	bool result = solution.isPalindrome(k);
	if(result == 0){
		cout << "false" << endl;
	}
	else{
		cout << "true" << endl;
	}
	return 0;
}