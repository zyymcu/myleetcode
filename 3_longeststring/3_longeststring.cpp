// 3_longeststring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <string>
#include <set>
#include <unordered_set>
#include <cassert>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring1(string s) {
        int max = 0;
        int p = 0;//—”…Í∑∂Œß
        unordered_set<char> us;
        int i, j;
        for ( i = 0; i < s.length(); i++) {
            for ( j = p; j < s.length(); j++) {
                if (us.find(s[j]) != us.end()) {
                    p = j;                    
                    break;
                } else {
                    us.insert(s[j]);                    
                }            
            }
            max = std::max((int)us.size(), max);
            us.erase(s[i]);
        }
        return max;
    }
    int lengthOfLongestSubstring(string s) {
        int i, j;
        int ret = 0;
        unordered_map<char, int> map;
        for (i = 0, j = 0; j < s.length(); j++) {
            if (map.find(s[j]) != map.end()) {
                ret = max(ret, j - i);
                i = max(map[s[j]] + 1, i);
            }
            map[s[j]] = j;
        }
        ret = max(ret, j - i);
        return ret;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i + 1];
            switch (nextChar) {
            case '\"': result.push_back('\"'); break;
            case '/': result.push_back('/'); break;
            case '\\': result.push_back('\\'); break;
            case 'b': result.push_back('\b'); break;
            case 'f': result.push_back('\f'); break;
            case 'r': result.push_back('\r'); break;
            case 'n': result.push_back('\n'); break;
            case 't': result.push_back('\t'); break;
            default: break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);

        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}