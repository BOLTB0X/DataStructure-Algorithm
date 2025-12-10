def solution(N):
    for i in range(1, N+1):
        M = i
        tot = i

        while M:
            tot += (M % 10)
            M //= 10

        if tot == N:
            return i
    return 0


print(solution(int(input())))