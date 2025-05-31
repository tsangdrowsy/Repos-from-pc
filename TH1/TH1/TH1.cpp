#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

long long x(int n)
{
	if (n == 1)
		return 1;
	long long tong = 0;
	for (int i = 1; i < n; i++)
	{
		tong +=x(i);
	}
	return n*tong;

}
int main()
{
	int n; cin >> n;
	cout << x(n);
	return 0;
}

