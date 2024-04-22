class Solution {
    fun solution(n: Long): Long {
        var answer: String = ""
        var list : MutableList<Int> = mutableListOf()
        var str : String = n.toString()
        for( c in str.toCharArray()){
            list.add(c.toString().toInt())
        }
        list.sortDescending()
        for(i in list){
            answer += i.toString()
        }
        return answer.toLong()
    }
}