# 聚类实验

- 数据集：[NVIE_PS_feature.csv](..\data\NVIE_PS_feature.csv) from USTC-NVIE中的自发部分
- 工具包：sklearn, numpy, pandas

### 结果

共使用了两种方法：K-Means和 Mean Shift

K-Means方法可以指定目标类的数量，因此可以与真实结果比较正确率。最终正确率为0.322 (依赖于随机种子)。

由于数据集的数据点在数据空间上距离较近，Mean Shift 方法不能指定聚出的类数，就难以得到6种表情的分类。 