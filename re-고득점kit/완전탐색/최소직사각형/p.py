def solution(sizes):
    maxSize = -1
    minSize = -1
    
    for w, h in sizes:
        maxSize = max(max(w, h), maxSize)
        minSize = max(min(w, h), minSize)
        
    return maxSize * minSize