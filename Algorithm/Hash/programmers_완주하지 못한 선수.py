from collections import Counter

def solution(participant, completion):
    answer = ''
    players = Counter(participant)
    
    for comp in completion:
        players[comp] -= 1
    
    for (k,v) in players.items():
        if v > 0:
            answer = k
            break
    
    return answer