#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

std::vector<int> generatePrimesInRange(int min, int max) {
    std::vector<bool> isPrime(max + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= max; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= max; j += i)
                isPrime[j] = false;
        }
    }

    std::vector<int> primes;
    for (int i = std::max(2, min); i <= max; i++) {
        if (isPrime[i])
            primes.push_back(i);
    }
    return primes;
}

std::vector<int> randomPrimes(int min, int max, int count) {
    auto primes = generatePrimesInRange(min, max);
    std::vector<int> result;
    std::mt19937 gen(0); // фиксируем seed
    std::uniform_int_distribution<int> dist(0, primes.size() - 1);

    for (int i = 0; i < count; i++) {
        result.push_back(primes[dist(gen)]);
    }
    return result;
}

int main() {
    auto start = clock();
    auto primes = randomPrimes(8000000, 9000000, 10000);
    auto duration = clock() - start;

    std::cout << "Primes count: " << primes.size()
        << " duration: " << duration << " ticks\n";
}
