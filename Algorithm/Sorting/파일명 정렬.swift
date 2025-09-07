func solution(_ files:[String]) -> [String] {
    var answer:[String] = []
    var splitedFiles: [[String]] = []
    
    for file in files {
        splitedFiles.append(splitFileName(file))
    }
    
    answer = splitedFiles.sorted {
        if $0[0].lowercased() == $1[0].lowercased() {
            return Int($0[1])! < Int($1[1])!
        }
        
        return $0[0].lowercased() < $1[0].lowercased()
    }.map{$0.joined()}
        
    return answer
}

func splitFileName(_ file: String) -> [String] {
    var res: [String] = ["", "", ""]
    var flag: Bool = false
    let file = file.map{String($0)}
    
    for i in file.indices {
        if flag {
            if let _ = Int(file[i]) {
                res[1].append(file[i])
            } else {
                res[2] = Array(file[i...]).joined()
                break
            }
        } else {
            if let _ = Int(file[i]) {
                flag = true
                res[1].append(file[i])
            } else {
                res[0].append(file[i])
            }
        }
    } // for
    
    return res
}