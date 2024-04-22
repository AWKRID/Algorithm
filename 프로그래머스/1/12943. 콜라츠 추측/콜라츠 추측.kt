class Solution {
    fun solution(num: Int): Int {
        var answer = 0
        var num1 :Long = num.toLong()
        if(num == 1){
            return 0
        }
        while(num1 != 1.toLong()){
            if(num1 % 2==0.toLong()) {
                num1 /=2
            }
            else{
                num1 *=3
                num1 ++
            }
            answer++
            if(answer >= 500){
                return -1
            }
        }
        return answer    
    }
    
    
}