#include<iostream>
#include<vector>
using namespace std;
int main() {
	cout << "hello";
	vector<int>v;
	v.push_back(4);
	for (auto x : v)
		cout << x;
	return 0;
