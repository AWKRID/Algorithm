class Solution {
    fun solution(s: String): Int {
        val numbers :Map<Int, String> = mapOf(1 to "one", 2 to "two", 3 to "three", 4 to "four", 5 to "five", 6 to "six", 7 to "seven", 8 to "eight", 9 to "nine",0 to "zero")
        var replacedString = s
        for(number in numbers){
          replacedString = replacedString.replace(number.value, number.key.toString())  
        }
        var answer: Int = replacedString.toInt()
        return answer
        
    }
}