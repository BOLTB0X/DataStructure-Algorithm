import Foundation

let N = Int(readLine()!)!

print(solution(N))

func solution(_ N: Int) -> Int {
  var answer: Int = 0
  var isPrime = [Bool](repeating: true, count: N + 1)
  var primes: [Int] = []

  if N < 2 { return 0 }
  
  isPrime[0] = false
  isPrime[1] = false
  
  for i in 2...N {
    if isPrime[i] {
      for j in stride(from: i * i, through: N, by: i) {
        isPrime[j] = false
      }
    }
  }

  primes = isPrime.enumerated().filter { $0.1 }.map { $0.0 }
  var start: Int = 0, end: Int = 0, sum: Int = primes[0]

  while start <= end && end < primes.count {
    if sum == N {
      answer += 1
    }

    if sum < N {
      end += 1
      sum = sum + (end == primes.count ? 0 : primes[end])
    } else {
      sum -= primes[start]
      start += 1
    }
  }
  
  return answer
} // solution
