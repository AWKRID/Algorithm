class Solution {
    fun solution(arr: IntArray): IntArray {
        var answer = mutableListOf<Int>()
        if(arr.size <= 1) {
            answer.add(-1)
            return answer.toIntArray()
        }
        for(i in arr.indices) {
            answer.add(arr[i])
        }
        answer.remove(arr.minOrNull())


        return answer.toIntArray()
    }
}