class Solution {
    fun solution(n: Int, m: Int): IntArray {
        var answer = intArrayOf(1, n * m)
        var minValue = if (n > m) m else n
        for (i in 1..n) {
            if (n % i == 0 && m % i == 0) {
                answer[0] = i
            }
        }
        if (answer[0] != 1) {
            answer[1] = n * m / answer[0]
        }
        return answer
    }
}