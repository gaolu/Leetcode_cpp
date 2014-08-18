// find the kth element in two array
int findKth(int A[], int m, int B[], int n, int k) {
	// always make sure B is longer than A
	if (m > n)
		return findKth(B, n, A, m, k);
	if (m == 0)
		return B[k - 1];
	if (k == 1)
		return min(A[0], B[0]);
	// divice k into ka and kb
	int ka = min(k / 2, m), kb = k - ka;
	if (A[ka - 1] < B[kb - 1])
		return findKth(A + ka, m - ka, B, n, k - ka);
	else if (B[kb - 1] < A[ka - 1])
		return findKth(A, m, B + kb, n - kb, k - kb);
	else
		return A[ka - 1];
}

double findMedianSortedArrays(int A[], int m, int B[], int n) {
	int total = m + n;
	// odd total
	if (total & 0x1) {
		return findKth(A, m, B, n, total / 2 + 1);
	}
	else {
		return (findKth(A, m, B, n, total / 2) + findKth(A, m, B, n, total / 2 + 1)) / 2.0;
	}
}