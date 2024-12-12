/**
 * Author: Sophia Lylova
 * Date: 2024-12-11
 * License: CC0
 * Source: CPP reference
 * Description: Example of usage custom comparator with set and priority queue.
 * Status: tested
 */
#pragma once

// Method 1
struct compare {
    bool operator() (const pair<int,int> &lhs, const pair<int,int> &rhs) const{
         return (lhs.second-lhs.first > rhs.second-rhs.first);
    }
};

set<pair<int,int>, compare> myset1;
set<pair<int,int>, greater<>> myset2;

// Method 2
// if you have bool function
bool compareF(const pair<int,int> &lhs, const pair<int,int> &rhs) {
         return (lhs.second-lhs.first > rhs.second-rhs.first);
    }

set<pair<int,int>, bool(*)(const pair<int,int> &lhs,
                           const pair<int,int> &rhs)
   > myset3(&compareF);

// priority_queue with least element at top
priority_queue<pii, vector<pii>, greater<>> q1;

