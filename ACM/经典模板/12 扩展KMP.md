# e-KMP&AC自动机

## e-KMP

- 作用：即扩展KMP，可以求出目标串的所有后缀与模式串的最大公共前缀

- 代码模板

```C++
struct e_KMP
{
    int Next[MAXN], extend[MAXN];
    char S[MAXN], T[MAXN];
    int lenS, lenT;

    void init()
    {
        scanf("%s%s", S, T);
        lenS = strlen(S), lenT = strlen(T);
    }
    void get_next()
    {
        Next[0] = lenT, Next[1] = 0;
        while(Next[1] + 1 < lenT && T[Next[1]] == T[Next[1] + 1])
        {
            Next[1]++;
        }
        int k = 1, p = Next[1];
        for(int i = 2; i < lenT; i++)
        {
            if(p > i + Next[i - k] - 1)
            {
                Next[i] = Next[i - k];
            }
            else
            {
                Next[i] = max(0, p - i + 1);
                while (i + Next[i] < lenT && T[i + Next[i]] == T[Next[i]])
                {
                    Next[i]++;
                }
                k = i, p = i + Next[i] - 1;
            }
        }
    }
    void work()
    {
        get_next(), extend[0] = 0;
        while (extend[0] < lenS && extend[0] < lenT && S[extend[0]] == T[extend[0]])
        {
            extend[0]++;
        }
        int k = 0, p = extend[0] - 1;
        for (int i = 1; i < lenS; i++)
        {
            if (p > i + Next[i - k] - 1)
            {
                extend[i] = Next[i - k];
            }
            else
            {
                extend[i] = max(0, p - i + 1);
                while (i + extend[i] < lenS && extend[i] < lenT && S[i + extend[i]] == T[extend[i]])
                {
                    extend[i]++;
                }
                k = i, p = i + extend[i] - 1;
            }
        }
}
```

## AC自动机

- 作用：单个目标串和多个模式串的匹配
- 在字典树上实现这些操作

## Manacher

- 作用：解决以每一个位置为中心的回文串的长度
