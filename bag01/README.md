# 01背包问题

## 解题思路
### 常规思路
背包问题的精髓在于在第i行，每一个值表示在该容量下，背包所获得的最大利益
伪码：
```objectivec
for i=0:N  // 球的数量
    for j=0:M    // 背包的容量
        if i==0
            if j >= weight(i)
                bag[i][j]=value(i)
        else
            if j >= weight(i)
                // 把当前球放进去，但是要拿出相应的重量，之后两者的利益之和是否会大于
                // 不放入该球的利益
                bag[i][j]=max(bag[i-1][j-weight(i)]+value(i), bag[i-1][j])
            else
                bag[i][j]=bag[i-1][j]
```


### 空间节约思路
常规思路里面可以看到用了一个很大的bag来存储每次的迭代值，其实对于背包问题，只需要一个行向量就可以解决了，思路就是从背包的最大值开始进行迭代
伪码：
```objectivec
for i=0:N  // 球的数量
    for j=M:0    // 背包的容量
        if (j > weight(i))
            // 从后面遍历其实是保证了上次的结果能保存在前j个值中
            bag[j]=max(bag[j-weight(i)]+value(i), bag[j])
```