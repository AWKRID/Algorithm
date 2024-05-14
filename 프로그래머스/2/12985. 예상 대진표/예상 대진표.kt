import kotlin.math.max
import kotlin.math.min


class Solution {
    fun solution(n: Int, a: Int, b: Int): Int {
        var aNum = min(a,b)
        var bNum = max(a,b)
        var count = 1
        while(true){
            if(aNum + 1 == bNum && bNum % 2 ==0) break
            count++
            aNum = (aNum+1) / 2
            bNum = (bNum+1) /2
        }

        return count
    }
}