# Combinatorics | 组合数学

## Permutations and Combinations | 排列组合

There are four basic counting principles and several counting formulas.

### Addition Principle | 加法原理

Suppose that a set $S$ is partitioned into pairwise disjoint parts $S_1,S_2 , \ldots,S_m$. The number of objects in $S$ satisfies:

$$
|S|=|S_1|+|S_2|+\cdots+|S_m|.
$$

### Subtraction Principle | 减法原理

Let $A$ be a set and let $U$ be a larger set containing $A$. Let $\bar{A} = U \setminus A = \{x \in U: x \notin A\}$ be the complement of $A$ in $U$. Then the number $|A|$ of objects in $A$ is given by the rule

$$
|A|=|U| - |\bar{A}|.
$$

### Multiplication Principle | 乘法原理

Let $S$ be a set of ordered pairs $(a, b)$ of objects, where the first object $a$ comes from a set of size $p$, and for each choice of object $a$ there are $q$ choices for object $b$. Then the size of $S$ satisfies:

$$
|S|=p \times q.
$$

### Division Principle | 除法原理

Let $S$ be a finite set that is partitioned into $k$ parts in such a way that each part contains the same number of objects. Then the number of parts in the partition is given by the rule

$$
k = \frac{|S|}{\text{number of objects in a part}}.
$$

### Permutations of Sets | 排列数

We denote by $P(n, r)$ the number of $r$-permutations of an $n$-element set. For $n$ and $r$ positive integers with $r \le n$,

$$
P(n,r)=\frac{n!}{(n-r)!}.
$$

### Combinations of Sets | 组合数

A combination of $S$ is a choice of a subset of $S$. We denote by $(\begin{smallmatrix}n\\r\end{smallmatrix})$ the number of $r$-subsets of an $n$-element
set. For $0 \le r \le n$,

$$
\begin{pmatrix}n\\r\end{pmatrix}=\frac{n!}{r!(n-r)!}.
$$

### Permutations of Multisets | 多重排列数

Let $S$ be a multiset with objects of $k$ different types, where each object has an infinite repetition number. Then the number of $r$-permutations of $S$ is

$$
k^r.
$$

Let $S$ be a multiset with objects of $k$ different types with finite repetition numbers $n_l, n_2, \ldots , n_k$, respectively. Let the size of $S$ be $n = n_l + n_2 + \ldots + n_k$.
Then the number of permutations of S equals

$$
\frac{n!}{n_1!n_2!\cdots n_k!}.
$$

### Combinations of Multisets | 多重组合数

Let $S$ be a multiset with objects of $k$ types, each with an infinite repetition number. Then the number of $r$-combinations of $S$ equals

$$
\begin{pmatrix}r+k-1\\r\end{pmatrix}=\begin{pmatrix}r+k-1\\k-1\end{pmatrix}.
$$

Let $S$ be a multiset with objects of $k$ different types with finite repetition numbers $n_l, n_2, \ldots , n_k$, respectively. Let the size of $S$ be $n = n_l + n_2 + \ldots + n_k$.
Then the number of $r$-combinations of $S$ equals the number of integral solutions of the equation $x_1 + x_2 + \cdots + x_k = r$ that satisfy $0 \le x_i \le n_i \, (i = 1, 2, \ldots, k)$. Let $P_i$ be the property that a solution of the equation satisfies $x_i > n_i$. Let $A_i$ consist of those solutions which have property $P_i \, (i = 1, 2, \ldots, k)$. Then the number of solutions equals

$$
|S| - \sum|A_i| + \sum|A_i \cap A_j| + \cdots + (-1)^k \left|\bigcap_{i=1}^k A_i\right|.
$$

## The Pigeonhole Principle | 鸽巢原理（抽屉原理）

If $n + 1$ objects are distributed into $n$ boxes, then at least one box contains two or more of the objects.

Let $q_l, q_2, . .. ,q_n$ be positive integers. If $q_l + q_2 + ... + q_n - n + 1$ objects are distributed into $n$ boxes, then either the first box contains at least $q_l$ objects, or the second box contains at least $q_2$ objects, ... , or the $n$th box contains at least $q_n$ objects.

If $m \ge 2$ and $n \ge 2$ are integers, then there is a positive integer $p$ such that $K_p \rightarrow K_m, K_n$.

## The Binomial Coefficients | 二项系数

### Pascal's Triangle | 杨辉三角

$$
\begin{pmatrix}n\\k\end{pmatrix}=\begin{pmatrix}n-1\\k\end{pmatrix}+\begin{pmatrix}n-1\\k-1\end{pmatrix}.
$$

### The Binomial Theorem | 二项式定理

$$
(x+y)^n=\sum_{k=0}^n \begin{pmatrix}n\\k\end{pmatrix}x^{k}y^{n-k}.
$$

### The Multinomial Theorem | 多项式定理

Let $n$ be a positive integer. For all $x_l, x_2, \ldots, x_t$,

$$
(x_1+x_2+\cdots+x_t)^n=\sum \begin{pmatrix}n\\n_1n_2\cdots n_t\end{pmatrix}x_1^{n_1}x_2^{n_2}\cdots x_t^{n_t},
$$

where the summation extends over all nonnegative integral solutions $n_l, n_2, \ldots, n_t$ of $n_l + n_2 + \cdots + n_t = n$.

### Newton's Binomial Theorem | 牛顿二项式定理

Let $\alpha$ be a real number. Then, for all $x$ and $y$ with $0 \le |x| < |y|$,

$$
(x+y)^\alpha=\sum_{k=0}^\infty \begin{pmatrix}\alpha\\k\end{pmatrix}x^{k}y^{\alpha-k}.
$$

where $(\begin{smallmatrix}\alpha\\k\end{smallmatrix})=\frac{\alpha(\alpha-1)\cdots (\alpha-k+1)}{k!}$.

### Partially Ordered Sets | 偏序关系

Let $(X,\le)$ be a finite partially ordered set, and let $r$ be the largest size of a chain. Then $X$ can be partitioned into $r$ but no fewer antichains.

Let $(X,\le)$ be a finite partially ordered set, and let $m$ be the largest
size of an antichain. Then $X$ can be partitioned into $m$ but no fewer chains.

## The Inclusion-Exclusion Principle | 容斥原理

The number of objects of the set $S$ that have none of the properties $P_1, P_2, \ldots, P_m$ is given by the alternating expression

$$
|\bar{A}_1 \cap \bar{A}_2 \cdots \bar{A}_m| = |S| - \sum|A_i| + \sum|A_i \cap A_j| + \cdots + (-1)^m \left|\bigcap_{i=1}^m A_i\right|.
$$

### Permutations with Forbidden Positions

### Mobius Inversion

## Recurrence Relations and Generating Functions

### Some Number Sequences

### Generating Functions

### Exponential Generating Functions

### Solving Linear Homogeneous Recurrence Relations

### Nonhomogeneous Recurrence Relations

### A Geometry Example

## Special Counting Sequences

## Others

Books

* [Introductory Combinatorics, 5th Edition](https://www.pearson.com/us/higher-education/product/Brualdi-Introductory-Combinatorics-5th-Edition/9780136020400.html). [Richard A. Brualdi](https://people.math.wisc.edu/~brualdi/), University of Wisconsin. 2010. Pearson.
* [组合数学（第5版）](http://www.tup.tsinghua.edu.cn/booksCenter/book_07098001.html). [卢开澄](http://www.tup.tsinghua.edu.cn/bookscenter/bookwritersay.html?id=07098001), 卢华明, 清华大学. 2016. 清华大学出版社.

Websites

* Combinatorics: <https://cp-algorithms.com/#combinatorics>
* 排列组合: <https://oi-wiki.org/math/combinatorics/combination/>
