class Solution {
    fun solution(nums: IntArray): Int {
        var primeNumbers = MutableList(3001) { true }
        var answer = 0
        var i = 2
        while (i <= 54) {
            if (primeNumbers[i]) {
                var j = 2
                while (i * j <= 3000) {
                    primeNumbers[i * j] = false
                    j++
                }
            }
            i++
        }
        for (idx in nums.indices) {
            for (j in idx + 1 until nums.size) {
                for (k in j + 1 until nums.size) {
                    if (primeNumbers[nums[idx] + nums[j] + nums[k]]) {
                        answer++
                    }
                }
            }
        }
        return answer
    }
}