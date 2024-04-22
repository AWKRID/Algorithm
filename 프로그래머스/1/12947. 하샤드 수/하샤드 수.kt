class Solution {
    fun solution(x: Int): Boolean {
        var answer = true
        var denom : Int = 0
        x.toString().forEach { denom +=it.toString().toInt() }
        if(x % denom !=0) {
            answer = false
        }
        return answer
    }
}