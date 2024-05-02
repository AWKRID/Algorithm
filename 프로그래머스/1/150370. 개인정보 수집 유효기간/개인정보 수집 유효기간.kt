class Solution {
    fun solution(today: String, terms: Array<String>, privacies: Array<String>): IntArray {
        var answer = mutableListOf<Int>()
        val termMap = mutableMapOf<String, Int>()
        for(term in terms){
            val sign = term.split(" ")[0]
            val month = term.split(" ")[1]
            termMap[sign] = month.toInt() * 28
        }
        val todayDays = dateIntoDays(today)
        for( i in privacies.indices){
            val date = privacies[i].split(" ").first()
            val term = privacies[i].split(" ").last()
            if(dateIntoDays(date) + termMap[term]!! <= todayDays) answer.add(i+1)
        }
        return answer.toIntArray()
    }
    fun dateIntoDays(date: String): Int{
        val dateArr = date.split(".")
        val year = dateArr[0].toInt()
        val month = dateArr[1].toInt()
        val day = dateArr[2].toInt()
        return  (year-2000) * 336 + (month-1) * 28 + day
    }
}