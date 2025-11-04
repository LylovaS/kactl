/**
 * Author: Somebody
 * Date: Somewhen
 * License: CC0
 * Description: Description: Example of usage custom comparator with set and priority queue.
 * Status: Tested
 */
#pragma once

// Method 1
struct compare {
	bool operator() (const pii &lhs, const pii &rhs) const {
		return (lhs.second-lhs.first > rhs.second-rhs.first);
	}
};
set<pii, compare> myset1;
set<pii, greater<>> myset2;
// Method 2
// if you have bool function
bool compareF(const pii &lhs, const pii &rhs) {
	return (lhs.second-lhs.first > rhs.second-rhs.first);
}
set<pii, bool(*)(const pii &lhs, const pii &rhs)> myset3(&compareF);
// priority queue with least element at top
priority_queue<pii, vector<pii>, greater<>> q1;