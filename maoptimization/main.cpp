#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}

vector<int> primesArray(int min, int max, int count) {
    vector<int> primes;
    srand((unsigned)time(0));
    while (primes.size() < count) {
        int value = min + rand() % (max - min + 1);
        if (isPrime(value))
            primes.push_back(value);
    }
    return primes;
}

int main() {
    clock_t start = clock();
    auto primes = primesArray(8000000, 9000000, 1000); 
    clock_t duration = clock() - start;
    cout << "Primes count: " << primes.size()
        << " duration: " << duration << " ticks\n";
}