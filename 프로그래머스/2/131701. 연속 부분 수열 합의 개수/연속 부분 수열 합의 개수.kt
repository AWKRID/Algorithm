class Solution {
    fun solution(elements: IntArray): Int {
        val answerList = mutableListOf<Int>()
        for (i in 1..elements.size) {
            for (j in elements.indices) {
                var sum = 0
                for (k in j until j + i) {
                    sum += if (k >= elements.size) elements[k - elements.size]
                    else elements[k]
                }
                answerList.add(sum)
            }
        }

        return answerList.distinct().size
    }
}