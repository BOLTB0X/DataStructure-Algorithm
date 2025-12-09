def solution(number, k):
    answer = ''
    stack = []
    
    for num in number:
        while stack and k > 0 and num > stack[-1]:
            stack.pop()
            k -= 1
        stack.append(num)
    
    if k > 0:
        stack = stack[:len(stack)-k]
    answer = "".join(stack)
    return answer