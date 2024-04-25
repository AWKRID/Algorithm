
class Solution {
    fun solution(array: IntArray, commands: Array<IntArray>): IntArray {
        var answer = mutableListOf<Int>()
        var list = array.toMutableList()
        for (i in 0 until commands.size) {
            var subList = list.subList(commands[i][0]-1, commands[i][1])
            var subListCopy = subList.toMutableList()
            subListCopy.sort()
            answer.add(subListCopy[commands[i][2]-1])

        }
        return answer.toIntArray()
    }
}