import java.util.*

class Solution {
    val dx = arrayOf(0,1,0,-1)
    val dy = arrayOf(1,0,-1,0)

    val answer = ArrayList<Int>()
    var visited = Array(104) { BooleanArray(104){false} }
    var map = Array(104) { CharArray(104) }
    var numRows = 0
    var numColumns = 0

    fun solution(maps: Array<String>): IntArray {
        numRows = maps.size
        numColumns = maps[0].length
        for(j in 0 until numRows){
            for(i in 0 until numColumns ){
                map[j][i] = maps[j][i]
            }

        }
        for(y in 0 until numRows){
            for(x in 0 until numColumns){
                if(map[y][x] != 'X' && !visited[y][x]) bfs(y,x)
            }
        }
        if(answer.isEmpty()) return intArrayOf(-1)
        return answer.sorted().toIntArray()
    }

    fun bfs(y:Int, x: Int){
        val q: Queue<Pair<Int,Int>> = LinkedList()
        q.add(Pair(y, x))
        visited[y][x] = true
        var count = map[y][x].toString().toInt()
        while(q.isNotEmpty()){
            val cur = q.poll()
            for(i in 0 .. 3){
                val ny = cur.first + dy[i]
                val nx = cur.second + dx[i]
                if(nx<0 || nx >= numColumns || ny <0 || ny >= numRows) continue
                if(visited[ny][nx]) continue
                if(map[ny][nx] == 'X') continue
                visited[ny][nx] = true
                q.add(Pair(ny,nx))
                count += map[ny][nx].toString().toInt()

            }
        }
        answer.add(count)
    }


}