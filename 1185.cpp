#include <iostream>
#include <cmath>

using namespace std;

bool is_fenge(int x, int n)
{
	int base = pow(10.0, n/2);
	return (x/base + x%base)*(x/base + x%base) == x;
}

int main()
{
	int n;
	bool found = false;
	cin >> n;
	for (int i = sqrt(pow(10.0,(n-1))); i < sqrt(pow(10.0,n)); ++i)
	{
		if (is_fenge(i*i, n))
		{
			cout << i*i << endl;
			found = true;
		}
	}
	if (!found)
	{
		cout << "NO FOUND" << endl;
	}
	//system("pause");
	return 0;
}
