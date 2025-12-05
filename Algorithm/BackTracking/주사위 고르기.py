from itertools import combinations
import bisect

def solution(dice):
    answer = []
    dice_type = [i for i in range(len(dice))]
    temp_score = []
    max_win = -1
    
    def dfs(dice_idx_list, tot, depth):
        if depth == len(dice_idx_list):
            temp_score.append(tot)
            return
    
        for number in dice[dice_idx_list[depth]]:
            dfs(dice_idx_list, tot + number, depth + 1)
    ## dfs
    
    for my in combinations(dice_type, len(dice) // 2):
        enemy = [i for i in range(len(dice)) if not i in my]
        #print(my, enemy)
        
        temp_score = []
        dfs(my, 0, 0)
        my_score = temp_score[:]
        
        temp_score = []
        dfs(enemy, 0, 0)
        enemy_score = sorted(temp_score[:])
        
        win = 0
        for target in my_score:
            win += bisect.bisect_left(enemy_score, target)
        
        #print(my, win)
        if max_win < win:
            max_win = win
            answer = [m+1 for m in my]
    
    return answer
## solution