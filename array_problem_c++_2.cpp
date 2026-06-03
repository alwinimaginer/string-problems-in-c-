/* 238. Product of Array Except Self
Attempted
Medium
Topics
premium lock icon
Companies
Hint
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30

  */
// method 1 : (brute force )
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> product;
        int n = nums.size();
       

        for(int i = 0; i < n ; i ++){
             int prod = 1;
            for(int j = 0; j < n; j++){
                if(j != i){
                    prod *= nums[j];
                }
            }
            product.push_back(prod);
        }
        return product;
    }
};

// method 2: (prefix and suffix products)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> product(n,1);


        // prefix products , here we skip product[0] because considering only prefix it is 1. think
        for(int i = 1; i < n; i ++ ){

            product[i] = product[i-1] * nums[i-1];
        }
        
        // suffix products , we come from the reverse order. first prefix then suffix.
        // two separate loops , not nested loops like in brute force.
        int right = 1;
        for(int i = n -1 ; i >= 0; i --){
           product[i] *= right;
           right *= nums[i];
        }
        return product;
    }
};
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.
 
