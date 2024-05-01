import java.util.*

class Solution {
    fun solution(ingredient: IntArray): Int {
        var answer: Int = 0
        val stk = Stack<Int>()

        for(i in ingredient) {
            if (stk.size >= 3 && i == 1) {
                if (stk[stk.size - 3] == 1 && stk[stk.size - 2] == 2 && stk.peek() == 3) {
                    repeat(3) { stk.pop() }
                    answer++
                    continue
                }
            }
            stk.push(i)
        }
        return answer
    }
}