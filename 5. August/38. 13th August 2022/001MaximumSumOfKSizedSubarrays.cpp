#include<iostream>

using namespace std;

int main(){

	int arr[] = {1,4,2,7,6,3,5};
	int n = sizeof(arr) / sizeof(int);
	int k = 3;

	int i = 0; //to denote start of window
	int j = 0; //to denote end of window

	int w_sum = 0; //to store the window sum
	int max_sum; //to track the maximum window sum

	//compute sum of first window
	while(j < k){
		w_sum += arr[j];
		j++;
	}

	//at this point, j is at next element after window

	max_sum = w_sum;

	//compute the sum for the remaining windows
	while(j < n){

		//slide the window

		w_sum -= arr[i];
		i++;
		w_sum += arr[j];
		
		max_sum = max(max_sum, w_sum);

		j++;

	}

	cout << max_sum << endl;

	return 0;
}