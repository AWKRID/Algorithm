class Solution {
    fun solution(a: Int, b: Int, n: Int): Int {
        var answer: Int = 0
        var cokeNum = n
        while(cokeNum / a !=0){
            val newCoke = cokeNum / a * b
            answer += cokeNum / a * b
            cokeNum %= a
            cokeNum += newCoke
        }
        return answer
    }
}