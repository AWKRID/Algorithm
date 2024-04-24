class Solution {
    fun solution(t: String, p: String): Int {
        var answer: Int = 0
        val numP = p.toLong()
        for(i in 0..t.length - p.length) {
            val substr = t.substring(i, i + p.length).toLong()
            if (substr <= numP) answer++

        }
        return answer
    }
}