class Solution {
    fun solution(numbers: IntArray): IntArray {
        var answer: MutableList<Int> = mutableListOf()
        for(i in numbers.indices) {
            for(j in i + 1 until numbers.size) {
                answer += numbers[i] + numbers[j]
            }
        }
        answer = answer.distinct().sorted().toMutableList()
        return answer.toIntArray()
    }
}