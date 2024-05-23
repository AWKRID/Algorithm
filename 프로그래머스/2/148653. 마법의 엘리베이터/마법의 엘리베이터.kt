class Solution {

    fun solution(storey: Int): Int {
        var answer: Int = 0
        var num = storey
        
        while(num != 0){
            val tmp = num % 10
            if(tmp >= 6) {
                num += 10-tmp
                answer += 10-tmp
            }
            else if(tmp == 5 && (num /10) % 10 >=5){
                num += 10-tmp
                answer += 10-tmp
            }
            else answer += tmp
            num /= 10
        }

        return answer
    }

}