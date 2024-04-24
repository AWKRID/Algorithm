class Solution {
    fun solution(sizes: Array<IntArray>): Int {
        val widthArr : IntArray = IntArray(sizes.size) 
        val heightArr: IntArray = IntArray(sizes.size)
        for(i in sizes.indices) {
            if(sizes[i][0] < sizes[i][1]) {
                widthArr[i] = sizes[i][0]
                heightArr[i] = sizes[i][1]
            }else{
                widthArr[i] = sizes[i][1]
                heightArr[i] = sizes[i][0]
            }
        }
        val maxWidth = widthArr.maxOrNull()
        val maxHeight = heightArr.maxOrNull()

        return maxWidth!! * maxHeight!!

    }
}
