class Solution {
    fun solution(num1: Int, num2: Int): Int {
        var answer: Int = 0
        var divide: Double = 0.0
        divide = num1.toDouble() / num2.toDouble() 
        answer = (divide * 1000).toInt()
        return answer
    }
}