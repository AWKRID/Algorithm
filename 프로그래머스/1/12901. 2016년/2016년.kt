class Solution {
    fun solution(a: Int, b: Int): String {
        var day = 0
        for(i in 1 until a){
            when(i){
                1,3,5,7,8,10 -> day += 31
                2 -> day += 29
                else -> day += 30
            }
        }
        day += b
        day %= 7
        return when(day){
            1 -> "FRI"
            2 -> "SAT"
            3 -> "SUN"
            4 -> "MON"
            5 -> "TUE"
            6 -> "WED"
            0 -> "THU"
            else -> ""
        }


    }
}