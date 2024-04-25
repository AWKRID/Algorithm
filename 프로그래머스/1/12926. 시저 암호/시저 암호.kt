
class Solution {
    fun solution(s: String, n: Int): String {
        var answer = ""
        for (char in s) {
            if (char == ' ') {
                answer += char
                continue
            }
            
            else if (char in 'a'..'z') {
                var temp = char + n
                if (temp > 'z') temp -= 26
                answer += temp.toChar()
            } else { 
                var temp = char + n
                if (temp > 'Z') temp -= 26
                answer += temp.toChar()
                
            }
            
    
        }
        return answer
    }
}