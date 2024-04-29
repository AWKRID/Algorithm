class Solution {
    fun solution(lottos: IntArray, win_nums: IntArray): IntArray {
        var answer: MutableList<Int> = mutableListOf()
        var count = 0
        var zeroCount = 0
        for(num in lottos){
            if (win_nums.contains(num)){
                count ++ 
            } 
            if(num == 0) zeroCount ++
        }
        answer.add(count + zeroCount)
        answer.add(count)
        
        for(i in answer.indices){
            if(answer[i] >= 6) answer[i] = 1
            else if (answer[i] == 5) answer[i] = 2
            else if (answer[i] == 4) answer[i] = 3
            else if (answer[i] == 3) answer[i] = 4
            else if (answer[i] == 2) answer[i] = 5
            else answer[i] = 6
        }
        
        
        return answer.toIntArray()
    }
}