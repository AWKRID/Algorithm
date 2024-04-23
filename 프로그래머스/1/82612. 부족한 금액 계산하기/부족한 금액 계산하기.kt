class Solution {
    fun solution(price: Int, money: Int, count: Int): Long {
        var answer: Long = 0
        var totalPrice : Long = (price * (count * (count +1)).toLong()/2)
        if(totalPrice > money){
            answer = totalPrice - money
        }

        return answer
    }
}