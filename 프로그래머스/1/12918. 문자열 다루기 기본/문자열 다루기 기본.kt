class Solution {
    fun solution(s: String): Boolean {
        var answer = true
        if(s.length ==4 || s.length == 6){
            for(c in s){
                if(c.code < '0'.code || c.code > '9'.code){
                    answer = false
                    break
                }
            }
        }else{
            answer = false
        }
        return answer
    }
}