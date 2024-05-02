class Solution {
    fun solution(park: Array<String>, routes: Array<String>): IntArray {
        var cy = 0
        var cx = 0
        for(y in park.indices){
            for(x in park[0].indices){
                if(park[y][x] == 'S') {
                    cy = y
                    cx = x
                    break
                }
            }
        }
        for(route in routes) {
            val routeInfo = route.split(" ")
            var dy = cy
            var dx = cx
            for(i in 1..routeInfo[1].toInt()){
                when(routeInfo[0]){
                    "E" -> dx++
                    "W" -> dx--
                    "S" -> dy++
                    "N" -> dy--
                }
                if(dy < 0 || dy >= park.size || dx < 0 || dx >= park[0].length||park[dy][dx] == 'X') {
                    dy = cy
                    dx = cx
                    break
                }
            }
            cy = dy
            cx = dx
        }
        return intArrayOf(cy, cx)
    }
}