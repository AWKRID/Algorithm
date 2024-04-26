class Solution {
    fun solution(s: String): IntArray {
        var answer: MutableList<Int> = MutableList<Int>(s.length) {-1}
        for(i in s.indices) {
            for(j in 0 until i){
                if (s[i] == s[j]){
                    answer[i] = i-j
                }
            }
        }
        return answer.toIntArray()
    }
}
