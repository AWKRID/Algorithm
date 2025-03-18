#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    set<int> uniq = set(nums.begin(), nums.end());
    
    return min(nums.size()/2, uniq.size()); 
}