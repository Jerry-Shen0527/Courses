# 作业1 线性分类器的使用

- 数据集：[NVIE_PS_feature.csv](Homework\1_LinearClassification\data\NVIE_PS_feature.csv) from USTC-NVIE中的自发部分

- 工具包：sklearn, numpy, pandas
- 分类方法：SVM、Logistic、SGD

### 结果比较

- 交叉验证方法：N-fold cross validation
- 评价标准：macro-precision, macro-Recall, macro-F1

其中macro的意义是，对每个类别进行二分类，然后做不加权平均。

| 方法                                 | SVM                                                          | SGD                                                          | Logistic                                                     |
| ------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Precision                            | 0.4163431                                                    | 0.40913566                                                   | 0.4305369                                                    |
| Recall                               | 0.4160352                                                    | 0.392065                                                     | 0.4245931                                                    |
| F1                                   | 0.407171                                                     | 0.392549                                                     | 0.4226251                                                    |
| 学习曲线(横轴为数据量，纵轴为Recall) | ![SVC](.\SVC.png) | ![SGDClassifier](.\SGDClassifier-1587101451722.png) | ![LogisticRegression](.\LogisticRegression.png) |

### 讨论

首先是方法的有效性：考虑随机分类，得到结果的Precision应该在$\frac{1}{6}=0.1667$左右，学习后的结果对此是有提升的。

三种方法相比，Logistic回归得到的分类效果准确率和召回率较高，而且学习曲线也比较稳定，应该是这三种方法中最好的。

### 额外工作

调用tensorflow2.0的keras接口，进行简单分类。目标函数为交叉熵。划出20%作为验证集，选取合适的终止epoch。

结果：

![auc](.\auc.png)

![curve](.\curve.png)

在测试集上的结果为: Precision=0.523273，好于线性的结果。