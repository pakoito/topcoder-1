// BEGIN CUT HERE
/*
// SRM 513 Div2 Easy (250)
// PROBLEM STATEMENT
// Manao conducted a training camp in Bazaleti to prepare students for programming contests.
The camp lasted for M days and was attended by N students.
Each day, a lecture on a separate topic was delivered. Some of the students did not attend on particular days.
You are given a vector <string> attendance containing N elements, each of them M characters long.
The j-th character in the i-th element of attendance is 'X' if the i-th student attended on the j-th day
and '-' otherwise.

Now Manao is going to arrange a contest comprised of K problems.
Some problems are ad hoc and require no special knowledge, some need a specific topic which was analyzed
at the camp and some combine several topics from the camp. This information is given in vector <string>
problemTopics, which contains K elements of length M. 
The j-th character in the i-th element of problemTopics is 'X' if problem i requires knowledge of the topic
that was taught on the j-th day of the camp and '-' otherwise.

Manao wants an estimate on which students should solve which of the problems.
He reckons that a student should solve a problem if he attended on each of the days when the topics
needed for the problem were analyzed.
Return a vector <string> containing N elements containing K characters each.
The j-th character in the i-th row should be 'X' if student i should solve problem j by Manao's estimate
and '-' otherwise.

DEFINITION
Class:TrainingCamp
Method:determineSolvers
Parameters:vector <string>, vector <string>
Returns:vector <string>
Method signature:vector <string> determineSolvers(vector <string> attendance, vector <string> problemTopics)


CONSTRAINTS
-attendance will contain between 1 and 50 elements, inclusive.
-Each element of attendance will contain between 1 and 50 characters, inclusive.
-All elements of attendance will be of the same length.
-Each character in attendance will be either '-' or 'X'.
-problemTopics will contain between 1 and 50 elements, inclusive.
-Each element of problemTopics will contain the same number of characters as attendance[0].
-Each character in problemTopics will be either '-' or 'X'.


EXAMPLES

0)
{"XXX",
 "XXX",
 "XX-"}
{"---",
 "XXX",
 "-XX",
 "XX-"}

Returns: {"XXXX", "XXXX", "X--X" }

The camp lasted for three days and had three attendees.
The first two of them have listened to all the lectures and the third one missed the camp's last day.
Of the four problems Manao is going to set for the contest, problem 0 requires no special knowledge,
problem 1 combines all three topics taught at the camp and the other two problems are a blend of two
of those techniques. Students 0 and 1 should be able to solve all problems, while student 2 is estimated
to fail problems 1 and 2 because they both need the topic considered on the last day of the camp.

1)
{"-XXXX",
 "----X",
 "XXX--",
 "X-X-X"}
{"X---X",
 "-X---",
 "XXX--",
 "--X--"}

Returns: {"-X-X", "----", "-XXX", "X--X" }

The camp comprised five days and was attended by four students. Student 0 should solve problems 1 and 3, student 1 is expected to solve nothing, student 2 should solve all problems but the first one and student 3 should solve problems 0 and 3.

2)
{"-----",
 "XXXXX"}
{"XXXXX",
 "-----",
 "--X-X"}

Returns: {"-X-", "XXX" }

Student 0 attended no lectures, but he should still be able to solve problem 1.

3)
{"-",
 "X",
 "X",
 "-",
 "X"}
{"-",
 "X"}

Returns: {"X-", "XX", "XX", "X-", "XX" }



4)
{"X----X--X",
 "X--X-X---",
 "--X-X----",
 "XXXX-X-X-",
 "XXXX--XXX"}
{"X----X-X-",
 "-----X---",
 "-X----X-X",
 "-X-X-X---",
 "-----X---",
 "X-------X"}

Returns: {"-X--XX", "-X--X-", "------", "XX-XX-", "--X--X" }



#line 101 "TrainingCamp.cpp"
*/
// END CUT HERE
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

class TrainingCamp {

public:
	vector <string> determineSolvers(vector <string> attendance, vector <string> problemTopics) {
		vector <string> result;
		int i, j, k;
		for (i = 0; i < (int)attendance.size(); ++i) {
			const string &a = attendance[i];
			string res;
			for (j = 0; j < (int)problemTopics.size(); ++j) {
				bool ok = true;
				const string &t = problemTopics[j];
				for (k = 0; k < (int)t.length(); ++k) {
					if (t[k] == 'X' && a[k] != 'X') {
						ok = false;
					}
				}
				res += ok ? 'X' : '-';
			}
			result.push_back(res);
		}
		return result;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"XXX",
 "XXX",
 "XX-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"---",
 "XXX",
 "-XX",
 "XX-"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"XXXX", "XXXX", "X--X" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, determineSolvers(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"-XXXX",
 "----X",
 "XXX--",
 "X-X-X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"X---X",
 "-X---",
 "XXX--",
 "--X--"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"-X-X", "----", "-XXX", "X--X" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, determineSolvers(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"-----",
 "XXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"XXXXX",
 "-----",
 "--X-X"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"-X-", "XXX" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, determineSolvers(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"-",
 "X",
 "X",
 "-",
 "X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"-",
 "X"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"X-", "XX", "XX", "X-", "XX" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, determineSolvers(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"X----X--X",
 "X--X-X---",
 "--X-X----",
 "XXXX-X-X-",
 "XXXX--XXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"X----X-X-",
 "-----X---",
 "-X----X-X",
 "-X-X-X---",
 "-----X---",
 "X-------X"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"-X--XX", "-X--X-", "------", "XX-XX-", "--X--X" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, determineSolvers(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TrainingCamp ___test;
	___test.run_test(0);
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
