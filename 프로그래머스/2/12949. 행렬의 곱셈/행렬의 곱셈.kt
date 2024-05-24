class Solution {
    fun solution(arr1: Array<IntArray>, arr2: Array<IntArray>): Array<IntArray> {
        var answer = Array(arr1.size) {IntArray(arr2[0].size)}
        var arr1Row = arr1.size
        var arr1Col = arr1[0].size
        var arr2Col = arr2[0].size
        
        for(i in 0 until arr1Row) {
            for(j in 0 until arr2Col){
                var sum = 0
                for(k in 0 until arr1Col){
                    sum += arr1[i][k] * arr2[k][j]
                }
                answer[i][j] = sum
            }
        }
        return answer
    }
}