class Solution {
    fun solution(k: Int, tangerine: IntArray): Int {
        var answer: Int = 0
        val countArr = IntArray(10000004)
        
        tangerine.forEach{
            countArr[it]++
        }
        
        countArr.sortDescending()
        var total = k
        for(i in countArr.indices){
            if(total <= 0) break
            total -= countArr[i]
            answer++
        }
        return answer
    }
}