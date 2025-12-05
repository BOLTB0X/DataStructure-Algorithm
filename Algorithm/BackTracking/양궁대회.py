from itertools import combinations_with_replacement

def solution(n, info):
    answer = []
    candi = {}
    
    for combi in combinations_with_replacement([i for i in range(11)], n):
        lion = [0] * 11
        for c in combi:
            lion[c] += 1
        
        lion_score, apach_score = get_scores(lion, info)
        
        if lion_score <= apach_score:
            continue
        
        if not lion_score - apach_score in candi:
            candi[lion_score - apach_score] = [lion]
        else:
            candi[lion_score - apach_score] += [lion]
            
            
    if not len(candi):
        answer = [-1]
    else:
        max_diff = max(candi.keys())
        answer = candi[max_diff][0]
        
        for arr in candi[max_diff][1:]:
            if better(arr, answer):
                answer = arr[:]
            
    return answer
# solution

def get_scores(lion, apach):
    lion_score, apach_score = 0, 0
    
    for i in range(11):
        if lion[i] == 0 and apach[i] == 0:
            continue
        if lion[i] > apach[i]:
            lion_score += (10 - i)
        else:
            apach_score += (10 - i)
    
    return lion_score, apach_score
# get_scores

def better(a, b):
    for i in range(10, -1, -1):
        if a[i] > b[i]:
            return True
        if a[i] < b[i]:
            return False
    return False
# better