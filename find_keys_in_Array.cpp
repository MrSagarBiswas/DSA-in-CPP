#include <iostream>
using namespace std;

int find(int *a, int n, int key)
{
	if (n==0)
		return -1;
	if (a[n-1] == key)
		cout<< n-1 <<" ";

	return find(a, n-1, key);
}

int main()
{
	int a[] = {1, 2, 4, 3, 4, 5};
	find(a, 6, 4);
}