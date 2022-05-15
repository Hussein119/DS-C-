#include<iostream>
using namespace std;
int rFibNum(int a, int b, int n);
int Combinations(int group, int members);
void moveDisks(int count, int needle1, int needle3, int needle2);
int main() {

	//moveDisks(64, 1, 3, 2);

	cout << "Enter Integer " << endl;
	int input; cin >> input;
	if (input == 0) {
		cout << "Hello World" << endl;
		return 0;
	 }
	else if (input > 0) {
		for (int i = 0; i <= input; i++) {
			if ((i % 3 == 0) && (i % 5 == 0)) {
				cout << "Hello World" << endl;
				return 0;
			}
			else if (i % 3 == 0)
				cout << "Hello" << endl;
			else if (i % 5 == 0)
				cout << "world" << endl;
		}
	}
	
	else if (input < 0) {
		for (int i = 0; i >= input; i--) {
			if ((i % 3 == 0) && (i % 5 == 0)) {
				cout << "Hello World" << endl;
				return 0;
			}
			if (i % 3 == 0)
				cout << "Hello" << endl;
			if (i % 5 == 0)
				cout << "world" << endl;
		}

	}





	return 0; 
}
int rFibNum(int a, int b, int n)
{
	if (n == 1)
		return a;
	else if (n == 2)
		return b;
	else
		return rFibNum(a, b, n - 1) + rFibNum(a, b, n - 2);
}
int Combinations(int group, int members)
// Pre: group and members are positive.
// Post: Function value = number of combinations 
// of members size that can be constructed from the total group size.
{
	if (members == 1)
		return group; // Base case 1
	else if (members == group)
		return 1; // Base case 2
	else
		return (Combinations(group - 1, members - 1) +
			Combinations(group - 1, members));
}
void moveDisks(int count, int needle1, int needle3, int needle2)
{
	if (count > 0)
	{
		moveDisks(count - 1, needle1, needle2, needle3);
		cout << "Move disk " << count << " from " << needle1
			<< " to " << needle3 << "." << endl;
		moveDisks(count - 1, needle2, needle3, needle1);
	}
}