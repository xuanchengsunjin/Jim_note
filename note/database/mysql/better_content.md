##### 分页优化
-------------------------------------------------------------------------------------------
  ```sql
    建议使用合理的分页方式以提高分页效率，大页情况下不使用跳跃式分页
    假如有类似下面分页语句:
        SELECT FROM table1 ORDER BY ftime DESC LIMIT 10000,10;
    这种分页方式会导致大量的io，因为MySQL使用的是提前读取策略。
    推荐分页方式：
        SELECT * FROM table1 WHERE ftime < last_time ORDER BY ftime DESC LIMIT 10;
        SELECT * FROM table as t1 inner JOIN (SELECT id FROM table ORDER BY time LIMIT 10000，10) as t2 ON t1.id=t2.id;
  ```

##### explain
-------------------------------------------------------------------------------------------

  - [ ] type性能比较
  ```
    通常来说, 不同的 type 类型的性能关系如下:
    ALL < index < range ~ index_merge < ref < eq_ref < const < system
    ALL 类型因为是全表扫描, 因此在相同的查询条件下, 它是速度最慢的.
    而 index 类型的查询虽然不是全表扫描, 但是它扫描了所有的索引, 因此比 ALL 类型的稍快.
    后面的几种类型都是利用了索引来查询数据, 因此可以过滤部分或大部分数据, 因此查询效率就比较高了.
  ```
  
