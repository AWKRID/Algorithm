import kotlin.math.sqrt

class Solution {
    fun solution(number: Int, limit: Int, power: Int): Int {
        val costList : MutableList<Int> = mutableListOf()

        for(i in 1..number){
            var count = 0
            for(j in 1 ..sqrt(i.toDouble()).toInt()){
                if(i % j == 0 && j*j != i ) count +=2
                if(i%j==0 && j *j == i) count++
                if(count > limit) {
                    count = power
                    break
                }
            }
            costList.add(count)
        }
        return costList.sum()
    }
}