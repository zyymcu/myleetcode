// 1_twosum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> hash;//num,index
		for (int i = 0; i < nums.size(); i++) {
			if (hash.find(target - nums[i]) != hash.end()) {
				return { hash[target - nums[i]],i };
			} else {
				hash[nums[i]] = i;
			}
		}
		return {};
	}
};
int main() {
	Solution s;
	vector<int> test = { 2, 7, 11, 15 };
	vector<int> ret = s.twoSum(test, 9);
	for (int i : ret) {
		printf("%d\n", i);
	}
}

