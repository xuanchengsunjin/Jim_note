#### [存在重复元素](https://leetcode-cn.com/explore/learn/card/hash-table/204/practical-application-hash-set/805/)

> 给定一个整数数组，判断是否存在重复元素。<br>
> 如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。<br>

  示例 1:
  ```bash
  输入: [1,2,3,1]
  输出: true
  ```

  - [ ] 解法1:
  > 先排序，再遍历，时间复杂度取决于排序算法<br>
  > 优点:空间复杂度为O(N),N为nums的长度<br>
  > 缺点:时间复杂度高<br>
  ```C++
    /**
        author:jim_sun
        @parm nums:待检验的vector数组
        @return false:不存在重复元素, true:存在重复元素
        @function 函数实现功能如本篇开头所述
    **/
    class Solution {
        public:
            bool containsDuplicate(vector<int>& nums) {
                sort(nums.begin(), nums.end());
                for (int i = 1;i < nums.size();i++){
                    if(nums[i] == nums[i - 1])
                        return true;
                }
                return false;
            }
    };
  ```

  - [ ] 解法2:
  > 利用数组,数组索引大小为整数最大值<br>
  > 优点:时间复杂度为O(N),N为nums的长度,思想与用哈希表类似<br>
  > 缺点:空间复杂度过高,可能导致程序运行不了,牺牲空间换取时间<br>
  ```C++
     /**
        author:jim_sun
        @parm nums:待检验的vector数组
        @return false:不存在重复元素, true:存在重复元素
        @function 函数实现功能如本篇开头所述
    **/
    class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            int count = std::numeric_limits<int>::max(); //count为int类型最大值
            bool arr_positive[count];//正整数数组,每个数组值表示该索引值是否已出现
            bool arr_negative[count];//负整数数组
            //初始化数组
            for (int j = 0;j < count;j++){
                arr_positive[j] = false;
                arr_negative[j] = false;
            }
            
            for(int i = 0;i < nums.size();i++){
                int temp = nums[i];
                int index = 0;
                if (temp < 0){
                    temp = -temp;
                    if(arr_negative[temp])
                        return true;
                    arr_negative[temp] = true;
                }
                else{
                    if(arr_positive[temp])
                        return true;
                    arr_positive[temp] = true;
                }
            }
            return false;
        }
    };
  ```

  - [ ] 解法3:
  > 利用哈希表/Set<br>
  > 优点:时间复杂度为O(N),N为nums的长度<br>
  > 缺点:空间复杂度高,牺牲空间换取时间<br>
  ```C++
     /**
        author: 
        @parm nums:待检验的vector数组
        @return false:不存在重复元素, true:存在重复元素
        @function 函数实现功能如本篇开头所述
    **/
    class Solution {
        public:
            bool containsDuplicate(vector<int>& nums) {
                unordered_set<int> hashset;
                for (auto num : nums) {
                    if (hashset.count(num) > 0) {
                        return true;
                    }
                    hashset.insert(num);
                }

                return false;      
            }
    };
  ```

  - [ ] 解法4：
  > 利用[bigset](https://github.com/xuanchengsunjin/Jim_note/blob/sandbox/note/algorithm/algorithm_other/big_set.md)<br>
  > 优点:时间复杂度为O(N),N为nums的长度<br>
  > 缺点:空间复杂度还好,是解法2的改良版,目的是优化空间复杂度,牺牲空间换取时间<br>
  ```C++
     /**
        author:jim_sun
        @parm nums:待检验的vector数组
        @return false:不存在重复元素, true:存在重复元素
        @function 函数实现功能如本篇开头所述
    **/
  ```
