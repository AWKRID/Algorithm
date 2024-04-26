class Solution {
    fun solution(k: Int, score: IntArray): IntArray {
        var answer: MutableList<Int> = mutableListOf()
        var honerList: IntArray = IntArray(k) {9999}
        for (i in score.indices) {
            if(i < k){
                honerList[i] = score[i]
                honerList.sort()
            }else{
                if(score[i] > honerList.minOrNull()!!){
                    honerList[0] = score[i]
                    honerList.sort()
                }
            }
            answer.add(honerList[0])
        }
        return answer.toIntArray()
    }
}