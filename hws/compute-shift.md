
# ✅ Exercise: 1D Function Alignment with Sampled Data (Automatic Differentiation)

---

## ✨ Exercise: Automatic Differentiation for Aligning Sampled 1D Signals

In the previous example, the functions $f(x)$ and $g(x)$ were given analytically (e.g., sine functions), which made alignment straightforward.
However, in many real applications the function is not known and you only have sampled data points.

In this exercise, you will replicate the alignment experiment but under a more realistic setting:

* You will hide the analytical form of $f$ 
* The algorithm will only receive:

  * a vector of sample locations $x$,
  * sample values $f(x)$,
  * and a shifted version $g(x) = f(x - t^*)$ 

Your task is to estimate the unknown shift $t$ using gradient descent and automatic differentiation.

---

## 🧩 Task Description

You are given:

* A vector of points:

$$
x = \text{linspace}(-3,3,300)
$$

* Sampled data from a “mysterious” function (for example the previous $sin()$):

$$
f_{\text{samples}} = f(x)
$$

* And a shifted version:

$$
g(x) = f(x - t^*)
$$

The goal is to estimate the unknown shift parameter $t$ by minimizing:

$$
L(t) = \frac{1}{N} \sum_{i=1}^N \big( f(x_i - t) - g(x_i) \big)^2 .
$$

---

### 2. Plot the results

Every 4 iterations, show:

* the target signal $g(x)$
* the shifted estimate $f(x - t)$
* the current value of $t$

At the end, print the estimated shift.

---

## 📌 What You Must Write

Write a full Python program in PyTorch that includes:

1. Your custom differentiable linear interpolator
2. The optimization loop
3. Intermediate plots
4. Final estimated shift

---

## 🎯 Learning Outcomes

After completing this exercise, you should understand:

* How automatic differentiation works even when no analytical function exists
* How to implement differentiable operations from scratch
* How alignment problems appear in signal processing, vision, and ML
* How PyTorch handles gradients through your own custom code

