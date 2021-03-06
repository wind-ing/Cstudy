# DFS+剪枝

## DFS

- 概念  

> DFS即深度优先搜索算法，是为了解决图结构的遍历搜索问题的一种方法

- 适合情况  

> 具有递归性质的问题  
适合地图类型的问题  
需要情况列举的问题  
相比bfs更适合树结构

- 判断思路

> 看状态能否转换成树结构和图结构  
思考转化后状态的数据量
如果数据量多，思考是否有可能进行剪枝处理  
判断是否能用DFS

- 算法模板（伪代码）

```C++
void dfs()//参数用来表示状态
{
    if（到达终点状态）
    {
        ...//根据题意添加
        return;
    }
    if(越界或者是不合法状态)
        return;
    for(扩展方式)
    {
        if(扩展方式所达到状态合法)
        {
            修改操作;//根据题意来添加
            标记;
            dfs();
            (还原标记);
            //是否还原标记根据题意
            //如果加上(还原标记)就是 回溯法
        }
    }
}
```

## 剪枝

- 概念

> DFS就是一种暴力全搜索的方法，为了应对大量数据的运算限制，就要对DFS搜索的情况做一个筛选优化去掉无用状态，提高算法速度，这样的操作就是剪枝。

- 常见分类

> 可行性剪枝：走到某一步时，已经可以判断不能够达成目的，那么久不再继续往下走，直接return
> 最优化剪枝：通常用于求解最值情况，当走到某一步发现已经比目前所求最小值大的时候就不再继续下去
> 奇偶剪枝：对奇数步（或者偶数步）完全不需要的情况下，直接剪掉这些状态
> 重复性剪枝：去掉重复状态
