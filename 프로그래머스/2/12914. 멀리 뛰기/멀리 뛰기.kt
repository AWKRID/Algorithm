class Solution {
    fun solution(n: Int): Long {
        var answer: Long = 0
        val fibonacci = LongArray(2004){-1}
        fibonacci[1] = 1
        fibonacci[2] = 2
        for(i in 3 ..n){
            fibonacci[i] = (fibonacci[i - 1] + fibonacci[i - 2]) % 1234567
        }

        return fibonacci[n]
    }
}