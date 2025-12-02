from itertools import combinations

def solution(orders, course):
    answer = []
    menu_type = sorted(set("".join(orders)))
    
    for cnt in course:
        candi = {}
        for order in orders:
            if cnt > len(order):
                continue
            for combi in combinations(order, cnt):
                temp_course = ''.join(sorted(combi))
                if not temp_course in candi:
                    candi[temp_course] = 1
                else:
                    candi[temp_course] += 1
        #print(candi)
        answer += [k for k,v in candi.items() if max(candi.values()) == v and v >= 2]
        
    return sorted(answer)