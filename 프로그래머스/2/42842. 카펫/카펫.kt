class Solution {
    fun solution(brown: Int, yellow: Int): IntArray {
        val sum = brown + yellow
        for (i in 1..sum / 2) {
            if (sum % i != 0)
                continue
            val width = sum / i
            val height = i
            var brownCount = brown
            var j = 0
            while (true) {
                brownCount -= 2 * (width + height - (4 * j) - 2)
                if (brownCount <= 0) break
                j++
            }
            if (brownCount == 0) return intArrayOf(width, height)
            else continue
        }
        return intArrayOf(sum / 2, sum / 2)
    }
}