class Solution {
    fun solution(n: Int): Int {
        var answer = 0
        var chars : String = n.toString()
        for(c in chars){
            answer += c.toString().toInt()
        }

        return answer
    }
}