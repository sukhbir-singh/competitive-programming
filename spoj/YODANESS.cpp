#include <bits/stdc++.h>
#define MAX 30010
#define INF 99999

using namespace std;

int reqArr[MAX];
long long int ans;

void merge(int start, int mid, int end){
	int arr1[mid - start + 2], arr2[end - mid + 1], i, j, count1, count2;
	for(i = start, j = 0; i <= mid; i++, j++){
		arr1[j] = reqArr[i];
	}
	arr1[j] = INF;

	for(i = mid + 1, j = 0; i <= end; i++, j++){
		arr2[j] = reqArr[i];
	}
	arr2[j] = INF;

	count1 = 0, count2 = 0;
	for(i = start; i <= end; i++){
		if(arr1[count1] < arr2[count2]){
			reqArr[i] = arr1[count1];
			++count1;
		}

		else {
			reqArr[i] = arr2[count2];
			++count2;
			ans += (mid - start + 1) - count1;
		}
	}
}

void mergeSort(int p, int q){
	int r;
	if(p < q){
		r = (p + q)/2;
		mergeSort(p, r);
		mergeSort(r + 1, q);
		merge(p, r, q);
	}
}

int main(){
	ios::sync_with_stdio(false);
	int t, p = 0, n, i;
	cin >> t;

	while(p < t){
		map <string, int> m;
		cin >> n;
		string arr[n], temp;

		for(i = 0; i < n; i++){
			cin >> arr[i];
		}

		for(i = 0; i < n; i++){
			cin >> temp;
			m[temp] = i;
		}

		for(i = 0; i < n; i++){
			reqArr[i] = m[arr[i]];
		}

		ans = 0;
		mergeSort(0, n - 1);
		cout << ans << "\n";
		++p;
	}

	return 0;
}