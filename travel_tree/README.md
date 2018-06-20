# 国庆出游

## 涉及的知识点
树的深度优先搜索（DFS）和广度优先搜索（BFS）
a. 深度优先搜索
> 深度优先搜索（DFS）就是先沿着树枝最深的地方进行遍历，用动态规划的话就是一路遍历到底，代码实现的时候就是把树根的子树放入到栈中，出栈的同时再次对该节点进行DP
> 伪码如下：
> def dfs(root, result):
>	vector<int> a = tree[root]
>	while(a.size()!=0):
> 		result.push_back(a.back());
>		dfs(a.back(), result);
> 		a.pop(); 


b. 广度优先搜索
> 广度优先搜索（BFS）就是先将根节点之下的所有子节点遍历出来，然后在进行各子节点之下的遍历，实现上使用的是队列（先进先出），这里不再赘述。

## 解题难点
这道题比较容易忽略的一点是不管怎样，开始的起点必须是节点为1的根节点，而且每个路一个方向必须只能走一次，所以它的约束是很多的！

## 解题思路
1. 使用一个bitset记录每个节点与其他节点的联通关系，这个很重要，能大大的节约时间，而且有一个好处就是这个联通关系使用bit来表示的话，可以用或运算直接进行
2. 每条路之间还必须有一个标志位记录这个路（带有方向，即a->b和b->a是不一样的）是否走过了
3. 因为这是一个树形的结构，在DP的时候，还是要养成一个最小单元的习惯，即考虑递归函数的时候只考虑根和子叶就可以了

伪码如下：
```python
# 树形结构由vector<int> tree[N]中记录
# 对每一个节点生成联通图
def check_connect(root, parent):
	# 自己肯定是可以到自己的
	# 不要认为这一步是多余的，这个标志位在迭代回去的时候
	# 会被或到父节点的标志位上，表明父节点可以与该节点联通
	connect[root][root]=1
	# 遍历该节点的子节点
	for node in tree[root]:
		# 如果碰到了自己的父节点
		if node == parent:
			continue
		# 继续对自己的子节点进行遍历
		check_connect(node, root)
		# 子节点遍历完了一定要与父节点的联通或运算
		connect[root] |= connect[node]
		
# 深度优先搜索
def dfs(root, parent):
	# 如果当前节点就是要找的目标节点
	# 找寻下一个
	if root==target[index]:
		index++
	# 如果找完了
	if index == target.size():
		ok=True
		return
	# 如果没有找完
	# 注意这里必须要这个while循环
	# 结束条件就是当遍历之前与遍历之后的结果是一样的！
	while(index < target.size()):
		old_index = index
		next_target = target[index]
		for node in tree[root]:
			if node == parent:
				continue
			# 这个地方算是精华了
			# 首先对于当前节点的子节点node，我们是否要对node进行
			# 遍历的条件就是node与我们要找的点是联通的，而且当前
			# 节点到这个子节点node的路还必须是没有被走过的，那么
			# 我们就可以进行深度的遍历了
			if connect[node][ndex_target] and passed[root][node]:
				passed[root][node]=0
				dfs(node, root)
				break
		# 如果遍历了一遍之后index没有什么改变，说明这次遍历
		# 没有什么用了，就可以退出了
		if old_index == index:
			break;
```