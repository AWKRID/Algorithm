
class Solution {
    fun solution(babbling: Array<String>): Int {
        val possibleWords = listOf("aya","ye","woo","ma")
        val answerList : MutableList<String> = babbling.toMutableList()
        var answer: Int =0

        for(i in answerList.indices){
            for(j in possibleWords.indices){
                answerList[i] = answerList[i].replace(possibleWords[j], "${j+1}")
            }
        }
        
        for(word in answerList){
            var flag = 0
            for(i in word.indices){
                if( word[i] != '1' && word[i] !='2' && word[i] !='3' && word[i] !='4')flag = 1
                if(i !=word.lastIndex && word[i] == word[i+1]) flag = 1
            }
            if(flag == 0) answer++
        }

        return answer
    }
}