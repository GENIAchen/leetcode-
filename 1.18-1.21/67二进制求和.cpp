#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        vector<char> result;
        int carry = 0;
        
        int len_a = a.size();
        int len_b = b.size();
        
        int i = len_a - 1, j = len_b - 1;

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';

            result.push_back((sum % 2) + '0');
            carry = sum / 2;
        }

        string reversedString(result.rbegin(), result.rend());
        return reversedString;
    }
};


int main(){
	Solution solution;
	string a = "1010";
	string b = "1011";
	string outcome = solution.addBinary(a,b);
	cout << outcome << endl;
	return 0;
}


