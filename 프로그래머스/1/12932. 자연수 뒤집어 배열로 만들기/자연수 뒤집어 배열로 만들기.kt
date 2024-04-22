class Solution {
    fun solution(n: Long): IntArray {
        var str : String = n.toString()
        var answer = IntArray(str.length)
        for(i in 0..str.length-1){
            answer[str.length-i-1] = str[i].toString().toInt()
        }
        return answer
    }
}