class Solution {
    fun solution(n: Int, lost: IntArray, reserve: IntArray): Int {
        var answer = 0
        val lostList = lost.toMutableList()
        val reserveList = reserve.toMutableList()
        val removeList = mutableListOf<Int>()
        lostList.forEach{
            if(reserveList.contains(it)){
                removeList.add(it)
            }
        }
        lostList.removeAll(removeList)
        reserveList.removeAll(removeList)
        lostList.sort()
        reserveList.sort()
        for(i in lostList.indices){
            for(j in reserveList.indices){
                if(lostList[i] in reserveList[j]-1 .. reserveList[j]+1){
                    reserveList.removeAt(j)
                    answer++
                    break
                }
            }
        }
        return  n - lostList.size + answer
    }
}