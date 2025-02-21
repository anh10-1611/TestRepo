#include<iostream>
#include<vector>

using namespace std;

//This is the function to assign all elements of fwTree to 0 to make it easier to create and adjust
void deploy(vector<int> fTree);

//This is the function to increase elements within the 2's complement method 
void increment(vector<int>& fTree, int i, int val);

//This is the function to calculate the sum from element 0 to element N in the initial array
int sumZeroToN(vector<int> fTree, int n);

//This is the function to calculate the sum from element b to element e in the initial array by subtracting sumZeroTo_b-1 from sumZeroTo_e
int sumUp(vector<int> fTree, int b, int e);

//This is the function to printout all elements in the tree
void display(vector<int> fTree);

//This is the function to display the menu
void menu();

int main() {
	int n;
	cout << "how many numbers in the array? "; cin >> n;
	vector<int> arr(n);
	cout << "\nPlease input your array\n";

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> fwTree(n + 1);
	deploy(fwTree);
	
	//This is used to add elements to the Fenwick tree
	for (int i = 0; i < arr.size(); i++) {
		increment(fwTree, i, arr[i]);
	}


	display(fwTree);

	int x = 0;
	int control;
	menu();

	cin >> control;

	while (control > 0 && control < 3) {
		switch (control) {
		case(1): {
			int e;
			cout << "Input n: "; cin >> e;
			int sum = sumZeroToN(fwTree, e);
			cout << "Sum(0, " << e << ") = " << sum;
			cout << "\n";
			break;
		}
		case(2): {
			int b, e;
			cout << "Input m: "; cin >> b;
			cout << "Input n: "; cin >> e;
			int sum = sumUp(fwTree, b, e);
			cout << "Sum(" << b << ", " << e << ") = " << sum;
			cout << "\n";
			break;
		}
		default:
			break;
		}
		cout << "Which program you want to execute next?\n";
		cin >> control;
	}

	return 0;
}

//This is the function to assign all elements of fwTree to 0 to make it easier to create and adjust
void deploy(vector<int> fTree) {
	for (int i = 0; i < fTree.size(); i++) {
		fTree[i] = 0;
	}
}

//This is the function to increase elements within the 2's complement method 
void increment(vector<int>& fTree, int i, int val) {
	//We start from 1 instead of 0 so adding 1 to index 
	i++;
	while (i < fTree.size()) {
		fTree[i] += val;
		//This is increasing index by flipping the bits, and it to the original then add it to the index
		i += i & -i;
	}
}

//This is the function to calculate the sum from element 0 to element N in the initial array
int sumZeroToN(vector<int> fTree, int n) {
	int sum = 0;
	while (n >= 1) {
		sum += fTree[n];
		//This is decreasing index by flipping the bits, and it to the original then subtract it from the index
		n -= n & -n;
	}
	return sum;
}

//This is the function to calculate the sum from element b to element e in the initial array by subtracting sumZeroTo_b-1 from sumZeroTo_e
int sumUp(vector<int> fTree, int b, int e) {
	return sumZeroToN(fTree, e) - sumZeroToN(fTree, b - 1);
}

//This is the function to printout all elements in the tree
void display(vector<int> fTree) {
	for (int i = 0; i < fTree.size(); i++) {
		cout << "Index[" << i << "]= " << fTree[i] << "\n";
	}
}

//This is the function to display the menu
void menu() {
	cout << "1: Find the sum of (0, n)\n";
	cout << "2: Find the sum of (m, n)\n";
	cout << "0: Exit program!\n";
	cout << "Please select your program!\n";
}