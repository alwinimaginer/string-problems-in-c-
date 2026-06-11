/*
338. Counting Bits
Easy
Topics
premium lock icon
Companies
Hint
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
 

Constraints:

0 <= n <= 105

*/
 // BRUTE FORCE APPROACH 
class Solution {
public:
    vector<int> countBits(int n) {
        int count = 0;
        vector<int> arr;
        for(int i = 0; i <= n ; i ++){
            int temp = i;
            while(temp > 0){
                if(temp % 2 != 0){
                    count ++;
                }
                temp = temp /2;
            }
          arr.push_back(count);
          count = 0;
        }
        return arr;
    }
};
 
