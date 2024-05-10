class Solution {
    val fiboArr = IntArray(100004){-1}

    fun solution(n: Int): Int {
        var answer = fibonacci(n)
        return answer
    }


    fun fibonacci(n: Int) : Int{
        if(fiboArr[n] != -1) return fiboArr[n]
        if(n == 0) {
            fiboArr[n] = 0
            return 0
        }
        if(n == 1) {
            fiboArr[n] = 1
            return 1
        }
        fiboArr[n] = (fibonacci(n - 1) + fibonacci(n - 2)) % 1234567
        return fiboArr[n]
    }
}