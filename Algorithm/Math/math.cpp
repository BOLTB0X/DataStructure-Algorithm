#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

void factor_basic(int n)
{
    if (n <= 0) return;
    
    for (int i = 1; i <= n; ++i)
    {
        if (n % i == 0)
            cout << i << ' ';
    }

    cout << '\n';
}

void factor_efficient(int n)
{
    for (int i = 1; i <= n/2; ++i)
    {
        if (n % i == 0)
            cout << i << ' ';
    }
    cout << n;
    cout << '\n';
}

void factor_more_efficient(int n) 
{
    for (int i = 1; i * i <= n; ++i)
    {
        if (i * i == n) {
			cout << i << ": " << n << "의 중복되는 제곱수 " << '\n';
		}else if (n % i == 0) {
			cout << i << ", "<< n / i << '\n';
		}
    }
}

bool is_Prime_baic(int n)
{
	for (int i = 2; i < n; i++)
    {
		if (n % i == 0)
			return false;
		
	}

	return true;
}

bool is_Prime_efficient(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
    {
		if (n % i == 0)
			return false;
		
	}
	return true;
}

// 여러 개의 숫자가 소수인지 반복해서 판단할 경우 유용
vector<bool> sieve_of_Eratosthenes(int n)
{
    vector<bool> isPrime(n + 1, true);

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    return isPrime;
}

int gcd(int a, int b)
{
	if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a * b) / lcm(a, b);
}

// 소인수 분해
vector<int> prime_factorization(int n)
{
    vector<int> answer;
    set<int> primes;
    int number = 2;
    
    while (number <= n)
    {
        if (!(n % number))
        {
            primes.insert(number);
            n /= number;
        }
        else number++;
    }
    
    answer.assign(primes.begin(), primes.end());
    return answer;
}

// 합성수 판별
bool is_composite(int n)
{
    vector<int> res;
    
    for (int i = 1; i <= n; ++i)
        if (!(n % i)) res.push_back(i);
    
    return res.size() >= 3;
}

// 분수 덧셈
vector<int> fraction_addition(int numer1, int denom1, int numer2, int denom2)
{
    int a = numer1 * denom2 + numer2 * denom1;
    int b = denom1 * denom2;
    
    return { a / gcd(a, b), b / gcd(a, b) };
}

int main(void) {
    factor_more_efficient(20);

    vector<bool> isPrime = sieve_of_Eratosthenes(20);

    for (int i = 1; i <= 20; ++i)
    {
        if (isPrime[i])
            cout << i << " 소수\n";
    }
    return 0;
}