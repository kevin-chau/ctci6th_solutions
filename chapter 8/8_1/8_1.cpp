#include <iostream>
#include <chrono>
using namespace std;

int memo[100] = {0};

int numWaysMEMO(int numSteps) {
    if (numSteps == 1) {
        return 1;
    }

    if (numSteps == 2) {
        return 2;  // 1 + 1 OR 2
    }

    if (numSteps == 3) {
        return 4;  // 1+1+1, 1+2, 2+1, 3
    }

    // MEMOIZE
    if (memo[numSteps] == 0) {
        memo[numSteps] = numWaysMEMO(numSteps - 1) + numWaysMEMO(numSteps - 2) + numWaysMEMO(numSteps - 3);
    }

    return memo[numSteps];
}

int numWays(int numSteps) {
    if (numSteps == 1) {
        return 1;
    }

    if (numSteps == 2) {
        return 2; // 1 + 1 OR 2
    }

    if (numSteps == 3) {
        return 4; // 1+1+1, 1+2, 2+1, 3 
    }

    return numWays(numSteps - 1) + numWays(numSteps - 2) + numWays(numSteps - 3);
}
// 4 steps: numWays(3) + numWays(2) + numWays()
// 1+1+1+1, 1+2+1, 2+1+1, 3+1
// 1+1+2, 2+2,
// 1+3

// 5 steps:
// 1+1+1+1+1, 1+2+1+1, 2+1+1+1, 3+1+1
// 1+1+2+1, 2+2+1,
// 1+3+1
// 1+1+1+2, 1+2+2, 2+1+2, 3+2
// 1+1+3, 2+3

// N steps: numWays(n-1) + numWays(n-2) + numWays(n-3)


int main() {
    cout << "Number of ways to climb 4 stairs: " << numWays(4) << endl;
    cout << "Number of ways to climb 5 stairs: " << numWays(5) << endl;

    // 36 is the largest number of stairs we can calculate before overflow, also shows how memoization is faster
    int start = time(nullptr);
    cout << "Number of ways to climb 36 stairs: " << numWays(36) << endl;
    int end = time(nullptr);
    cout << "took " << end - start << " seconds to calculate unmemoized" << endl;
    start = time(nullptr);
    cout << "Number of ways to climb 36 stairs: " << numWaysMEMO(36) << endl;
    end = time(nullptr);
    cout << "took " << end - start << " seconds to calculate memoized" << endl;
    cout << "Number of ways to climb 100 stairs (memoized): " << numWaysMEMO(100) << endl;
    return 0;
}