import kotlin.math.max
import kotlin.math.min


class Solution {
    fun solution(s: String): String {
        val numList = s.split(" ").toList()
        var min = Int.MAX_VALUE
        var max = Int.MIN_VALUE
        for(num in numList){
            val intNum = num.toInt()
            max = max(max, intNum)
            min = min(min, intNum)

        }
        return "$min $max"
    }
}