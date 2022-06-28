---
marp: true
math: katex
---

# Concrete Mathematics

---

## 1 Recurrent Problems

There are recurrences that don't have simple closed forms. When such recurrences turn out to be important, because they **arise repeatedly**, we add new operations to our repertoire; this can **greatly extend the range** of problems solvable in "simple" closed form.

---

### 1.1 The Tower of Hanoi

We are given a tower of eight disks, initially stacked in decreasing size on one of three pegs. The objective is to transfer the entire tower to one of the other pegs, moving only one disk at a time and never moving a larger one onto a smaller. Let $T_n$ be the minimum number of moves that will transfer $n$ disks from one peg to another under Lucas's rules. Then

$$
\begin{array}{rcl}
T_0 & = & 0;\\
T_n & = & 2T_{n−1} + 1 , \; \text{for} \; n > 0.
\end{array}
$$

One way is to guess the correct solution by looking at small cases, then to prove that our guess is correct using mathematical induction. The anwser is

$$
T_n = 2^n − 1, \; \text{for} \; n \ge 0.
$$

---

Q1.1 - Assuming that there are n different sizes of disks and exactly $m_k$ disks of size $k$. Determine $A(m_1, \ldots , m_n)$, the minimum number of moves needed to transfer a tower when equal-size disks are considered to be indistinguishable.

Q1.2 - Find the minimum number of moves $F(k, n)$ that will transfer $n$ disks from one peg to another if there are $k$ pegs.

---

### 1.2 Lines in the Plane

How many slices of pizza can a person obtain by making $n$ straight cuts with a pizza knife? After some thought we realize that the $n$th line increases the number of regions by $k$ if and only if it splits $k$ of the old regions. The recurrence is therefore

$$
\begin{array}{rcl}
T_0 & = & 0;\\
T_n & = & T_{n−1} + n, \; \text{for} \; n > 0.
\end{array}
$$

We can use a trick that Gauss reportedly when he was nine years old, which is merely adding the numbers to its reversal. The solution is

$$
T_n = \frac{n(n+1)}{2} + 1, \; \text{for} \; n \ge 0.
$$

---

Q2.1 - What's the maximum number of regions definable by n zig-zag lines, each of which consists of two parallel infinite half-lines joined by a straight segment?

Q2.2 - Find a recurrence relation for $P(n, d)$, the maximum number of $d$-dimensional subspaces that can be defined by $n$ different hyperplanes.

---

### 1.3 The Josephus Problem

We start with n people numbered $1$ to $n$ around a circle, and we eliminate every second remaining person until only one survives. The problem: Determine the survivor's number, $J(n)$. Because J(n) always seems to be odd, we condider the even case and the odd case respectively. The recurrence is

$$
\begin{array}{rcl}
J(1) & = & 1;\\
J(2n) & = & 2J(n) - 1, \; \text{for} \; n \ge 1;\\
J(2n + 1) & = & 2J(n) + 1, \; \text{for} \; n \ge 1.
\end{array}
$$

The solution to the recurrence is

$$
J(2^m + l) = 2l + 1, \; \text{for} \; m \ge 0 \; \text{and} \; 0 \le l < 2^m.
$$

Suppose $n$'s binary expansion is $n = (b_m b_{m−1} \ldots b_1 b_0)_2$, we have

$$
J\left((b_m b_{m−1} \ldots b_1 b_0)_2\right) = (b_{m−1} \ldots b_1 b_0 b_m)_2.
$$

---

If we let $\beta_0 = \beta$ and $\beta_1 = \gamma$, we can rewrite the generalized recurrence

$$
\begin{array}{rcl}
f(1) & = & \alpha;\\
f(2n + j) & = & 2f(n) + \beta_j, \; \text{for} \; j = 0, 1 \; \text{and} \; n \ge 1.
\end{array}
$$

Let $f(n) = A(n)\alpha + B(n)\beta + C(n)\gamma$ and $n = 2^m + l$, where $m \ge 0$ and $0 \le l < 2^m$. Using the **repertoire method**, plugging $f(n) = 1$, $f(n) = n$, $f(n) = n^2$ into $f(0), f(1), f(2)$, we have

$$
\begin{array}{rcl}
A(n) & = & 2^m;\\
B(n) & = & 2^m - 1 - l;\\
C(n) & = & l.
\end{array}
$$

Suppose we now relax the radix $2$ notation to allow arbitrary digits instead of just $0$ and $1$, we have
$$
f\left((b_m b_{m−1} \ldots b_1 b_0)_2\right) = (\alpha \beta_{b_{m−1}} \beta_{b_{m−2}} \ldots \beta_{b_{1}} \beta_{b_{0}})_2.
$$

---

Consider a even more generalized recurrence

$$
\begin{array}{rcll}
f(j) & = & \alpha_j & \text{for} \; 1 \le j < d;\\
f(dn + j) & = & cf(n) + \beta_j,& \text{for} \; 0 \le j < d \; \text{and} \; n \ge 1.
\end{array}
$$

If we start with numbers in radix $d$ and produce values in radix $c$, we have

$$
f\left((b_m b_{m−1} \ldots b_1 b_0)_d\right) = (\alpha_{b_m} \beta_{b_{m−1}} \beta_{b_{m−2}} \ldots \beta_{b_{1}} \beta_{b_{0}})_c.
$$

---

Q3.1 - Suppose there are $2n$ people in a circle; the first $n$ are "good guys" and the last $n$ are "bad guys". Show that there is always an integer $m$ (depending on $n$) such that, if we go around the circle executing every $m$th person, all the bad guys are first to go.

Q3.2 - Suppose that Josephus finds himself in a given position $j$, but he has a chance to name the elimination parameter $q$ such that every $q$th person is executed. Can he always save himself?

Q3.3 - Let's say that a Josephus subset of $\{1, 2, . . . , n\}$ is a set of $k$ numbers such that, for some $q$, the people with the other $n−k$ numbers will be eliminated first. Are non-Josephus subsets rare for large $n$?

---

## 2 Sums

---

### 2.1 Sums and Recurrences

Consider a recurrence of the form

$$
a_nT_n = b_nT_{n−1} + c_n.
$$

Let $s_nb_n = s_{n−1}a_{n−1}$ and $S_n = s_n a_n T_n$. We have a sum-recurrence $S_n = S_{n−1} + s_nc_n = s_1b_1T_0 +
 \sum_{k=1}^n s_k c_k$. Hence the solution is

$$
T_n = \frac{1}{s_n a_n} \left(s_1b_1T_0 + \sum_{k=1}^n s_k c_k \right).
$$

This idea can be used to find the solution of a recurrence that arises in the study of "quick-sort," one of the most important methods for sorting data inside a computer.

---

### 2.2 Manipulation of Sums

There are three simple rules: distributive law, associative law, commutative law. These rules can be used to compute the general sum of an arithmetic progression, $\sum_{k=0}^{n}(a + bk) = (a + \frac{1}{2}b_n)(n + 1)$.

The operation of splitting off a term is the basis of a perturbation method that allow us to find the sum of a general geomeric progression, $\sum_{0\le k\le n} ax^k=a\frac{1-x^{n+1}}{1-x}$ and $\sum_{0\le k\le n} kx^k=x\frac{1 - x^{n+1}-(n+1)x^{n}(1-x)}{(1-x)^2}$, for $x \ne 1$ (more connections between calculus and discrete mathematics).

---

### 2.3 Multiple Sums

For two or more indices, there are a general associative law and a general distributive law. We have an interesting formula:

$$
\left(\sum_{k=1}^n a_k\right) \left(\sum_{k=1}^n b_k\right) = n \sum_{k=1}^n a_k b_k - \sum_{1\le j<k\le n}^n (a_k - a_j)(b_k - b_j),$$

which yields Chebyshev's monotonic inequalities as a special case.

Here is an example of multiple sums $S_n = \sum_{1 \le j < k \le n} \frac{1}{k-j}$. We can evaluate this sum in two ways, one algebraic and one geometric, which gives us a further identity

$$
S_n = \sum_{0 \le k < n} H_k = n H_n - n.
$$

---

### 2.4 General Methods

There are at least eight methods to solve the the sum of the first $n$ squares

$$
S^{(2)}_n = \sum_{0 \le k \le n} k^2, \; \text{for} \; n \ge 0.
$$

**Method 0**: Look it up.

Handbook of Integer Sequences, Sloane, 1973. Sequence number 1574, and it's called the sequence of "square pyramidal numbers".

**Method 1**: Guess the answer, prove it by induction.

Suppose the equivalent formula is $S^{(2)}_n = \frac{n(n + \frac{1}{2})(n+1)}{3}$. We can prove our conjectures using  Mathematical induction.

---

**Method 2**: Perturb the sum.

Using the perturbation method on $S^{(2)}_n$ reveals a way to sum the first $n$ integers in closed form, $2 \sum_{0 \le k \le n} k = (n+1)^2 - (n+1)$. We can probably get an expression for the integers squared if we start to perturb $S^{(3)}_n = \sum_{0 \le k \le n} k^3$, for $n \ge 0$.

**Method 3**: Build a repertoire.

The solution to $R_0 = \alpha$; $R_n = R_{n−1} + \beta + \gamma n + \delta n^2$, for $n > 0$ will be of the general form $R_n = A(n)\alpha + B(n)\beta + C(n)\gamma + D(n)\delta$. Plugging $f(n) = 1$, $f(n) = n$, $f(n) = n^2$, $f(n) = n^3$ into $f(0), f(1), f(2), f(3)$, we will get the answer.

---

**Method 4**: Replace sums by integrals.

The area under the curve $f(x)=x^2$ is $\int_0^n x^2 dx = \frac{1}{3}n^3$; therefore we know that $S^{(2)}_n$ is approximately $\frac{1}{3}n^3$. 1) One way to use this fact is to examine the error in the approximation $E_n = S^{(2)}_n - \frac{1}{3}n^3$. We find that $E_n = E_{n-1} + n - \frac{1}{3}$. 2) Another way to pursue the integral approach is to find a formula for $E_n$ by summing the areas of the wedge-shaped error terms. Then we get the answer.

**Method 5**: Expand and contract.

---

### 2.5 Finite and Infinite Calculus

---

### 2.6 Infinite Sums

---

## 3 Integer Functions

### 3.1 Floors and Ceilings

---

### 3.2 Floor/Ceiling Applications

---

### 3.3 Floor/Ceiling Recurrences

---

### 3.4 `mod': The Binary Operation

---

### 3.5 Floor/Ceiling Sums

---

## 4 Number Theory

---

### 4.1 Divisibility

---

### 4.2 Primes

---

### 4.3 Prime Examples

---

### 4.4 Factorial Factors

---

### 4.5 Relative Primality

---

### 4.6 `mod': The Congruence Relation

---

### 4.7 Independent Residues

---

### 4.8 Additional Applications

---

### 4.9 Phi and Mu

---

## 5 Binomial Coefficients

---

### 5.1 Basic Identities

---

### 5.2 Basic Practice

---

### 5.3 Tricks of the Trade

---

### 5.4 Generating Functions

---

### 5.5 Hypergeometric Functions

---

### 5.6 Hypergeometric Transformations

---

### 5.7 Partial Hypergeometric Sums

---

### 5.8 Mechanical Summation

---

## 6 Special Numbers

---

### 6.1 Stirling Numbers

---

### 6.2 Eulerian Numbers

---

### 6.3 Harmonic Numbers

---

### 6.4 Harmonic Summation

---

### 6.5 Bernoulli Numbers

---

### 6.6 Fibonacci Numbers

---

### 6.7 Continuants

---

## 7 Generating Functions

---

### 7.1 Domino Theory and Change

---

### 7.2 Basic Maneuvers

---

### 7.3 Solving Recurrences

---

### 7.4 Special Generating Functions

---

### 7.5 Convolutions

---

### 7.6 Exponential Generating Functions

---

### 7.7 Dirichlet Generating Functions

---

## 8 Discrete Probability

---

### 8.1 Definitions

---

### 8.2 Mean and Variance

---

### 8.3 Probability Generating Functions

---

### 8.4 Flipping Coins

---

### 8.5 Hashing

---

## 9 Asymptotics

---

### 9.1 A Hierarchy

---

### 9.2 O Notation

---

### 9.3 O Manipulation

---

### 9.4 Two Asymptotic Tricks

---

### 9.5 Euler's Summation Formula

---

### 9.6 Final Summations

---
