import java.util.*
import kotlin.math.max
import kotlin.math.min

class Solution {
    fun solution(arr: IntArray): Int {
        var answer = 0
        val stk = Stack<Int>()
        for ( num in arr){
            if(stk.isEmpty()){
                stk.push(num)
            }
            val lcm = findLcm(stk.peek(), num)
            stk.pop()
            stk.push(lcm)
        }
        return stk.peek()
    }


    fun findLcm(a: Int, b: Int): Int{
        val minVal = min(a,b)
        val maxVal = max(a,b)
        for(i in 1 ..minVal){
            if((maxVal*i) % minVal == 0) return maxVal*i
        }
        return 0
    }
}