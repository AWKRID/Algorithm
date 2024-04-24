import kotlin.math.pow
class Solution {
    fun solution(n: Int): Int {
        var answer: Int = 0
        val base3 : MutableList<Int> = mutableListOf()
        var k = n
        while(k > 0){
            base3.add(k%3)
            k /=3
        }
        for(i in base3.indices){
            answer += (base3[base3.lastIndex-i] * 3.0.pow(i)).toInt()
        }

        return answer
    }
}