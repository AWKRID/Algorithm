class Solution {
fun solution(seoul: Array<String>): String {
    var x : Int = 0
    for(i in 0..(seoul.size-1)){
        if(seoul[i] =="Kim"){
               x = i
               break;
        }
    }
    var answer = "김서방은 ${x}에 있다"
    return answer
    }
}