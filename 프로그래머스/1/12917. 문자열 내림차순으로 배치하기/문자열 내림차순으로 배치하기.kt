class Solution {
    fun solution(s: String): String {
        var answer = s.toMutableList()
        answer.sortDescending()
        var ret = ""
        for (ele in answer){
            ret += ele.toString()
        }
        return ret
    }
}