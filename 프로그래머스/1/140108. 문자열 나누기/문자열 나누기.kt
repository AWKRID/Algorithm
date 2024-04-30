class Solution {
    fun solution(s: String): Int {
        var answer: Int = 0
        var firstCount = 0
        var secondCount = 0
        var x = ""
        
        for(i in s.indices){
            if(x == "") x = s[i].toString()
            
            if(s[i].toString() == x) firstCount ++
            else secondCount ++
            if(firstCount == secondCount){
                answer++
                firstCount = 0
                secondCount = 0
                x = ""
            }
        }
        if(x != "") answer++

        return answer
    }
}