// 458_poorpig.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
	int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
		int states = minutesToTest / minutesToDie + 1;
		return ceil(log(buckets) / log(states));
	}
};

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		int buckets = stringToInteger(line);
		getline(cin, line);
		int minutesToDie = stringToInteger(line);
		getline(cin, line);
		int minutesToTest = stringToInteger(line);

		int ret = Solution().poorPigs(buckets, minutesToDie, minutesToTest);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}