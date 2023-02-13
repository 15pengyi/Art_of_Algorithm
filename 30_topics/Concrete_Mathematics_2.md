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
F(z) = \sum_{n \ge 0} F_n z^n = \frac{z}{1-z-z^2} = \frac{1}{\sqrt{5}}\left( \frac{1}{1-\phi z} - \frac{1}{1-\hat{\phi}z} \right),
$$

where $\phi=\frac{1+\sqrt{5}}{2}$ is the golden ratio, $\hat{\phi}=\frac{1-\sqrt{5}}{2}$.

The closed form for the coefficient of $z^n$ is

$$
F_n = \frac{1}{\sqrt{5}} \left( \phi^n - \hat{\phi}^n\right)=\lfloor \frac{\phi^n}{\sqrt{5}} + \frac{1}{2}\rfloor.
$$

---

### 6.7 Continuants

The continuant polynomial $K_n$ is defined by the following recurrence:

$$
\begin{array}{rcl}
K_0() & = & 1;\\
K_1(x_1) & = & x_1;\\
K_n(x_1,\ldots,x_n) & = & K_{n-1}(x_1,\ldots,x_{n-1})x_n+K_{n-2}(x_1,\ldots,x_{n-2}).
\end{array}
$$

---

A Morse code sequence of length $n$ that has $k$ dashes has $n-2k$ dots and $n - k$ symbols altogether:

$$
K_n(z,\ldots,z) = \sum_{k=0}^n \begin{pmatrix}n-k\\k\end{pmatrix} z^{n-2k}.
$$

We have the identity

$$
F_{n+1} = K_n(z,\ldots,z)|_{z=1} = \sum_{k=0}^n \begin{pmatrix}n-k\\k\end{pmatrix}.
$$

A remarkable law:

$$
K_{m+n}(x_1, \ldots, x_{m+n}) K_k(x_{m+1}, \ldots, x_{m+k})\\
= K_{m+k}(x_1, \ldots, x_{m+k}) K_n(x_{m+1}, \ldots, x_{m+n})\\
+ (-1)^k K_{m-1}(x_1, \ldots, x_{m-1})K_{n-k-1}(x_{m+k+2}, \ldots, x_{m+n}).
$$

---

If Euclid's algorithm finds the greatest common divisor $d$ in $k$ steps, after computing the sequence of quotients $q_1, \ldots q_k$, then the starting numbers were $K(q_1, q_2, \ldots, q_k)d$ and $K(q_2, \ldots, q_k)d$.

Continuants are closely connected with the Stern-Brocot tree:

$$
f(R^{a_1}\cdots L^{a_{n-1}}) = \frac{K_{n+1}(a_0, a_1, \ldots, a_{n-1}, 1)}{K_{n}(a_1, \ldots, a_{n-1}, 1)}.
$$

A remarkable identity:

$$
\frac{z^{F_1}}{1+\frac{z^{F_2}}{1+\frac{z^{F_3}}{\ddots}}} = (1-z)\sum_{n \ge 1} z^{\lfloor n \phi \rfloor}.
$$

---

## 7 Generating Functions

To manipulate infinite series that "generate" those sequences.

---

### 7.1 Domino Theory and Change

---

Q1 - How many ways $T_n$ are there to completely cover a $2 \times n$ rectangle with $2 \times 1$ dominoes?

$T$ are called generating functions, because they generate the coefficients of interest:

$$
T
= \frac{\begin{smallmatrix}┃\\┃\end{smallmatrix}}{\begin{smallmatrix}┃\\┃\end{smallmatrix}-\begin{smallmatrix}┏┓\\┃┃\\┗┛\end{smallmatrix}-\begin{smallmatrix}┏━┓\\┣━┫\\┗━┛\end{smallmatrix}}
= \frac{\begin{smallmatrix}┃\\┃\end{smallmatrix}}{\begin{smallmatrix}┃\\┃\end{smallmatrix}-\begin{smallmatrix}┏┓\\┃┃\\┗┛\end{smallmatrix}-\begin{smallmatrix}\hphantom{┏}\hphantom{┏}\hphantom{┏}\\┏━┓\\┗━┛\end{smallmatrix}^2}
= \frac{1}{1-z-z^2}.
$$

$$
T_n = \sum_{m} \begin{pmatrix}n-m\\m\end{pmatrix} = F_{n+1}.
$$

Thus domino tilings are closely related to the continuant polynomials.

---

Q2 - How many ways $T_n$ are there to completely cover a $3 \times n$ rectangle with $2 \times 1$ dominoes?

$$
U = \begin{smallmatrix}┃\\┃\\┃\end{smallmatrix} + \begin{smallmatrix}┏┓\hphantom{┏}\\┃┃\hphantom{┏}\\┣┻┓\\┗━┛\end{smallmatrix}V + \begin{smallmatrix}┏━┓\\┣┳┛\\┃┃\hphantom{┏}\\┗┛\hphantom{┏}\end{smallmatrix}\Lambda + \begin{smallmatrix}┏━┓\\┣━┫\\┣━┫\\┗━┛\end{smallmatrix}U,
$$

$$
V = \begin{smallmatrix}┏┓\\┃┃\\┗┛\\\hphantom{┏}\hphantom{┏}\end{smallmatrix}U + \begin{smallmatrix}┏━┓\hphantom{┏}\\┣━┫\hphantom{┏}\\┗┳┻┓\\\hphantom{┏}┗━┛\end{smallmatrix}V,
$$

$$
\Lambda = \begin{smallmatrix}\hphantom{┏}\hphantom{┏}\\┏┓\\┃┃\\┗┛\end{smallmatrix}U + \begin{smallmatrix}\hphantom{┏}┏━┓\\┏┻┳┛\\┣━┫\hphantom{┏}\\┗━┛\hphantom{┏}\end{smallmatrix}\Lambda.
$$

---

The final equation can be solved for $U$:

$$
\begin{array}{rcl}
U & = &\frac{\begin{smallmatrix}┃\\┃\\┃\end{smallmatrix}}{\begin{smallmatrix}┃\\┃\\┃\end{smallmatrix} - \begin{smallmatrix}┏┓\hphantom{┏}\\┃┃\hphantom{┏}\\┣┻┓\\┗━┛\end{smallmatrix}\left(\begin{smallmatrix}┃\\┃\\┃\end{smallmatrix} - \begin{smallmatrix}┏━┓\hphantom{┏}\\┣━┫\hphantom{┏}\\┗┳┻┓\\\hphantom{┏}┗━┛\end{smallmatrix} \right)^{-1} \begin{smallmatrix}┏┓\\┃┃\\┗┛\\\hphantom{┏}\hphantom{┏}\end{smallmatrix} - \begin{smallmatrix}┏━┓\\┣┳┛\\┃┃\hphantom{┏}\\┗┛\hphantom{┏}\end{smallmatrix} \left(\begin{smallmatrix}┃\\┃\\┃\end{smallmatrix} - \begin{smallmatrix}\hphantom{┏}┏━┓\\┏┻┳┛\\┣━┫\hphantom{┏}\\┗━┛\hphantom{┏}\end{smallmatrix} \right)^{-1} \begin{smallmatrix}\hphantom{┏}\hphantom{┏}\\┏┓\\┃┃\\┗┛\end{smallmatrix} - \begin{smallmatrix}┏━┓\\┣━┫\\┣━┫\\┗━┛\end{smallmatrix}}\\
 & = & \frac{\begin{smallmatrix}┃\\┃\end{smallmatrix} - \begin{smallmatrix}\hphantom{┏}\hphantom{┏}\hphantom{┏}\\┏━┓\\┗━┛\end{smallmatrix}^3}{\left( \begin{smallmatrix}┃\\┃\end{smallmatrix} - \begin{smallmatrix}\hphantom{┏}\hphantom{┏}\hphantom{┏}\\┏━┓\\┗━┛\end{smallmatrix}^3 \right)^2 - 2 \begin{smallmatrix}┏┓\\┃┃\\┗┛\end{smallmatrix}^2 \begin{smallmatrix}\hphantom{┏}\hphantom{┏}\hphantom{┏}\\┏━┓\\┗━┛\end{smallmatrix}}\\
 & = & \frac{1 - z^3}{1 - 4z^3 + z^6}.
\end{array}
$$

The total number of $3 \times n$ tilings is

$$
U_n = \sum_m \begin{pmatrix}n-m\\m\end{pmatrix} 2^{\frac{n}{2} - m}.
$$

---

Q3 - How many ways are there to pay 50 cents?

Let $P$, $N$, $D$, $Q$, and $C$ be the generating functions of the numbers of ways to pay n cents when we're allowed to use coins that are worth at most 1, 5, 10, 25, and 50 cent, we have

$$
P = \emptyset + \textcircled{\scriptsize 1} + \textcircled{\scriptsize 1}^2 + \cdots,
$$

$$
N = (\emptyset + \textcircled{\scriptsize 5} + \textcircled{\scriptsize 5}^2 + \cdots)P,
$$

$$
D = (\emptyset + \textcircled{\scriptsize 10} + \textcircled{\scriptsize 10}^2 + \cdots)N,
$$

$$
Q = (\emptyset + \textcircled{\scriptsize 25} + \textcircled{\scriptsize 25}^2 + \cdots)D,
$$

$$
C = (\emptyset + \textcircled{\scriptsize 50} + \textcircled{\scriptsize 50}^2 + \cdots)Q.
$$

---

Multiplying the equations together gives us the compact expression

$$
C = \frac{1}{1-z}\frac{1}{1-z^5}\frac{1}{1-z^{10}}\frac{1}{1-z^{25}}\frac{1}{1-z^{50}}.
$$

The corresponding generating function is an inffinite product of fractions,

$$
P = \frac{1}{1-z}\frac{1}{1-z^2}\frac{1}{1-z^{3}}\cdots,
$$

and the coefficient of $z^n$ when these factors are fully multiplied out is called $p(n)$, the number of partitions of $n$.

---

### 7.2 Basic Maneuvers

---

$G(z) = g_0 + g_1 z^ + \cdots = \sum_{n \ge 0}g_n z^n$ is the generating function for the sequence $\langle g_0, g_1, g_2, \ldots \rangle$.

The coefficient of $z^n$ was then the number of combinatorial objects having $n$ occurrences of that feature.

---

Reshaping generating functions.

$$
\alpha F(z) + \beta G(z) = \sum_n (\alpha f_n + \beta g_n) z^n;
$$

$$
z^m G(z) = \sum_n (g_{n-m}) z^n, \quad \text{integer} \; m > 0;
$$

$$
G(cz) = \sum_n c^n g_{n} z^n;
$$

$$
G'(z) = \sum_n (n+1) g_{n+1} z^n;
$$

$$
\int_0^z G(t) dt = \sum_{n \ge 1} \frac{1}{n} g_{n-1} z^n;
$$

$$
F(z)G(z) = \sum_{n} \left( \sum_{k} f_k g_{n-k} \right) z^n;
$$

---

### 7.3 Solving Recurrences

---

Given a sequence $\langle g_{n_i} \rangle$ that satisffies a given recurrence, we seek a closed form for $g_n$ in terms of $n$. A solution  via generating functions proceeds in four steps:

* Step 1. Write down a single equation that expresses $g_n$ in terms of other elements of the sequence.
* Step 2. Multiply both sides of the equation by $z^n$ and sum over all $n$.
* Step 3. Solve the resulting equation, getting a closed form for $G(z)$.
* Step 4. Expand G(z) into a power series and read off the coefficient of $z^n$.

---

Rational Expansion Theorem for Distinct Roots.

If $R(z) = P(z) / Q(z)$, where $Q(z) = q_0(1 - \rho_1 z) \cdots (1 - \rho_l z)$ and the numbers $(\rho_1, \ldots, \rho_l)$ are distinct, and if $P(z)$ is a polynomial of degree less than $l$, then

$$
[z^n] R(z) = a_1 \rho_1^n + \cdots + a_l \rho_l^n,
$$
where

$$
a_k = \frac{-\rho_k P(1/\rho_k)}{Q'(1/\rho_k)}.
$$

---

Example 1: Fibonacci numbers.

* Step 1. $g_0 = g_{n-1} + g_{n-2} + [n=1] = \begin{cases}0 & n \le 0\\1 & n = 1\\g_{n-1} + g_{n-2} & n \ge 2\end{cases}$.
* Step 2. $G(z) = \sum_n g_n z^n = \sum_n g_{n-1} z^n + \sum_n g_{n-2} z^n + \sum_n [n=1] z^n = z G(z) + z^2 G(z) + z$.
* Step 3. $G(z) = \frac{z}{1 - z - z^2}$.
* Step 4. According to Rational Expansion Theore for Distinct Roots, $a(\rho)=\frac{-\rho P(1/\rho)}{Q'(1/\rho)} = \frac{\rho}{\rho + 2}$, $a(\phi) = 1 / \sqrt{5}$, $a(\hat{\phi}) = -1 / \sqrt{5}$, so that $F_n = (\phi^n - \hat{\phi}^n) / \sqrt{5}$.

---

General Expansion Theorem for Rational Generating Functions.

If $R(z) = P(z) / Q(z)$, where $Q(z) = q_0(1 - \rho_1 z)^{d_1} \cdots (1 - \rho_l z)^{d_l}$ and the numbers $(\rho_1, \ldots, \rho_l)$ are distinct, and if $P(z)$ is a polynomial of degree less than $d_1 + \cdots + d_l$, then

$$
[z^n] R(z) = f_1(n) \rho_1^n + \cdots + f_l(n) \rho_l^n, \quad \text{where},
$$

where each $f_k(n)$ is a polynomial of degree $d_k - 1$ with leading coefficient

$$
a_k = \frac{(-\rho_k)^{d_k} P(1/\rho_k) d_k}{Q^{(d_k)}(1/\rho_k)}.
$$

---

Example 2: A more-or-less random recurrence.

* Step 1. $g_0 = g_{n-1} + 2g_{n-2} + (-1)^n[n\ge 0]$.
* Step 2. $G(z) = \sum_n g_n z^n = \sum_n g_{n-1} z^n + 2 \sum_n g_{n-2} z^n + \sum_{n\ge 0} (-1)^n z^n + \sum_{n=1} z^n = z G(z) + 2z^2 G(z) + \frac{1}{1+z} + z$.
* Step 3. $G(z) = \frac{1+z+z^2}{(1 - 2z)(1+z)^2}$.
* Step 4. According to General Expansion Theorem for Rational Generating Functions, $\rho_1 = 2$, $\rho_2 = -1$, $g_n = a_1 2^n + (a_2 n + c)(-1)^n$, where $a_1=\frac{(-2)\left(1+1/2+(1/2)^2\right)}{(-2)(1+1/2)^2}=\frac{7}{9}$, $a_2=\frac{(1)^2\left(1+(-1)+(-1)^2\right)(2)}{(2)\left(1-2(-1)\right)}=\frac{1}{3}$. Plugging in $n = 0$ tells us that $c=\frac{2}{9}$, so that $g_n = \frac{7}{9} 2^n + \left(\frac{1}{3} n + \frac{2}{9}\right)(-1)^n$.

---

Example 3: Mutually recursive sequences - the problem of $3 \times n$ domino tilings.

$U_n$ is the total number of ways of $3 \times n$ domino tilings, $V_n$ is the number of ways to cover a $3 \times n$ rectangle-minus-corner, using $(3n - 1)/2$ dominoes.

* Step 1. $U_n = 2V_{n-1} + U_{n-2} + [n=0]$, $V_n = U_{n-1} + V_{n-2}$.
* Step 2. $G(z) = \sum_n g_n z^n = \sum_n g_{n-1} z^n + 2 \sum_n g_{n-2} z^n + \sum_{n\ge 0} (-1)^n z^n + \sum_{n=1} z^n = z G(z) + 2z^2 G(z) + \frac{1}{1+z} + z$.
* Step 3. $G(z) = \frac{1+z+z^2}{(1 - 2z)(1+z)^2}$.
* Step 4. According to General Expansion Theorem for Rational Generating Functions, $\rho_1 = 2$, $\rho_2 = -1$, $g_n = a_1 2^n + (a_2 n + c)(-1)^n$, where $a_1=\frac{(-2)\left(1+1/2+(1/2)^2\right)}{(-2)(1+1/2)^2}=\frac{7}{9}$, $a_2=\frac{(1)^2\left(1+(-1)+(-1)^2\right)(2)}{(2)\left(1-2(-1)\right)}=\frac{1}{3}$. Plugging in $n = 0$ tells us that $c=\frac{2}{9}$, so that $g_n = \frac{7}{9} 2^n + \left(\frac{1}{3} n + \frac{2}{9}\right)(-1)^n$.

---

Example 4: A closed form for change.

---

P. 356

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
