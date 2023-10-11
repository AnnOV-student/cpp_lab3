#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n, i;
	cin >> n;
	int t = 0;
	long * a = new long [n], sum1=0, sum2=0, sum=0;
	for ( i = 0; i < n; i++) {
		cin >> * (a + i);
		sum += *(a + i);
	}
	for (i = n - 1; i >= 0; i--) {
		for (int j = n - 2; j >= 0; j--)
		if ( *(a + j +1) > *(a + j)) {
			long p = *(a + j);
			*(a + j) = *(a + j + 1);
			*(a + j + 1) = p;
		}
	}
	long sumsum = *a;
	for (i = 0; i < n; i++) {
		while (sumsum < sum - sumsum) {
			t++;
			sumsum += *(a + i);
		}
			
	}
	for (i = 0; i <= t; i++)
		sum1 += *(a + i);
	for (i = t + 1; i < n; i++)
		sum2 += *(a + i);
	for (i = 1; i <= t; i++) {
		for (int j = n - 1; j > t; j--) {
			if (2 * abs(i - j) <= abs(sum1 - sum2)) {
				long p = *(a + i);
				*(a + i) = *(a + j);
				*(a + j) = p;
				sum1 = sum1 - *(a + j) + *(a + i);
				sum2 = sum2 - *(a + i) + *(a + j);
			}
		}

	}
	cout << endl << abs(sum1 - sum2);
	return 0;
}