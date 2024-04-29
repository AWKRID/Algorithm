import kotlin.math.min
class Solution {
    fun solution(X: String, Y: String): String {
        var answer: String = ""
        val digitList = listOf('0','1','2','3','4','5','6','7','8','9')
        for (ch in digitList) {
            answer += ch.toString().repeat(
                min(
                    X.count {
                        it == ch
                    },
                    Y.count {
                        it == ch
                    })
            )
        }
        if (answer.isEmpty()) return "-1"
        if (answer.toList().distinct() == listOf('0')) return "0"

        return answer.reversed()
    }
}
