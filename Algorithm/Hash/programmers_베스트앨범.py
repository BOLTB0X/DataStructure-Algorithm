def solution(genres, plays):
    answer = []
    
    genre_index = {}
    total_dict = {}
    
    for i in range(len(genres)):
        genre_index[genres[i]] = genre_index.get(genres[i], []) + [i] 
        total_dict[genres[i]] = total_dict.get(genres[i], 0) + plays[i]
    
    
    for (k,_) in sorted(total_dict.items(), key=lambda x: x[1], reverse=True):
        answer += sorted(genre_index[k], key=lambda x: plays[x], reverse=True)[:2]
        
    return answer