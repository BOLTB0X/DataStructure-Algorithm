from collections import deque

def solution(progresses, speeds):
    answer = []
    cnt = 0
    
    pQue = deque([])
    sQue = deque([])
    
    for i in range(len(speeds)):
        pQue.append(progresses[i])
        sQue.append(speeds[i])
    
    while pQue:
        while len(pQue) > 0 and pQue[0] >= 100:
            pQue.popleft()
            sQue.popleft()
            cnt += 1
        
        if cnt > 0:
            answer.append(cnt)
            cnt = 0
        
        for i in range(len(sQue)):
            pQue[i] += sQue[i]
            
    return answer