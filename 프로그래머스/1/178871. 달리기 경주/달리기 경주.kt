class Solution {
    fun solution(players: Array<String>, callings: Array<String>): Array<String> {
        var answer: MutableList<String> = players.toMutableList()
        var answerIndex : MutableMap<String,Int> = mutableMapOf()
        for(i in answer.indices){
            answerIndex[answer[i]] = i
        }

        for(calling in callings){
            val idx = answerIndex[calling]
            swap(answer,idx!!,idx-1)
            answerIndex[calling] = idx-1
            answerIndex[answer[idx]] = idx
        }

        return answer.toTypedArray()
    }

    fun swap(answer : MutableList<String>, index1: Int, index2: Int) {
        val temp = answer[index1]
        answer[index1] = answer[index2]
        answer[index2] = temp
    }
}