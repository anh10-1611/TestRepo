#include<iostream>
#include<vector>

using namespace std;


void deploy(vector<int> fTree) {
	for (int i = 0; i < fTree.size(); i++) {
		fTree[i] = 0;
	}
}

void increment(vector<int> &fTree, int i, int val) {
	i++;
	while (i < fTree.size()) {
		fTree[i] += val;
		i += i & -i;
	}

}

int sumZerotoN(vector<int> fTree, int n) {
	int sum = 0;
	while (n >= 1) {
		sum += fTree[n];
		n -= n & -n;
	}
	return sum;
}


void display(vector<int> fTree) {
	for (int i = 1; i < fTree.size(); i++) {
		cout << "Index[" << i << "]= " << fTree[i] << "\n";
	}
}


int sumUp(vector<int> fTree, int b, int e) {
	return sumZerotoN(fTree, e) - sumZerotoN(fTree, b - 1);
}

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

	for (int i = 0; i < arr.size(); i++) {
		increment(fwTree, i, arr[i]);
	}
	display(fwTree);

	int sum = sumZerotoN(fwTree, n);
	cout << "sum from 0 to " << n << " is " << sum;

	int sum2 = sumUp(fwTree, 3, 8);
	cout << "\nsum from 3 to 8 is " << sum2;

	return 0;
}