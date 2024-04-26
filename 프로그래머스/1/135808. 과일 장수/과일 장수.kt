
class Solution {
    fun solution(k: Int, m: Int, score: IntArray): Int {
        var answer: Int = 0
        val scoreList : MutableList<Int> = score.toMutableList()
        scoreList.sort()
        var i = scoreList.lastIndex + 1 -m
        while(i>=0){
            answer += scoreList[i] * m
            i -= m
        }
        return answer
    }
}