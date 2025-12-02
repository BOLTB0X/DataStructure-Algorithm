from itertools import permutations
import math

def solution(numbers):
    answer = 0
    candidate_prime = []
    for cnt in range(1, len(numbers)+1):
        for per in permutations(numbers, cnt):
            candidate_prime.append(int(''.join(per)))
    
    for num in set(candidate_prime):
        if is_prime(num):
            answer += 1
    return answer

def is_prime(n):
    if n <= 1:
        return False
    
    for i in range(2, int(math.sqrt(n))+1):
        if not n % i:
            return False
    return True