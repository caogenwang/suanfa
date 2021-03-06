#define MAXN 100
//初始化
int fa[MAXN];
inline void init(int n)
{
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
}
/*
    假如有编号为1, 2, 3, ..., n的n个元素，我们用一个数组fa[]来存储每个元素的父节点
    （因为每个元素有且只有一个父节点，所以这是可行的）。一开始，我们先将它们的父节点设为自己。
*/

//查询
int find(int x)
{
    if(fa[x] == x)
        return x;
    else
        return find(fa[x]);
}
/*
    我们用递归的写法实现对代表元素的查询：一层一层访问父节点，直至根节点（根节点的标志就是父节点是本身）。
    要判断两个元素是否属于同一个集合，只需要看它们的根节点是否相同即可。
*/

//合并
inline void merge(int i, int j)
{
    fa[find(i)] = find(j);
}
/*
    合并操作也是很简单的，先找到两个集合的代表元素，然后将前者的父节点设为后者即可。
    当然也可以将后者的父节点设为前者，这里暂时不重要。本文末尾会给出一个更合理的比较方法。
*/

//路径压缩
