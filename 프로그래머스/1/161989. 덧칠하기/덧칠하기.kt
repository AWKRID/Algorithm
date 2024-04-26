class Solution {
    fun solution(n: Int, m: Int, section: IntArray): Int {
        var answer: Int = 0
        val sectionList = section.toMutableList()
        var startIndex = 0
        while(sectionList.isNotEmpty()) {
            startIndex = sectionList[0]
            for(i in startIndex until startIndex+m){
                sectionList.remove(i)
            }
            answer++
        }
        return answer
    }
}