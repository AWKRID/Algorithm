class Solution {
    fun solution(arr: IntArray): Double {
        var answer : Double = 0.0
        var sum : Double = arr.sum().toDouble()
        answer = sum / arr.size.toDouble()
        return answer
    }
}