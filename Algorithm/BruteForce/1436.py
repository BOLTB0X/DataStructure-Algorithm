def solution(n):
    ret = 666
    loopCount = 0

    while 1:
        if '666' in str(ret):
            loopCount += 1

        if loopCount == n:
            break
        ret += 1

    return ret


n = int(input())
print(solution(n))