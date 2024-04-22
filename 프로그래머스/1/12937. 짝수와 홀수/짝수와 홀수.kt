class Solution {
    fun solution(num: Int): String {
        var answer = "Odd"
        if(num %2 == 0){
            answer = "Even"
        }
        return answer
    }
}