#include <iostream>
using namespace std;
//2 * n타일링(2)

int main(void)
{
	int n;
	cin >> n;

	int ary[1001];
	ary[1] = 1;
	ary[2] = 3;

	for (int i = 3; i <= n; i++)
	{
		ary[i] = (ary[i - 1] + 2 * ary[i - 2]) % 10007;
	}

	cout << ary[n];

	return 0;
}