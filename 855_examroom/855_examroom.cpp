// 855_examroom.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
using namespace std;

class ExamRoom {
public:
	set<int> s;
	int n;

	ExamRoom(int N) {
		n = N;
	}

	int seat() {
		int dist = *s.begin(), pre = -1, student = 0;
		if (s.size() > 0) {
			for (auto i : s) {
				if (pre != -1) {
					int t = (i - pre) / 2;
					if (t > dist) {
						dist = t;
						student = pre + t;
					}
				}
				pre = i;
			}
			if (n - 1 - *s.rbegin() > dist) student = n - 1;
		}
		s.insert(student);
		return student;
	}

	void leave(int p) {
		s.erase(p);
	}
};
int main() {
	ExamRoom* obj = new ExamRoom(5);
	int param_1 = obj->seat();
	obj->leave(0);
	delete obj;
}
