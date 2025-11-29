from collections import deque

def solution(n, wires):
    answer = n
    adj = [[0] * (n+1) for i in range(n+1)]
    
    def BFS(start):
        ret = 1
        visited = [False] * (n+1)
        visited[start] = True
        
        que = deque([start])
        
        while que:
            cur = que.popleft()
            
            for i in range(1,n+1):
                if not visited[i] and adj[cur][i] == 1:
                    ret += 1
                    visited[i] = True
                    que.append(i)
        return ret
    
    for wire in wires:
        adj[wire[0]][wire[1]] = 1
        adj[wire[1]][wire[0]] = 1
    
    
    for wire in wires:
        adj[wire[0]][wire[1]] = 0
        adj[wire[1]][wire[0]] = 0
        
        cnt1 = BFS(wire[0])
        cnt2 = BFS(wire[1])
        
        answer = min(answer, abs(cnt1-cnt2))
        
        adj[wire[0]][wire[1]] = 1
        adj[wire[1]][wire[0]] = 1
    
    return answer