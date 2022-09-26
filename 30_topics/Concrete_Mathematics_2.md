---
marp: true
math: katex
---

# Concrete Mathematics

---

## 6 Special Numbers

---

### 6.1 Stirling Numbers

---

Stirling numbers of the first kind: $\big[\begin{smallmatrix}n\\k\end{smallmatrix}\big]$ counts the number of ways to arrange $n$ objects into $k$ cycles, which can be read "$n$ cycle $k$". What is the interpretation of the following recurrence?

$$
\begin{bmatrix}n\\k\end{bmatrix} = (n-1)\begin{bmatrix}n-1\\k\end{bmatrix} + \begin{bmatrix}n-1\\k-1\end{bmatrix}.
$$

$\begin{bmatrix}n\\k\end{bmatrix}$ is the number of permutations of $n$ objects that contain exactly $k$ cycles.

$$
\sum_k \begin{bmatrix}n\\k\end{bmatrix} = n!.
$$

Stirling cycle numbers are the coefficients of ordinary powers that yield factorial powers.

$$
x^{\overline{n}} = \sum_k \begin{bmatrix}n\\k\end{bmatrix} x^{k}.
$$

---

Stirling numbers of the second kind: $\big\{\begin{smallmatrix}n\\k\end{smallmatrix}\big\}$ stands for the number of ways to partition a set of $n$ things into $k$ nonempty subsets, which can be read "$n$ subset $k$". What is the interpretation of the following recurrence?

$$
\begin{Bmatrix}n\\k\end{Bmatrix} = k\begin{Bmatrix}n-1\\k\end{Bmatrix} + \begin{Bmatrix}n-1\\k-1\end{Bmatrix}.
$$

Stirling subset numbers are the coefficients of factorial powers that yield ordinary powers, why?

$$
x^n = \sum_k \begin{Bmatrix}n\\k\end{Bmatrix} x^{\underline{k}}.
$$

---

Inversion formulas:

$$
\sum_{k} \begin{bmatrix}n\\k\end{bmatrix} \begin{Bmatrix}k\\m\end{Bmatrix}(-1)^{n-k} = \sum_{k} \begin{Bmatrix}n\\k\end{Bmatrix}\begin{bmatrix}k\\m\end{bmatrix}(-1)^{n-k} = [m=n].
$$

The two kinds of Stirling numbers are related by an extremely simple law

$$
\begin{bmatrix}n\\k\end{bmatrix} = \begin{Bmatrix}-k\\-n\end{Bmatrix}.
$$

---

### 6.2 Eulerian Numbers

---

Eulerian numbers: $\left< \begin{matrix}n\\k\end{matrix} \right>$ is the number of permutations $\pi_1\pi_2 \cdots \pi_n$ of $\{1, 2, \ldots, n\}$ that have $k$ ascents, namely, $k$ places where $\pi_j < \pi_{j+1}$.

The symmetry law:

$$
\left< \begin{matrix}n\\k\end{matrix} \right> = \left< \begin{matrix}n\\n-1-k\end{matrix} \right>.
$$

The recurrence:

$$
\left< \begin{matrix}n\\k\end{matrix} \right> = (k+1)\left< \begin{matrix}n-1\\k\end{matrix} \right> + (n-k)\left< \begin{matrix}n-1\\k-1\end{matrix} \right>.
$$

---

Worpitzky's identity: an unusual connection between ordinary powers and consecutive binomial coefficients

$$
x^n = \sum_k \left< \begin{matrix}n\\k\end{matrix} \right> \begin{pmatrix}x+k\\n\end{pmatrix}.
$$

---

### 6.3 Harmonic Numbers

---

Given $n$ cards and a table, what is the largest possible overhang by stacking the cards up over the table's edge, subject to the laws of gravity? A similar problem is called the "worm on the rubber band".

$$
H_n = \sum_{k=1}^n \frac{1}{k}.
$$

Riemann's zeta function:

$$
\zeta(r) = H_\infty^{(r)} = \sum_{k \ge 1}\frac{1}{k^r}.
$$

Euler's constant:

$$
\gamma = \lim_{n \rightarrow \infty} (H_n - \ln n).
$$

---

### 6.4 Harmonic Summation

---

A more general sum:

$$
\sum_{0 \le k < m}\begin{pmatrix}k\\m\end{pmatrix} H_k = \begin{pmatrix}n\\m+1\end{pmatrix}(H_n - \frac{1}{n+1}).
$$

A much more general sum:

$$
U_n(x, y) = \sum_{k \ge 1} \begin{pmatrix}n\\k\end{pmatrix} \frac{(-1)^{k-1}}{k}(x+ky)^n = x^n H_n + nx^{n-1}y.
$$

---

### 6.5 Bernoulli Numbers

---

The formulas for sums of $m$th powers:

$$
S_m(n) = \sum_{k=0}^{n-1} k^m = H_{n-1}^{(-m)} = \frac{1}{m+1}\sum_{k=0}^m \begin{pmatrix}m+1\\k\end{pmatrix} B_k n^{m+1-k}.
$$

Bernoulli numbers are defined by an implicit recurrence relation

$$
\sum_{j=0}^m \begin{pmatrix}m+1\\j\end{pmatrix} B_j = [m=0].
$$

Bernoulli numbers are the coefficients of the power series

$$
\frac{z}{e^z - 1} = \sum_{n \ge 0} B_n \frac{z^n}{n!}.
$$

---

Two remarkable formulas for $z \cot z$ are

$$
z \cot z = 1 - 2 \sum_{k \ge 1}\frac{z^2}{k^2 \pi^2 - z^2} = 1 - 2 \sum_{j \ge 1} \frac{z^{2j}}{\pi^{2j}} H_\infty^{(2j)},
$$

$$
z \cot z = iz \coth iz = \frac{2iz}{e^{2iz}-1} + \frac{2iz}{2} = \sum_{n \ge 0}(-4)^n B_{2n} \frac{z^{2n}}{(2n)!},
$$

which gives us an almost miraculous closed form for infinitely many infinite sums:

$$
\zeta (2n) = H_\infty^{(2n)} = (-1)^{n-1}\frac{2^{2n-1}\pi^{2n}B_{2n}}{(2n)!}.
$$

---
Bernoulli numbers also appear in the coeficients of the tangent function:

$$
\tan z = \sum_{n \ge 0} T_{2n-1} \frac{z^{2n-1}}{(2n-1)!} = \sum_{n \ge 0} (-1)^{n-1} \frac{4^n(4^n-1)}{2n} B_{2n} \frac{z^{2n-1}}{(2n-1)!}.
$$

Bernoulli numbers are related to the constant terms in the Stirling polynomials:

$$
\frac{B_{m}}{m!} = -m \sigma_m(0).
$$

---

### 6.6 Fibonacci Numbers

Leonardo Fibonacci, 1202.

---

Fibonacci numbers are often found in nature: the bee-tree law, the florets of sunflower, reflections.

Jean-Dominique Cassini's identity is the basis of a geometrical paradox that was one of Lewis Carroll's favorite puzzles:

$$
F_{n+1}F_{n-1} - F_n^2 = (-1)^n.
$$

The divisibility property.

$$
\gcd(F_m, F_n) = F_{\gcd(m, n)}.
$$

One of the most important property is Zeckendorf's theorem, every positive integer has a unique representation of the form

$$
n = F_{k_1} + F_{k_2} + \cdots + F_{k_r}, \quad k_{i+1} \ge k_i + 2,
$$

which leads to the Fibonacci number system.

---

The generating function of the Fibonacci numbers

$$
F(z) = \sum_{n \ge 0} F_n z^n = \frac{z}{1-z-z^2}.
$$

---

P. 310

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