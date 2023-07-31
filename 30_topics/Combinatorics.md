---
marp: true
math: katex
---

# Combinatorics | 组合数学

---

## 1 What, Is Combinatorics? | 楔子

---

## 2 Permutations and Combinations | 排列组合

---

There are four basic counting principles and several counting formulas.

### 2.1 Addition Principle | 加法原理

Suppose that a set $S$ is partitioned into pairwise disjoint parts $S_1,S_2 , \ldots,S_m$. The number of objects in $S$ satisfies:

$$
|S|=|S_1|+|S_2|+\cdots+|S_m|.
$$

---

### 2.2 Subtraction Principle | 减法原理

Let $A$ be a set and let $U$ be a larger set containing $A$. Let $\bar{A} = U \setminus A = \{x \in U: x \notin A\}$ be the complement of $A$ in $U$. Then the number $|A|$ of objects in $A$ is given by the rule

$$
|A|=|U| - |\bar{A}|.
$$

---

### 2.3 Multiplication Principle | 乘法原理

Let $S$ be a set of ordered pairs $(a, b)$ of objects, where the first object $a$ comes from a set of size $p$, and for each choice of object $a$ there are $q$ choices for object $b$. Then the size of $S$ satisfies:

$$
|S|=p \times q.
$$

---

### 2.4 Division Principle | 除法原理

Let $S$ be a finite set that is partitioned into $k$ parts in such a way that each part contains the same number of objects. Then the number of parts in the partition is given by the rule

$$
k = \frac{|S|}{\text{number of objects in a part}}.
$$

---

### 2.5 Permutations of Sets | 排列数

We denote by $P(n, r)$ the number of $r$-permutations of an $n$-element set. For $n$ and $r$ positive integers with $r \le n$,

$$
P(n,r)=\frac{n!}{(n-r)!}.
$$

---

### 2.6 Combinations of Sets | 组合数

A combination of $S$ is a choice of a subset of $S$. We denote by $(\begin{smallmatrix}n\\r\end{smallmatrix})$ the number of $r$-subsets of an $n$-element
set. For $0 \le r \le n$,

$$
\begin{pmatrix}n\\r\end{pmatrix}=\frac{n!}{r!(n-r)!}.
$$

---

### 2.7 Permutations of Multisets | 多重排列数

Let $S$ be a multiset with objects of $k$ different types, where each object has an infinite repetition number. Then the number of $r$-permutations of $S$ is

$$
k^r.
$$

Let $S$ be a multiset with objects of $k$ different types with finite repetition numbers $n_1, n_2, \ldots , n_k$, respectively. Let the size of $S$ be $n = n_1 + n_2 + \ldots + n_k$.
Then the number of permutations of S equals

$$
\frac{n!}{n_1!n_2!\cdots n_k!}.
$$

---

### 2.8 Combinations of Multisets | 多重组合数

Let $S$ be a multiset with objects of $k$ types, each with an infinite repetition number. Then the number of $r$-combinations of $S$ equals

$$
\begin{pmatrix}r+k-1\\r\end{pmatrix}=\begin{pmatrix}r+k-1\\k-1\end{pmatrix}.
$$

Let $S$ be a multiset with objects of $k$ different types with finite repetition numbers $n_1, n_2, \ldots , n_k$, respectively. Let the size of $S$ be $n = n_1 + n_2 + \ldots + n_k$. Then the number of $r$-combinations of $S$ equals the number of integral solutions of the equation $x_1 + x_2 + \cdots + x_k = r$ that satisfy $0 \le x_i \le n_i \, (i = 1, 2, \ldots, k)$.

---

Let $P_i$ be the property that a solution of the equation satisfies $x_i > n_i$. Let $A_i$ consist of those solutions which have property $P_i \, (i = 1, 2, \ldots, k)$. Then the number of solutions equals

$$
|S| - \sum|A_i| + \sum|A_i \cap A_j| + \cdots + (-1)^k \left|\bigcap_{i=1}^k A_i\right|.
$$

---

## 3 The Pigeonhole Principle | 鸽巢原理（抽屉原理）

---

If $n + 1$ objects are distributed into $n$ boxes, then at least one box contains two or more of the objects.

Let $q_1, q_2, . .. ,q_n$ be positive integers. If $q_1 + q_2 + ... + q_n - n + 1$ objects are distributed into $n$ boxes, then either the first box contains at least $q_1$ objects, or the second box contains at least $q_2$ objects, ... , or the $n$th box contains at least $q_n$ objects.

If $m \ge 2$ and $n \ge 2$ are integers, then there is a positive integer $p$ such that $K_p \rightarrow K_m, K_n$.

---

## 4 Generating Permutations and Combinations | 排列组合的生成

---

## 5 The Binomial Coefficients | 二项系数

---

### 5.1 Pascal's Triangle | 杨辉三角

$$
\begin{pmatrix}n\\k\end{pmatrix}=\begin{pmatrix}n-1\\k\end{pmatrix}+\begin{pmatrix}n-1\\k-1\end{pmatrix}.
$$

---

### 5.2 The Binomial Theorem | 二项式定理

$$
(x+y)^n=\sum_{k=0}^n \begin{pmatrix}n\\k\end{pmatrix}x^{k}y^{n-k}.
$$

---

### 5.3 The Multinomial Theorem | 多项式定理

Let $n$ be a positive integer. For all $x_1, x_2, \ldots, x_t$,

$$
(x_1+x_2+\cdots+x_t)^n=\sum \begin{pmatrix}n\\n_1n_2\cdots n_t\end{pmatrix}x_1^{n_1}x_2^{n_2}\cdots x_t^{n_t},
$$

where the summation extends over all nonnegative integral solutions $n_1, n_2, \ldots, n_t$ of $n_1 + n_2 + \cdots + n_t = n$.

---

### 5.4 Newton's Binomial Theorem | 牛顿二项式定理

Let $\alpha$ be a real number. Then, for all $x$ and $y$ with $0 \le |x| < |y|$,

$$
(x+y)^\alpha=\sum_{k=0}^\infty \begin{pmatrix}\alpha\\k\end{pmatrix}x^{k}y^{\alpha-k}.
$$

where $(\begin{smallmatrix}\alpha\\k\end{smallmatrix})=\frac{\alpha(\alpha-1)\cdots (\alpha-k+1)}{k!}$.

---

### 5.5 Partially Ordered Sets | 偏序关系

Let $(X,\le)$ be a finite partially ordered set, and let $r$ be the largest size of a chain. Then $X$ can be partitioned into $r$ but no fewer antichains.

Let $(X,\le)$ be a finite partially ordered set, and let $m$ be the largest
size of an antichain. Then $X$ can be partitioned into $m$ but no fewer chains.

---

## 6 The Inclusion-Exclusion Principle | 容斥原理

---

The number of objects of the set $S$ that have none of the properties $P_1, P_2, \ldots, P_m$ is given by the alternating expression

$$
|\bar{A}_1 \cap \bar{A}_2 \cdots \bar{A}_m| = |S| - \sum|A_i| + \sum|A_i \cap A_j| + \cdots + (-1)^m \left|\bigcap_{i=1}^m A_i\right|.
$$

---

### 6.1 Permutations with Forbidden Positions

The number of ways to place $n$ nonattacking, indistinguishable rooks
on an $n$-by-$n$ board with forbidden positions equals

$$
n!-r_1(n-1)!+\cdots+(-1)^kr_k(n-k)!+\cdots+(-1)^nr_n,
$$

where $r_k$ is the number of ways to place $k$ nonattacking rooks on the $n$-by-$n$ board where each of the k rooks is in a forbidden position, $(k = 1,2 ... , n)$.

---

### 6.2 M$\"o$bius Inversion

Let $(X,\le)$ be a partially ordered set with a smallest element $0$. Let $\mu$ be its M$\"o$bius function, and let $F : X \rightarrow \mathfrak{R}$ be a real-valued function defined on $X$. Let the function $G : X \rightarrow \mathfrak{R}$ be defined by $G(x) = \sum_{\{z: z \le x\}} F(z), (x \in X)$. Then

$$
F(x) = \sum_{\{y: y \le x\}} G(y)\mu(y, x), (x \in X),
$$

where $\mu * \zeta = \delta$,  the Kronecker delta function is given by $\delta = \left\{ \begin{array}{ll}1, & \text{if} \, x = y\\0, & \text{otherwise} \end{array} \right.$ and $\zeta = \left\{ \begin{array}{ll}1, & \text{if} \, x \le y\\0, & \text{otherwise} \end{array} \right.$ is the zeta function .

---

## 7 Recurrence Relations and Generating Functions | 递推关系与母函数

---

### 7.1 Some Number Sequences

The Fibonacci numbers satisfy the formula

$$
f_n = \frac{1}{\sqrt{5}}\left(\frac{1+\sqrt{5}}{2}\right)^n-\frac{1}{\sqrt{5}}\left(\frac{1-\sqrt{5}}{2}\right)^n, (n \ge 0).
$$

The sums of the binomial coefficients along the diagonals of Pascal's
triangle running upward from the left are Fibonacci numbers. More precisely, the $n$th Fibonacci number $f_n$ satisfies

$$
f_n = \begin{pmatrix}n-1\\0\end{pmatrix}+\begin{pmatrix}n-2\\1\end{pmatrix}+ \cdots +\begin{pmatrix}n-t\\t-1\end{pmatrix},
$$

where $t = \lfloor\frac{n - 1}{2}\rfloor$.

---

### 7.2 Generating Functions

Let $n$ be a positive integer. Then

$$
g_n(x) = 1(1 + x)(l + x + \cdots + x^2) \cdots (1 + x + x^2 + \cdots + x^{n-1}) = \frac{\prod_{j=1}^n(1-x^j)}{(1-x)^n}.
$$

---

### 7.3 Exponential Generating Functions

Let $S$ be the multiset $\{n_j \cdot a_j, n_2 \cdot a_2, \ldots, n_k \cdot a_k\}$, where $n_1, n_2, \ldots, n_k$ are nonnegative integers. Let $h_n$ be the number of $n$-permutations of $S$. Then the exponential generating function $g^{(e)}(x)$ for the sequence $h_0, h_1, h_2, \ldots, h_n$ is given by

$$
g^{(e)}(x) = f_{n_1}(x)f_{n_2}(x)\cdots f_{n_k}(x)
$$

where, for $i = 1, 2, \ldots, k$, $f_{n_i}(x) = 1 + x + \frac{x^2}{2!} + \cdots + \frac{x^n}{n!}$.

---

### 7.4 Solving Linear Homogeneous Recurrence Relations

Let $q$ be a nonzero number. Then $h_n = q_n$ is a solution of the linear homogeneous recurrence relation

$$
h_n - a_1 h_{n-1} - a_2 h_{n-2} - \cdots - a_k h_{n-k} = 0, (a_k \ne 0, n \ge k)
$$

with constant coefficients if and only if q is a root of the polynomial equation

$$
x^k - a_1 x^{k-1} - a_2 x^{k-2} - \cdots - a_k = 0.
$$

---

Let $q_1, q_2, \ldots ,q_t$ be the distinct roots of the following characteristic equation of the linear homogeneous recurrence relation with constant coefficients:

$$
h_n - a_1 h_{n-1} - a_2 h_{n-2} - \cdots - a_k h_{n-k} = 0, (a_k \ne 0, n \ge k).
$$

If $q_i$ is an $s_i$-fold root of the characteristic equation of, the part of the general solution of this recurrence relation corresponding to $q_i$ is

$$
H^{(i)}_n = (c_1 + c_2 n + \ldots + c_{s_i} n^{s_i-1}) q_i^n
$$

The general solution of the recurrence relation is

$$
h_n = H^{(1)}_n + H^{(2)}_n + \cdots + H^{(t)}_n.
$$

---

Let $h_0, h_1, \ldots, h_n, \ldots$ be a sequence of numbers that satisfies the linear homogeneous recurrence relation

$$
h_n + c_1 h_{n-1} + c_2 h_{n-2} + \cdots + c_k h_{n-k} = 0, (c_k \ne 0, n \ge k).
$$

of order $k$ with constant coefficients. Then its generating function $g(x)$ is of the form

$$
g(x) = \frac{p(x)}{q(x)},
$$

where $q(x)$ is a polynomial of degree $k$ with a nonzero constant term and $p(x)$ is a polynomial of degree less than $k$.

---

### 7.5 Nonhomogeneous Recurrence Relations

The technique used to solve nonhomogeneous differential equations can be summarized as follows:

1. Find the general solution of the homogeneous relation.
2. Find a particular solution of the nonhomogeneous relation.
3. Combine the general solution and the particular solution, and determine values of the constants arising in the general solution so that the combined solution satisfies the initial conditions.

---

## 8 Special Counting Sequences | 非线性递推关系

---

### 8.1 Catalan Numbers

The Catalan sequence is the sequence $C_0, C_1, \ldots, C_n, \ldots,$ where

$$
C_n = \frac{1}{n+1}\begin{pmatrix}2n\\n\end{pmatrix}, (n=0,1,2,\ldots).
$$

The number of sequences $a_1, a_2, \ldots, a_{2n}$ of $2n$ terms that can be formed by using exactly $n$  $+1$s and exactly $n$ $-1$s whose partial sums are always positive:

$$
a_1 + a_2 + \ldots + a_k \ge 0, (k = 1,2, \ldots, 2n)
$$

equals the $n$th Catalan number $C_n$.

---

* Example #1. There are $2n$ people in line to get into a theater. Admission is 50 cents. Of the $2n$ people, $n$ have a 50-cent piece and $n$ have a $1 dollar bill. The box office at the theater rather foolishly begins with an empty cash register. In how many ways can the people line up so that whenever a person with a $1 dollar bill buys a ticket, the box office has a 50-cent piece in order to make change?
* Example #2. A big city lawyer works $n$ blocks north and $n$ blocks east of her place of residence. Every day she walks $2n$ blocks to work. How many routes are possible if she never crosses (but may touch) the diagonal line from home to office?
* Example #3. Let $a_1, a_2, \ldots, a_n$ be $n$ numbers. By a multiplication scheme for these numbers we mean a scheme for carrying out the multiplication of $a_1, a_2, \ldots, a_n$. A multiplication scheme requires a total of $n - 1$ multiplications between two numbers, each of which is either one of $a_1, a_2, \ldots, a_n$ or a partial product of them. How many multiplication schemes for $n$ numbers?

---

Let $h_n$ denote the number of ways of dividing a convex polygonal region with $n + 1$ sides into triangular regions by inserting diagonals that do not intersect in the interior. Define $h_1 = 1$. Then $h_n$ satisfies the recurrence relation

$$
h_n = \sum_{k=1}^{n-1} h_k h_{n-k} = \frac{1}{n}\begin{pmatrix}2n-2\\n-1\end{pmatrix}, (n \ge 2).
$$

---

### 8.2 Difference Sequences and Stirling Numbers

Let the general term of a sequence be a polynomial of degree $p$ in $n$:

$$
h_n = a_p n^p + a_{p-1} n^{p-1} + \cdots + a_1 n + a_0, (n \ge 0).
$$

Then $\Delta^{p+1} h_n = 0$ for all $n \ge 0$.

The geneml term of the sequence whose difference table has its $0$th
diagonal equal to $c_0, c_1, c_2, \ldots, c_p, 0, 0, \ldots$, where $c_p \ne 0$ is a polynomial in $n$ of degree $p$ satisfying

$$
h_n = c_0 \begin{pmatrix}n\\0\end{pmatrix} + c_1 \begin{pmatrix}n\\1\end{pmatrix} + \cdots + c_p \begin{pmatrix}n\\p\end{pmatrix}.
$$

---

Assume that the sequence $h_0, h_1, h_2, \cdots, h_n , \ldots$ has a difference table whose $0$th diagonal equals $c_0, c_1, c_2, \ldots, c_p, 0, 0, \ldots$. Then

$$
\sum_{k=0}^n h_k = c_0 \begin{pmatrix}n+1\\1\end{pmatrix} + c_1 \begin{pmatrix}n+1\\2\end{pmatrix} + \cdots + c_p \begin{pmatrix}n+1\\p+1\end{pmatrix}.
$$

If $1 \le k \le p - 1$, then

$$
S(p,k) = kS(p-l,k) + S(p -1,k -1),
$$

where $S(p, k) = \frac{c(p, k)}{k!}, (0 \le k \le p)$ are called the Stirling numbers of the second kind. The Stirling number of the second kind $S(p, k)$ counts the number of partitions of a set of $p$ elements into $k$ indistinguishable boxes in which no box is empty.

---

For each integer $k$ with $0 \le k \le p$, we have

$$
S(p,k)= \frac{1}{k!} \sum_{t=0}^k (-1)^t \begin{pmatrix}k\\t\end{pmatrix} (k-t)^p.
$$

The Bell number $B_p$ is the number of partitions of a set of $p$ elements into nonempty, indistinguishable boxes, we have

$$
B_p = S(p, 0) + S(p, 1) + \cdots + S(p,p).
$$

If $p \ge 1$, then

$$
B_p = \begin{pmatrix}p - 1\\0\end{pmatrix} B_0 + \begin{pmatrix}p - 1\\1\end{pmatrix} B_1 + \cdots + \begin{pmatrix}p - 1\\p-1\end{pmatrix} B_{p-1}.
$$

---

If $1 \le k \le p - 1$, then

$$
s(p, k) = (p - 1)s(p - 1, k) + s(p - 1, k - 1),
$$

where $s(p, k)$ are called the Stirling numbers of the first kind, $[n]_p = n(n - 1)(n - 2) \cdots (n - p + 1) = \sum_{k=0}^{p} (-1)^{p-k} s(p, k) n^k$. The Stirling number $s(p, k)$ of the first kind counts the number of arrangements of $p$ objects into $k$ nonempty circular permutations.

---

### 8.3 Partition Numbers

Let $n$ and $r$ be positive integers with $r \le n$. Let $p_n(r)$ be the number of partitions of $n$ in which the largest part is $r$, and let $q_n(r)$ be the number of partitions of $n - r$ in which no part is greater than $r$. Then

$$
p_n(r) = q_n(r).
$$

Let $n$ be a positive integer. Let $p_n^s$ equal the number of self-conjugate partitions of $n$, and let $p_n^t$ be the number of partitions of $n$ into distinct odd parts. Then

$$
p_n^s = p_n^t.
$$

Let $p_n^o$ be the number of partitions of $n$ into odd parts, and let $p_n^d$ be the number of partitions of $n$ into distinct parts. Then

$$
p_n^o = p_n^d.
$$

---

$$
\sum_{n=0}^\infty p_nx^n = \prod_{k=0}^\infty (1-x^k)^{-1}.
$$

Lexicographic order is a linear extension of the partial order of majorization on the set $P_n$ of partitions of a positive integer $n$.

Let $n$ be a positive integer. Let $p'_n$ be the number of partitions of $n$ into an even number of distinct parts, and let $p_n''$ be the number of partitions of $n$ into an odd number of distinct parts. Then

$$
p_n' = p_n'' + e_n,
$$

where $e_n$ is an error term given by $e_n = (-1)^j$ if $n$ is of the form $j(3j \pm 1) /2$, and $0$ otherwise.

---

### 8.4 A Geometric Problem

$h_n^{(k)}$ counts the number of regions into which $k$-dimensional space is divided by $n$ $(k - 1)$-dimensional hyperplanes in general position, where $h_n^{(k)} = \sum_{k=0}^n\begin{pmatrix}n\\k\end{pmatrix}$ which is the sum of the first $k + 1$ numbers in row $n$ of Pascal's triangle.

---

### 8.5 Lattice Paths and Schr$\"o$der Numbers

The number of rectangular lattice paths from $(r, s)$ to $(p, q)$ equals the binomial coefficient

$$
\begin{pmatrix}p - r + q - s\\p - r\end{pmatrix} = \begin{pmatrix}p - r + q - s\\q - s\end{pmatrix}.
$$

Let $n$ be a nonnegative integer. Then the number of subdiagonal rectangular lattice paths from $(0,0)$ to $(n, n)$ equals the $n$th Catalan number $C_n = \frac{1}{n+1}\begin{pmatrix}2n\\n\end{pmatrix}$.

Let $p$ and $q$ be positive integers with $p \le q$. Then the number of subdiagonal rectangular lattice paths from $(0,0)$ to $(p, q)$ equals

$$
\frac{p-q+1}{p+1}\begin{pmatrix}p+q\\q\end{pmatrix}.
$$

---

Let $r \le \min\{p, q\}$. Then

$$
K(p,q: rD) = \begin{pmatrix}&p+q-r&\\p-r&q-r&r\end{pmatrix}
$$

and

$$
K(p,q) = \sum_{r=0}^{\min\{p,q\}} K(p,q: rD),
$$

where $K(p, q : rD)$ is the number of $HVD$-lattice paths from $(0,0)$ to $(p, q)$ that use exactly $r$ diagonal steps $D=(1, 1)$.

---

Let $p$ and $q$ be positive integers with $p \ge q$, and let $r$ be a nonnegative
integer with $r \le q$. Then

$$
R(p,q: rD) = \frac{p-q+1}{p - r + 1} \begin{pmatrix}&p+q-r&\\p-r&q-r&r\end{pmatrix},
$$

and

$$
R(p,q) = \sum_{r=0}^{\min\{p,q\}} R(p,q: rD),
$$

where $R(p, q)$ equal the number of subdiagonal $HVD$-lattice paths from $(0,0)$ to $(p, q)$.

---

## 9 Systems of Distinct Representatives

---

### 9.1 General Problem Formulation

Let $Y$ be a finite set, and let $A = (A_1, A_2, \ldots, A_n)$ be a family (a sequence) of $n$ subsets of $Y$.

* A family $(e_1, e_2, \ldots, e_n)$ of elements of $Y$ is caned a system of representatives of $A$.
* If the elements are all different, then $(e_1, e_2, \ldots, e_n)$ is called a system of distinct representatives.

---

### 9.2 Existence of SDRs

* The Marriage Condition. In order for the family $A = (A_1, A_2, \ldots, A_n) of sets to have an SDR, it is necessary that for each $k = 1, 2, \ldots, n$ and each choice of k distinct indices $i_1, i_2, \ldots, i_k$ from $\{1, 2, \ldots, n\}$, $|A_{i_1} \cup A_{i_2} \cup \cdots \cup A_{i_k} | \ge k$.
* The family $A = (A_1, A_2, \ldots , A_n)$ of subsets of a set $Y$ has an SDR if and only if the marriage condition MC holds.
* Let $A = (A_1, A_2, \ldots, A_n)$ be a family of subsets of a finite set $Y$. Let $t$ be an integer with $0 \le t \le n$. Then there exists a subfamily of $t$ sets of $A$ that has an SDR if and only if $|A_{i_1} \cup A_{i_2} \cup \cdots \cup A_{i_k} | \ge k- (n - t)$ for all $k$ with $k \ge n-t$ and all choices of $k$ distinct indices $i_1, i_2, \ldots ,i_k$ from $\{1,  2, \ldots, n\}$.

---

### 9.2 Stable Marriages

* Deferred Acceptance Algorithm. For each preferential ranking matrix, there exists a stable complete marriage.
* The stable complete marriage obtained from the deferred acceptance algorithm, with the women choosing the men, is women-optimal. If the men choose the women in the deferred acceptance algorithm, the resulting complete marriage is men-optimal.

---

## 10 Combinatorial Designs

A combinatorial design is an arrangement of the objects of a set into subsets satisfying certain prescribed properties.

---

### 10.1 Modular Arithmetic

$$
Z_n= \{0, 1, \ldots, n-1\}.
$$

For any two integers $a$ and $b$ in $Z_n$,

* $a \bigoplus b$ is the remainder when the ordinary sum $a + b$ is divided by $n$. * An additive inverse of an integer $a$ in $Z_n$ is an integer $b$ in $Z_n$ such that $a \bigoplus b = 0$.
* $a \bigotimes b$ is the remainder when the ordinary product $a \times b$ is divided by $n$. A multiplicative inverse of an integer $a$ in $Z_n$ is an integer $b$ in $Z_n$ such that $a \bigotimes b = 1$.

---

Let $n$ be an integer with $n \ge 2$ and let $a$ be a nonzero integer in $Z_n$. Then $a$ has a multiplicative inverse in $Z_n$ if and only if the $GCD$ of $a$ and $n$ is $1$. If $a$ has a multiplicative inverse, then it is unique.

---

The complex numbers are obtained from the real numbers by "adjoining" a root. This method can be used to construct fields with $p^k$ elements for every prime $p$ and integer $k \ge 2$, starting from the field $Z_p$.

---

### 10.2 Block Designs

Let $X$ be any set of $v$ elements, called varieties, and let $B$ be a collection $B_1, B_2, \ldots, B_b$ of $k$-element subsets of $X$ called blocks. Then $B$ is a balanced block design on $X$, provided that each pair of elements of $X$ occurs together in exactly $\lambda$ blocks. If $k < v$, then $B$ is a balanced incomplete block design, or BIBD for short.

* In a BIBD, each variety is contained in $r=\frac{\lambda(v - 1)}{k-1}$ blocks.
* In a BIBD, $b \ge v$.

A BIBD example of index $\lambda = 1$ with $v = 7, b = 7, k = 3$:

$$
B_1 = \{0, 1, 3\}, B_2 = \{1, 2, 4\}, B_3 = \{2, 3, 5\},\\
B_4 = \{3, 4, 6\}, B_5 = \{0, 4, 5\}, B_6 = \{1, 5, 6\},\\
B_7 = \{0, 2, 6\}.
$$

---

Let $B$ be a subset of $k < v$ elements of $Z_v$ that forms a difference set mod $v$. Then the blocks developed from $B$ as a starter block form an SBIBD with index $\lambda = \frac{k(k - 1)}{v - 1}$.

* A BIBD for witch the number $b$ of blocks equals the number $v$ of varieties, is called symmetric, and this is shorten to SBIBD.

---

### 10.3 Steiner Triple Systems

BIBDs with block size $k = 2$ are trivial.
BIBDs with block size $k = 3$ are called Steiner triple systems.

* There is only one instance of a Steiner triple system that forms an SBIBD.

An example of a Steiner triple system of index $\lambda = 1$ with $v = 9$ varieties and $b = 12$ blocks:

$$
\begin{array}{ccc}
B_1 = \{0,1,2\} & B_2 = \{3,4,5\} & B_3 = \{6,7,8\}\\
B_4 = \{0,3,6\} & B_5 = \{1,4,7\} & B_6 = \{2,5,8\}\\
B_7 = \{0,4,8\} & B_8 = \{2,3,7\} & B_9 = \{1,5,6\}\\
B_{10} = \{0,5,7\} & B_{11} = \{1,3,8\} & B_{12} = \{2,4,6\}
\end{array}.
$$

---

Let $B$ be a Steiner triple system with pammeters $b, v, k = 3, r, \lambda$. Then $r = \frac{\lambda(v - 1)}{2}$ and $b = \frac{\lambda v(v - 1)}{6}$.

---

If there are Steiner triple systems of index $\lambda = 1$ with $v$ and $u$ varieties, respectively, then there is a Steiner triple system of index $\lambda = 1$ with $vu$ varieties.

* Kirkman's schoolgirl problem. A schoolmistress takes her class of $15$ girls on a daily walk. The girls are arranged in five rows, with three girls in each row, so that each
girl has two companions. Is it possible to plan a walk for seven consecutive days so that no girl will walk with any of her classmates in a triplet more than once?

---

### 10.4 Latin Squares

Let $n$ be a positive integer and let $S$ be a set of $n$ distinct elements. A Latin square of order $n$, based on the set $S$, is an n-by-n array, each of whose entries is an element of $S$ such that each of the $n$ elements of $S$ occurs once (and hence exactly once) in each row and once in each column.

* A Latin square of order $n$ corresponds to a partition of the positions of an $n$-by-$n$ array into $n$ sets $A(0), A(1), ... , A(n - 1)$, each consisting of $n$ positions for nonattacking rooks.

An example of Latin squares:

$$
A =
\begin{bmatrix}
0 & 1 & 2 & 3\\
1 & 2 & 3 & 0\\
2 & 3 & 0 & 1\\
3 & 0 & 1 & 2\\
\end{bmatrix}.
$$

---

Let $n$ be a positive integer and let $r$ be a nonzero integer in $Z_n$ such that the GCD of $r$ and $n$ is $1$. Let $A$ be the $n$-by-$n$ array whose entry $a_{ij}$ in row $i$ and column $j$ is $a_{ij} = r \times i + j$ (arithmetic mod $n$), $(i,j = 0, 1, ... ,n - 1)$. Then $A$ is a Latin square of order $n$ based on $Z_n$.

* The Latin square of order $n$ constructed  using an integer $r$ with a multiplicative inverse in $Z_n$, will be denoted by $L^r_n$.

---

We refer to mutually orthogonal Latin squares as MOLS. Let $N(n)$ denote the largest number of MOLS of order $n$, we have $N(n) = n - 1$ if $n$ is a prime power.

Let $n \ge 2$ be an integer and let $n = p_1^{e_1} \times p_2^{e_2} \times \cdots p_k^{e_k}$ be the factorization of $n$ into distinct prime numbers $p_1, p_2, \ldots, p_k$. Then $N(n) \ge \min \{p_i^{e_i} - 1: i = 1, 2, \ldots, k\}$.

Let $n \ge 2$ be an integer. If there exist $n - 1$ MOLS of order $n$, then there exists a resolvable BIBD with parameters $b = n^2 + n, v = n^2, k = n, r = n + 1, \lambda = 1$.

---

## 11 Graph Theory

Two general graphs $G = (V, E)$ and $G' = (V', E')$ are called isomorphic, provided that there is a one-to-one correspondence $\theta: V \rightarrow V'$ between their vertex sets such that, for each pair of vertices $x$ and $y$ of $V$, there are as many edges of $G$ joining $x$ and $y$ as there are edges of $G'$ joining $\theta(x)$ and $\theta(y)$.

---

### 11.1 Eulerian Trails

Let $G$ be a connected general graph. A trail in a general graph $G$ is called Eulerian, provided that it contains every edge of $G$.

* G has a closed Eulerian trail if and only if the degree of each vertex is even.
* G has an open Eulerian trail if and only if there are exactly two vertices $u$ and $v$ of odd degree. Every open Eulerian trail in $G$ joins $u$ and $v$.
* Suppose that the number of vertices of $G$ with odd degree is $m > O$. Then the edges of $G$ can be partitioned into $m/2$ open trails. It is impossible to partition the edges of $G$ into fewer than $m/2$ open trails.

---

### 11.2 Hamilton Paths & Cycles

A Hamilton cycle of a graph G of order $n$ is a cycle of $G$ of length $n$.

* A connected graph of order $n \ge 3$ with a bridge does not have a Hamilton cycle.
* Let $G$ be a graph of order $n \ge 3$ that satisfies the Ore property. Then $G$ has a Hamilton cycle.

---
A Hamilton path in $G$ is given by a permutation of the $n$
vertices of $G$ in which consecutive vertices are joined by an edge of $G$.

* A graph of order $n$, in which the sum of the degrees of each pair of nonadjacent vertices is at least $n - 1$, has a Hamilton path.

---

### 11.3 Bipartite Multigraphs

Let $G = (V, E)$ be a multigraph. Then $G$ is called  bipartite, provided that the vertex set $V$ may be partitioned into two subsets $X$ and $Y$ so that each edge of $G$ has one vertex in $X$ and one vertex in $Y$.

* A multigraph is bipartite if and only if each of its cycles has even length.
* If $|X| \neq |Y|$, then $G$ does not have a Hamilton cycle.
* If $|X| = |Y|$, then G does not have a Hamilton path that begins at a vertex in $X$ and ends at a vertex in $X$.
* If $|X| = |Y| + 1$, then $G$ does not have a Hamilton path that begins at $X$ and ends at $Y$.
* If $X$ and $Y$ differ by at least $2$, then $G$ does not have a Hamilton path.

---

### 11.4 Trees and More

A tree is defined to be a connected graph that becomes disconnected upon the removal of any edge.

* A connected graph of order $n \ge 2$ is a tree if and only if it has exactly $n - 1$ edges.
* Let $G$ be a connected graph of order $n$. Then $G$ is a tree if and only if $G$ does not have any cycles.

---

If we iteratively remove non bridge edges until every edge is a bridge of the remaining graph, we get a spanning subgraph that is a spanning tree of $G$.

* Every connected graph has a spanning tree.
* Let $T_1$ and $T_2$ be spanning trees of a connected graph $G$. Let $\beta$ be an edge of $T_1$. Then there is an edge $\alpha$ of $T_2$ such that the graph obtained from $T_1$ by inserting $\alpha$ and deleting $\beta$ is a spanning tree of $G$.

Algorithm to grow a spanning tree.

* A breadth-first spanning tree, a depth-first spanning tree.
* A distance tree (Dijkstra's algorithm), a minimum weight spanning tree(Kruskal's algorithm, Prim's algorithm).

---

### 11.5 The Shannon Switching Game

Shannon's game is played by two people, called here the positive player $P$ and the negative player $N$, who alternate turns.

* When it is $N$'s turn, $N$ destroys some edge of $G$ by putting a negative sign - on it.
* When it is $P$'s turn, $P$ puts a positive sign + on some edge of $G$, which now cannot be destroyed by $N$.

Play proceeds until one of the players achieves his or her goal:

* There is a path between $u$ and $v$ that has only + signs on its edges.
* Every path in $G$ between $u$ and $v$ contains a - sign on at least one of its edges.

---

The game determined by a multigraph $G = (V, E)$ with distinguished vertices $u$ and $v$ is a positive game if and only if there is a subset $U$ containing $u$ and $v$ of the vertex set $V$ such that the induced multisubgraph $G_U$ has two spanning trees, $T_1$ and $T_2$, with no common edges.

---

### 11.6 Chromatic Number

A vertex-coloring of $G$ is an assignment of a color to each of the vertices of $G$ in such a way that adjacent vertices are assigned different colors. The smallest $k$, such that $G$ is $k$-colorable, is called the chromatic number of $G$, denoted by $\chi(G)$.

* Let $G$ be a graph of order $n \ge 1$. Then $1 \le \chi(G) \le n$.
* Let $G$ be a graph with at least one edge. Then $\chi(G) = 2$ if and only if $G$ is bipartite.
* Let $G$ be a connected graph for which the maximum degree of a vertex is $\Delta$. If $G$ is neither a complete graph $K_n$ nor an odd cycle graph $C_n$ then $\chi(G) \le \Delta$.

---

For each nonnegative integer $k$, the number of $k$-colorings of the vertices of a graph $G$ is denoted by $p_G(k)$. Repeated use of deletion and contraction gives an algorithm for determining $p_G(k)$.

* Let $G$ be a graph of order $n \ge 1$. Then the number of $k$-colorings of $G$ is a polynomial in $k$ of degree equal to $n$ and this polynomial is computed correctly by the preceding algorithm.
* Let $U$ be an articulation set of $G$ and suppose that the induced subgraph $G_u$ is a complete graph $K_r$. Let the connected components of $G_{V-U}$ be the induced subgraphs $G_{u_1}, \ldots , G_{u_t}$. For $i = 1, \ldots , t$, let $H_i = G_{U \cup U_i}$ be the subgraph of $G$ induced by $U \cup U_i$. Then $p_G(k) = \frac{p_{H_1}(k) \times \cdots \times p_{H_t}(k)}{([k]_r)^{t-1}}$.

---

### 11.7 Plane & Planar Graphs

---

pp. 473.

---

### 11.8 A Five-Color Theorem

---

### 11.9 Independence Number & Clique Number

---

### 11.10 Matching Number

---

### 11.11 Connectivity

---

## 12 Digraphs and Networks

---

### 12.1 Digraphs

---

### 12.2 Networks

---

### 12.3 Matchings in Bipartite Graphs Revisited

---

## 13 P$\'o$lya Counting

---

### 13.1 Permutation & Symmetry Groups

---

### 13.2 Burnside's Theorem

---

### 13.3 Polya's Counting Formula

---

## 14 References

Books

* [Introductory Combinatorics, 5th Edition](https://www.pearson.com/us/higher-education/product/Brualdi-Introductory-Combinatorics-5th-Edition/9780136020400.html). [Richard A. Brualdi](https://people.math.wisc.edu/~brualdi/), University of Wisconsin. 2010. Pearson.
* [组合数学（第5版）](http://www.tup.tsinghua.edu.cn/booksCenter/book_07098001.html). [卢开澄](http://www.tup.tsinghua.edu.cn/bookscenter/bookwritersay.html?id=07098001), 卢华明, 清华大学. 2016. 清华大学出版社.

Websites

* Combinatorics: <https://cp-algorithms.com/#combinatorics>
* 排列组合: <https://oi-wiki.org/math/combinatorics/combination/>
