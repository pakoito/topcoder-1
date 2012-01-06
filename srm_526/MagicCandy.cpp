// BEGIN CUT HERE
/*
// SRM 526.5 Div2 Medium (500)
// PROBLEM STATEMENT
// Today is the Christmas Eve. People around the world celebrate this holiday.
The following story takes place in the land of reindeer, where Santa Claus resides.

The reindeer love candies. They have n pieces of candy. The pieces of candy are numbered 1 through n.
Dasher is one of the reindeer. He wants to eat one of the candies. To pick the one he will eat,
Dasher uses the following method:

While there is more than one piece of candy:
Discard all candies that are numbered by perfect squares (i.e., candies 1, 4, 9, 16, 25, etc.).
Relabel the remaining k candies 1 through k, keeping the numbers in the same order.
Once only one piece of candy remains, Dasher will eat it.

You are given an int n. Your method must compute and return the number
initially assigned to the piece of candy eaten by Dasher.

DEFINITION
Class:MagicCandy
Method:whichOne
Parameters:int
Returns:int
Method signature:int whichOne(int n)


NOTES
-It can be proved that Dasher's method will always lead to a situation
in which only one piece of candy remains.


CONSTRAINTS
-n will be between 1 and 1,000,000,000 inclusive.


EXAMPLES

0)
5

Returns: 5

We start with 5 candies. Let's call them A, B, C, D, and E. Initially, they are numbered 1 through 5, in this order.

In the first round, we discard candies with numbers 1 (which is A) and 4 (which is D).
This leaves us with candies B, C, and E.
These candies now get new numbers: B becomes 1, C becomes 2, and E becomes 3.
In the second round, we discard candy number 1 (which is now B).
This leaves us with candies C and E.
Again, the candies now get new numbers: C becomes 1 and E becomes 2.
In the third round, we discard candy number 1 (which is now C).

The only remaining candy is E. Its number in the beginning was 5, therefore our method should return 5.

1)
9

Returns: 7

This time we start with 9 pieces of candy. If we label them A through I, the process will look as follows:

start: ABCDEFGHI
throw away candies 1, 4, 9 (A, D, I)
after the first round: BCEFGH
throw away candies 1, 4 (B, F)
after the second round: CEGH
throw away candies 1, 4 (C, H)
after the third round: EG
throw away candy 1 (E)
at the end: G


2)
20

Returns: 17



3)
5265

Returns: 5257



4)
20111223

Returns: 20110741



5)
1

Returns: 1



#line 104 "MagicCandy.cpp"
*/
// END CUT HERE
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<string> StrVec;

class MagicCandy {

public:
	int whichOne(int n) {
		int x[32000];
		int i;
		for (i = 0; i < 32000; ++i) {
			x[i] = i*i;
		}

		int result = n;
		int *p = lower_bound(x + 1, x + 32000, n);
		int d = p - x;
		while (n > 1) {
			if (n < *p) {
				--p;
				--d;
			} else {
				if (n == *p) {
					--result;
				}
				n -= d;
			}


/*
			while (n < *p) {
				--p;
				--d;
			}
			while (n > 1 && n >= *p) {
				if (n == *p) {
					--result;
				}
				n -= d;
			}
*/
		}

		return result;
	}

	
// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 5;

			verify_case(n, Arg1, whichOne(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 9;
			int Arg1 = 7;

			verify_case(n, Arg1, whichOne(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 20;
			int Arg1 = 17;

			verify_case(n, Arg1, whichOne(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5265;
			int Arg1 = 5257;

			verify_case(n, Arg1, whichOne(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 20111223;
			int Arg1 = 20110741;

			verify_case(n, Arg1, whichOne(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;

			verify_case(n, Arg1, whichOne(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;

			verify_case(n, Arg1, whichOne(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MagicCandy ___test;

//	___test.run_test(1);

	___test.run_test(-1);
	return 0;
}
// END CUT HERE
