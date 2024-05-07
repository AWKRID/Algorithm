class Solution {
    fun solution(id_list: Array<String>, report: Array<String>, k: Int): IntArray {
        val map = mutableMapOf<String, Int>()
        report.distinct().forEach {
            val key = it.split(' ')[1]
            map[key] = map.getOrDefault(key, 0) + 1
        }
        val filteredList = map.filterValues { it >= k }

        val answer = mutableMapOf<String, Int>()
        id_list.forEach {
            answer[it] = 0
        }

        report.distinct().forEach {
            val key = it.split(' ')[0]
            if (filteredList.contains(it.split(' ')[1])) answer[key] = answer.getOrDefault(key, 0) + 1
        }
        return answer.values.toIntArray()
    }
}