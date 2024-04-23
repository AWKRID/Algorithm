class Solution {
    fun solution(numbers: IntArray): Int {
        var numList : MutableList<Int> = mutableListOf<Int>(1,2,3,4,5,6,7,8,9)
        var answer: Int = 0
        for(number in numbers){
            numList.remove(number)
        }
        for(number in numList){
            answer += number
        }
        return answer
    }
}