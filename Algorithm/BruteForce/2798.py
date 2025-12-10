def solution(N, M, Cards):
    ret = 0

    for i in range(N-2):
        for j in range(i+1, N-1):
            for k in range(j+1, N):
                if M >= Cards[i]+Cards[j]+Cards[k]:
                    ret = max(ret, Cards[i]+Cards[j]+Cards[k])

    return ret


N, M = map(int, input().split())
Cards = list(map(int, input().split()))

print(solution(N, M, Cards))