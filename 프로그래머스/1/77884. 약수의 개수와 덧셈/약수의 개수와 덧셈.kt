class Solution {
    fun solution(left: Int, right: Int): Int {
        var answer: Int = 0
        var squaredList = mutableListOf<Int>()
        for(i in 1..31){
            squaredList.add(i*i)
        }
        for(i in left .. right) {
            if(squaredList.contains(i)) answer -= i
            else answer += i
        }
        return answer
    }
}