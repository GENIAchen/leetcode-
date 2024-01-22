#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
		int len = digits.size();
		int i = len-1;
		while(i>=0 && digits[i]+1==10){
			digits[i] = 0;
			i--;
		}
		if(i<0){
			digits.insert(digits.begin(),1);
		}
		else{
			digits[i]++;
		}
		return digits;
    }
};

int main(){
	Solution solution;
	vector<int> numbers = {9,9,9,9};
	vector<int> outcome = solution.plusOne(numbers);
	int length = outcome.size();
	for(int i = 0;i<length;i++){
		cout << outcome[i] << ' ';
	}
	return 0;
	
}
