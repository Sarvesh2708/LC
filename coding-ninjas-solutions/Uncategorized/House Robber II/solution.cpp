#include <bits/stdc++.h>
using namespace std;

long long maxadjsum(vector<int>& temp) {
    int n = temp.size();

    if(n == 0) return 0;

    long long prev = temp[0];
    long long prev2 = 0;

    for(int i = 1; i < n; i++) {

        long long take = temp[i];

        if(i > 1)
            take += prev2;

        long long nottake = prev;

        long long curr = max(take, nottake);

        prev2 = prev;
        prev = curr;
    }

    return prev;
}

long long int houseRobber(vector<int>& valueInHouse) {

    int n = valueInHouse.size();

    if(n == 0) return 0;

    if(n == 1) return valueInHouse[0];

    vector<int> temp1, temp2;

    for(int i = 0; i < n; i++) {

        if(i != 0)
            temp1.push_back(valueInHouse[i]);

        if(i != n-1)
            temp2.push_back(valueInHouse[i]);
    }

    return max(maxadjsum(temp1), maxadjsum(temp2));
}