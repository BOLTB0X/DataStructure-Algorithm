# Math

> 수학 관련 코드들 정리

## 약수 구하기

1. **기본**

   ```cpp
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
   ```

   ---

2. **Upgrade**

   ```cpp
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
   ```

   ```cpp
   void factor_more_efficient(int n) 
   {
       for (int i = 1; i * i <= n; ++i)
       {
           if (i * i == n) {
			   cout << i << ": " << n << "의 중복되는 제곱수 " << '\n';
		   } else if (n % i == 0) {
			   cout << i << ", "<< n / i << '\n';
		   }
       }
   }
   ```

   ---

## 소수 판별

1. **기본**

   ```cpp
   bool is_Prime_efficient(int n)
   {
	   for (int i = 2; i <= sqrt(n); i++)
       {
		   if (n % i == 0)
			   return false;
	   }
	   return true;
   }
   ```

   ---

2. **에라토스테네스의 체**

   ```cpp
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
   ```

   ---

## 최대공약수 , 최소공배수

1. **최대공약수**

   ```cpp
   int gcd(int a, int b)
   {
	   if (b == 0) return a;
       return gcd(b, a % b);
   }
   ```

   ---

2. **최소공배수**

   ```cpp
   int lcm(int a, int b)
   {
       return (a * b) / gcd(a, b);
   }
   ```

   ---

## 소인수 분해

```cpp
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
```

## 합성수 판별

```cpp
bool is_composite(int n)
{
    vector<int> res;
    
    for (int i = 1; i <= n; ++i)
        if (!(n % i)) res.push_back(i);
    
    return res.size() >= 3;
}
```

## 분수 덧셈

```cpp
vector<int> fraction_addition(int numer1, int denom1, int numer2, int denom2)
{
    int a = numer1 * denom2 + numer2 * denom1;
    int b = denom1 * denom2;
    
    return { a / gcd(a, b), b / gcd(a, b) };
}
```


## 참고

- 프로그래머스 기초, 입문 문제