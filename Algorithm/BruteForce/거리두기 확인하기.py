flag = True
dir = [[1,0], [-1,0], [0,1], [0,-1]]

def solution(places):
    answer = []
    
    for place in places:
        answer.append(checkProtect(place))
    return answer

def checkProtect(place):
    global flag
    flag = True
    visited = [[False]*5 for _ in range(5)]
    
    for i in range(len(place)):
        for j in range(len(place[0])):
            if place[i][j] == "P":
                visited[i][j] = True
                DFS(place, visited, i, j, 0)
                
                if not flag:
                    return 0
    
    return 1

def DFS(place, visited, x, y, depth):
    global flag
    
    if not flag:
        return
    
    if flag and depth == 2:
        return
    
    for d in dir:
        nx = x + d[0]
        ny = y + d[1]
        
        if nx < 0 or ny < 0 or nx >= 5 or ny >= 5:
            continue
            
        if visited[nx][ny] or place[nx][ny] == "X":
            continue
            
        if place[nx][ny] == "P":
            flag = False
            return
        
        visited[nx][ny] = True
        DFS(place, visited, nx, ny, depth+1)
    return