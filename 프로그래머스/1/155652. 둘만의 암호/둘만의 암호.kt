class Solution {
    fun solution(s: String, skip: String, index: Int): String {
        var answer: String = ""
        var alphaList = mutableListOf<Char>()
        
        
        for(char in 'a' .. 'z') alphaList.add(char)
        
        for (char in skip){
            alphaList.remove(char)
        }
        for(char in s){
            val idx = (alphaList.indexOf(char) + index) % alphaList.size
            answer += alphaList[idx]
        }
        
        return answer
    }
}