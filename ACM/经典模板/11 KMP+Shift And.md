# KMP&Shife And

## KMP

- 作用

> 模式匹配算法，在一个文本串S内查找一个模式串P的出现位置；目标串的个别后缀；模式串的最大公共前缀

- 模式匹配算法
>
> 1. 算法目的：确定主串中所含子串第一次出现的位置
> 2. 初始条件：串S和T存在，T是非空串，$1 \leq pos \leq StrLength（S）$
> 3. 操作结果：若主串S第pos个字符起存在和串T值相同的子串，，则返回它在主串S中第一次出现的位置，否则`return 0`  
> 注：S称为被匹配的串，T称为模式串。若S包含串T，则称“匹配成功”，否则称“匹配不成功”

- next数组代码模板

```C++
void getnext(int len)
{
    int j, k;
    j = 0;
    k = -1;//初始化值为-1且下标从0开始
    next[0] = -1;
    while(j < len)
    {
        if( k == -1 || b[j] == b[k])
        {
            j++;
            k++;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
}
```

- KMP代码模板

```C++
int kmp(int len1, int len2)
{
    int i, j;
    int cnt = 0;
    i = 0;
    j = 0;
    getnext(len2);//得到目标串的next数组
    while(i < len1)
    {
        if(j == -1 || a[i] == b[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
        if(j == len2)
        {
            cnt++;//记录目标串出现的次数
        }
    }
    return cnt;
}
```

## Shift And

[字符串匹配shiftand算法](https://blog.csdn.net/silence401/article/details/77446537)
