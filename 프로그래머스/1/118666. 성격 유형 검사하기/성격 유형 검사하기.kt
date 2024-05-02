class Solution {
    fun solution(survey: Array<String>, choices: IntArray): String {
        val map = mutableMapOf("R" to 0, "T" to 0, "C" to 0, "F" to 0, "J" to 0, "M" to 0, "A" to 0, "N" to 0)

        var answer: String = ""
        for(idx in survey.indices){
            val first = survey[idx][0].toString()
            val second = survey[idx][1].toString()
            val score = score(choices[idx])
            if(score >0) map[first] = map[first]!! + score
            else map[second] = map[second]!! - score
        }
        answer += if(map["R"]!! >= map["T"]!!) "R" else "T"
        answer += if (map["C"]!! >= map["F"]!!) "C" else "F"
        answer += if (map["J"]!! >= map["M"]!!) "J" else "M"
        answer += if (map["A"]!! >= map["N"]!!) "A" else "N"

        return answer
    }



    fun score(choice : Int) : Int{
        return when(choice){
            1 -> 3
            2 -> 2
            3 -> 1
            4 -> 0
            5 -> -1
            6 -> -2
            7 ->-3
            else -> -100
        }
    }
}