class Solution {
    fun solution(food: IntArray): String {
        var answer: String = ""
        for(i in 1..food.lastIndex) {
            for(j in 1..food[i]/2){
                answer += "$i"
            }
        }
        
        val reversedAnswer = answer.reversed()
        answer +="0"
        answer += reversedAnswer
        return answer
    }
}