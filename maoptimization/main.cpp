#include <iostream>
#include <vector>
#include <time.h>
using namespace std;


bool isPrimeBase(int n)
{
    if (n < 2) return false;
    if (n == 2) return true;
        if (n % 2 == 0) return false;
            int p = sqrt(n);
            for (int i = 3; i <= p; i += 2)
            {
                if (n % 2 == 0) return false;
            }
    return true;
}

std::vector<int> primesArray(int min, int max, int count)
{
    std::vector<int> primes;
    srand(0);
    for (int i = 0; i < count; i++)
    {
        int value = (rand() / 32767.0 * (max - min) + min);
        if (isPrimeBase(value))
            primes.push_back(value);
    }
    return primes;
}

int main()
{
    auto start = clock();
    auto result = primesArray(8000000, 9000000, 10000);
    auto duration = clock() - start;
    std::cout << "Primes count: " << result.size() << " duration: " << duration << " msec.\n";
}
