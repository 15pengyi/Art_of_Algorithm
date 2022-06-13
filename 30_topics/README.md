# Topics

## Combinatorics | 组合数学

### Permutations and Combinations | 排列组合

There are four basic counting principles and several counting formulas.

#### Addition Principle | 加法原理

Suppose that a set $S$ is partitioned into pairwise disjoint parts $S_1,S_2 , \ldots,S_m$. The number of objects in $S$ satisfies:

$$
|S|=|S_1|+|S_2|+\cdots+|S_m|.
$$

#### Subtraction Principle | 减法原理

Let $A$ be a set and let $U$ be a larger set containing $A$. Let $\bar{A} = U \setminus A = \{x \in U: x \notin A\}$ be the complement of $A$ in $U$. Then the number $|A|$ of objects in $A$ is given by the rule

$$
|A|=|U| - |\bar{A}|.
$$

#### Multiplication Principle | 乘法原理

Let $S$ be a set of ordered pairs $(a, b)$ of objects, where the first object $a$ comes from a set of size $p$, and for each choice of object $a$ there are $q$ choices for object $b$. Then the size of $S$ satisfies:

$$
|S|=p \times q.
$$

#### Division Principle | 除法原理

Let $S$ be a finite set that is partitioned into $k$ parts in such a way that each part contains the same number of objects. Then the number of parts in the partition is given by the rule

$$
k = \frac{|S|}{\text{number of objects in a part}}.
$$

#### Permutations of Sets | 排列数

We denote by $P(n, r)$ the number of $r$-permutations of an $n$-element set. For $n$ and $r$ positive integers with $r \le n$,

$$
P(n,r)=\frac{n!}{(n-r)!}.
$$

#### Combinations of Sets | 组合数

A combination of $S$ is a choice of a subset of $S$. We denote by $(\begin{smallmatrix}n\\r\end{smallmatrix})$ the number of $r$-subsets of an $n$-element
set. For $0 \le r \le n$,

$$
\begin{pmatrix}n\\r\end{pmatrix}=\frac{n!}{r!(n-r)!}.
$$

#### Permutations of Multisets | 多重排列数

Let $S$ be a multiset with objects of $k$ different types, where each object has an infinite repetition number. Then the number of $r$-permutations of $S$ is

$$
k^r.
$$

Let $S$ be a multiset with objects of $k$ different types with finite repetition numbers $n_l, n_2, \ldots , n_k$, respectively. Let the size of $S$ be $n = n_l + n_2 + \ldots + n_k$.
Then the number of permutations of S equals

$$
\frac{n!}{n_1!n_2!\cdots n_k!}.
$$

#### Combinations of Multisets | 多重组合数

Let $S$ be a multiset with objects of $k$ types, each with an infinite repetition number. Then the number of $r$-combinations of $S$ equals

$$
\begin{pmatrix}r+k-1\\r\end{pmatrix}=\begin{pmatrix}r+k-1\\k-1\end{pmatrix}.
$$

Let $S$ be a multiset with objects of $k$ different types with finite repetition numbers $n_l, n_2, \ldots , n_k$, respectively. Let the size of $S$ be $n = n_l + n_2 + \ldots + n_k$.
Then the number of $r$-combinations of $S$ equals the number of integral solutions of the equation $x_1 + x_2 + \cdots + x_k = r$ that satisfy $0 \le x_i \le n_i \, (i = 1, 2, \ldots, k)$. Let $P_i$ be the property that a solution of the equation satisfies $x_i > n_i$. Let $A_i$ consist of those solutions which have property $P_i \, (i = 1, 2, \ldots, k)$. Then the number of solutions equals

$$
|S| - \sum|A_i| + \sum|A_i \cap A_j| + \cdots + (-1)^k \left|\bigcap_{i=1}^k A_i\right|.
$$

### The Pigeonhole Principle | 鸽巢原理（抽屉原理）

### The Binomial Coefficients | 二项系数

### The Inclusion-Exclusion Principle | 容斥原理

## Others

Books

* [Introductory Combinatorics, 5th Edition](https://www.pearson.com/us/higher-education/product/Brualdi-Introductory-Combinatorics-5th-Edition/9780136020400.html). [Richard A. Brualdi](https://people.math.wisc.edu/~brualdi/), University of Wisconsin. 2010. Pearson.

Websites

* Combinatorics: <https://cp-algorithms.com/#combinatorics>
* 排列组合: <https://oi-wiki.org/math/combinatorics/combination/>
