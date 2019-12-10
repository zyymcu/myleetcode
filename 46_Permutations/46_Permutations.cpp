// 46_Permutations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
	vector<vector<int>> result;
	vector<vector<int>> permute(vector<int>& nums) {
		helper({}, nums);
		return result;
	}
	void helper(vector<int> route,vector<int> choices) {
		if (choices.size() == 0) {
			result.push_back(route);
			return;
		}
		for (int i = 0; i < choices.size();i++) {
			int choice = choices[i];
			route.push_back(choice);
			choices.erase(choices.begin()+i);
			helper(route, choices);
			route.pop_back();
			choices.insert(choices.begin() + i, choice);
		}
	}
};



int main()
{	
	vector<int> test = {1,2,3,4};
	vector<vector<int>>  ret = Solution().permute(test);
	
	for (int i = 0; i < ret.size(); i++) {
		std::cout << i << ": ";
		for (int j = 0; j < ret[i].size(); j++) {
			std::cout <<ret[i][j] <<",";
		}
		std::cout << endl;
	}	
}

