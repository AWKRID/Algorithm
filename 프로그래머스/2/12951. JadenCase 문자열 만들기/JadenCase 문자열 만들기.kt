class Solution {
    fun solution(s: String): String {
        var answer = ""
        var flag = 1
        for(i in s.indices){
            if(s[i] == ' ') {
                flag = 1
                answer += " "
                continue
            }
            if(flag == 1){
                flag = 0
                answer += s[i].uppercase()
            }
            else answer += s[i].lowercase()


        }
        return answer

    }
}