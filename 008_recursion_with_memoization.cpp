#include <iostream>

// Max number whose fibonacci value can be stored in a 64-bit integer is 103,
// Its fibonacci value, i.e., fibo(103) is approx. 6.3 * 10^18.
const int length = 104;   // 0 to 103
long long g_fiboSeq[length];    // fibo(n) = g_fiboSeq[n], for n >= 0.

void initFibo()
{
    g_fiboSeq[0] = 0;
    g_fiboSeq[1] = 1;
    for (int count = 2; count < length; ++count)
		g_fiboSeq[count] = -1;
}

long long fibo(int n)
{
	if (n <= 0)
		return 0;
    if (n == 1)
        return 1;

	if (g_fiboSeq[n] != -1)
		return g_fiboSeq[n];

	g_fiboSeq[n] = fibo(n - 1) + fibo(n - 2);
	return g_fiboSeq[n];
}

int getN()
{
    std::cout << "Enter a number between 0 and 103 (inclusive): ";
	int n;
	std::cin >> n;

    if (n >= 0 && n <= 103)
    	return n;
    else
        return getN();
}

int main()
{
    initFibo();
    int n = getN();
    std::cout << "Fibonacci number correspoonding to " << n << " is " << fibo(n) << std::endl;
	return 0;
}
