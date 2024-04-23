class Solution {
    fun solution(s: String): String {
        var answer = ""
        answer +=  s[s.lastIndex/2]
        if(s.length %2 ==0){
            answer += s[s.lastIndex/2 + 1]
        }
        return answer
    }
}