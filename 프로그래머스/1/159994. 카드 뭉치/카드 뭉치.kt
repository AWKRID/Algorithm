class Solution {
    fun solution(cards1: Array<String>, cards2: Array<String>, goal: Array<String>): String {
        var answer: String = "Yes"
        val cards1List = cards1.toMutableList()
        val cards2List = cards2.toMutableList()
        val goalList = goal.toMutableList()
        for(word in goal){
            if(cards1List.isNotEmpty() && word == cards1List[0]){
                cards1List.remove(word)
                goalList.remove(word)
            }else if(cards2List.isNotEmpty() &&word == cards2List[0]){
                cards2List.remove(word)
                goalList.remove(word)
            }else{
                return "No"
            }
        }
        return answer
    }
}