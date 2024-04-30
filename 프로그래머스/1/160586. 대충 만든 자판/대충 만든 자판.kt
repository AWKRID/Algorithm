import kotlin.math.min

class Solution {
    fun solution(keymap: Array<String>, targets: Array<String>): IntArray {
        var answer: MutableList<Int> = mutableListOf()

        var minKeyMap = mutableMapOf<String, Int>()
        for (key in keymap) {
            for (i in key.indices) {
                if (minKeyMap.containsKey(key[i].toString())) {
                    minKeyMap[key[i].toString()] = min(minKeyMap[key[i].toString()]!!, i + 1)
                }
                else{
                    minKeyMap[key[i].toString()] = i+1
                }
            }
        }

        for (target in targets) {
            var count = 0
            for (i in target.indices) {
                if (!minKeyMap.containsKey(target[i].toString())) {
                    count = -1
                    break
                }
                count += minKeyMap[target[i].toString()]!!

            }
            answer.add(count) 
        }


        return answer.toIntArray()
    }
}