# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

int partition(vector <int> & vec1, int s, int e){
	int pivot = vec1[s];

	// check how many number are small than pivot so we can place pivot after them
	int count = 0;
	for (int i = s + 1; i <= e; ++i){
		if (vec1[i] <= pivot){
			count++;
		}
	}
	
	// place pivot at right position
	int pivotIndex = s + count;
	// now swap the start which is pivot with count + s, this way the pivot is places
	// right in the middle where right ones are greater and left ones are smaller
	// eg [3, 5, 1, 6] where pivot = 3 get swap with the count + s index which changes [5, 3, 1, 6]
	
	swap(vec1[pivotIndex], vec1[s]);

	int i = s; int j = e;
	while(i < pivotIndex && j > pivotIndex){
		while(vec1[i] <= pivot){
			i++;
		}
		while(vec1[j] > pivot){
			j--;
		}
		if (i < pivotIndex && j > pivotIndex){
			swap(vec1[i++], vec1[j--]);
		}
	}
	return pivotIndex;
	
}

void quickSort(vector <int> & vec1, int s, int e){
	// base condt
	if (s >= e){
		return;
	}

	int p = partition(vec1, s, e);

	// left sort
	quickSort(vec1, s, p - 1);

	// right sort
	quickSort(vec1, p + 1, e);
}

int main()
{
	int n ;
	cin >> n;
	vector<int> vec1;

	// take input into vect1
	for (int i = 0; i < n; ++i){
		int input;
		cin >> input;
		vec1.push_back(input);
	}

	int s = 0;
	int e = n - 1;
	quickSort(vec1, s, e);

	// print vec1
	for (auto e: vec1){
		cout << e << ' ';
	}
	return 0;
}
