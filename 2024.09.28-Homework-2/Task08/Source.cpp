#include <cstdio>

int main()

{
	
    int n = 0;
	int m = 0;

	scanf("%d", &n);
	scanf("%d", &m);

	if (n < m)
	{
	int x = m;
	m = n;
	n = x;
	}

	if (n == 1 || m == 1)
	{
	printf("%d\n", n * m * 4);
	}
	else
	{
	int r = (m + 2) * n + m * (n + 2);
	
    if (n % 2 == 1 && m % 2 == 1)
	{
	r -= 2;
	}
	printf("%d\n", r);
	}

	return EXIT_SUCCESS;
    
}
