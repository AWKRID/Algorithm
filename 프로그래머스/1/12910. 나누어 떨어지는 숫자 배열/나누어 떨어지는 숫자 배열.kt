class Solution {
    fun solution(arr: IntArray, divisor: Int): IntArray {
        var answer = mutableListOf<Int>()
        for (ele in arr){
            if(ele % divisor == 0){
                answer.add(ele)
            }
        }
        answer.sort()
        if(answer.isEmpty()){
            answer.add(-1)
        }
        return answer.toIntArray()
    }
}