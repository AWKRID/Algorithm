import kotlin.math.max
import kotlin.math.min

class Solution {
    fun solution(wallpaper: Array<String>): IntArray {
        var answer = mutableListOf<Int>()

        var left = 9999
        var top = 9999
        var right = 0
        var bottom = 0

        for (y in wallpaper.indices) {
            for(x in wallpaper[0].indices){
                if(wallpaper[y][x] == '#') {
                    left = min(left, x)
                    right = max(right, x+1)
                    top = min(top, y)
                    bottom = max(bottom, y+1)
                }
            }
        }
        answer.add(top)
        answer.add(left)
        answer.add(bottom)
        answer.add(right)
        return answer.toIntArray()

    }

}
