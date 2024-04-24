class Solution {
    fun solution(s: String): String {
        var answer = ""
        val words = s.split(" ")
        for(word in words){
            for(i in word.indices) {
                answer += if(i%2==0) word[i].uppercase()
                else word[i].lowercase()
            }
            answer += " "
        }
        answer = answer.substring(0, answer.length - 1)
        return answer
    }
}