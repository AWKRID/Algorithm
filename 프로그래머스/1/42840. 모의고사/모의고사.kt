import kotlin.math.max

class Solution {
    fun solution(answers: IntArray): IntArray {
        val answer = mutableListOf<Int>()
        val answer1 = listOf(1,2,3,4,5)
        val answer2 = listOf(2,1,2,3,2,4,2,5)
        val answer3 = listOf(3,3,1,1,2,2,4,4,5,5)

        var grade1 = 0
        var grade2 = 0
        var grade3 = 0

        for(i in answers.indices){
            if(answers[i] == answer1[i%answer1.size]) grade1 += 1
            if(answers[i] == answer2[i%answer2.size]) grade2 += 1
            if(answers[i] == answer3[i%answer3.size]) grade3 += 1
        }
        val maxScore = max(grade1, max(grade2, grade3))
        if(maxScore == grade1) answer.add(1)
        if (maxScore == grade2) answer.add(2)
        if (maxScore == grade3) answer.add(3)
        return answer.toIntArray()
    }
}