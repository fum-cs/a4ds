## 2D Image Alignment Using Automatic Differentiation

In this exercise, you will study a simple **2D image registration** problem using PyTorch and automatic differentiation.

The goal is to estimate a 2D translation $(t_x, t_y)$ that aligns a *moving image* to a *target image* by minimizing a mean squared error loss.

---

### Problem setup

You are given two synthetic images:

- A **target image** containing a white square.
- A **moving image** containing the same square, but shifted.

We assume that the transformation between the two images is **only a translation**.

---

### Important note on coordinate normalization

The translation parameters $(t_x, t_y)$ are defined in **normalized image coordinates**, where:

- Image coordinates lie in the interval $[-1, 1]$
- $(0,0)$ corresponds to the image center
- $(t_x, t_y)$ do **not** represent pixel displacements

This normalization is required by PyTorch's `grid_sample` function.

---

### Optimization problem

The loss function is defined as:

$$
\mathcal{L}(t_x, t_y)
=
\frac{1}{HW}
\sum_{i,j}
\Big(
I_{\text{moving}}(x_i - t_x, y_j - t_y)
-
I_{\text{target}}(x_i, y_j)
\Big)^2
$$

The translation parameters $(t_x, t_y)$ are optimized using gradient-based methods and automatic differentiation.

---

### Provided code

```python
import torch
import torch.nn.functional as F
import matplotlib.pyplot as plt

# synthetic target image (white square)
target = torch.zeros(1, 1, 80, 80)
target[:, :, 20:60, 20:60] = 1.0

# moving image: shifted square
moving = torch.zeros_like(target)
moving[:, :, 25:65, 10:50] = 1.0

# learnable translation parameters (normalized coordinates)
theta = torch.tensor([0.0, 0.0], requires_grad=True)
optimizer = torch.optim.Adam([theta], lr=0.05)

def warp_image(img, tx, ty):
    B, C, H, W = img.shape
    grid_y, grid_x = torch.meshgrid(
        torch.linspace(-1, 1, H),
        torch.linspace(-1, 1, W),
        indexing="ij"
    )
    grid = torch.stack([grid_x - tx, grid_y - ty], dim=-1)
    return F.grid_sample(
        img,
        grid.unsqueeze(0),
        mode="bilinear",
        align_corners=True
    )

for it in range(11):
    optimizer.zero_grad()
    warped = warp_image(moving, theta[0], theta[1])
    loss = F.mse_loss(warped, target)
    loss.backward()
    optimizer.step()

    if it % 2 == 0:
        plt.figure(figsize=(3,3))
        plt.title(f"Iteration {it}")
        plt.imshow(warped[0,0].detach(), cmap='gray')
        plt.axis('off')
        plt.show()

print("Estimated translation:", theta.detach())
````

---

### Questions

1. **Loss analysis**
   Identify the loss function being minimized and explain its components.
   Which variables are optimized, and which quantities are fixed?

2. **Automatic differentiation**
   Explain why gradients with respect to $(t_x, t_y)$ can be computed, even though the transformation is geometric.

3. **Expected solution**
   Based on how the two images are constructed, to what values should $(t_x, t_y)$ approximately converge?
   Provide a geometric explanation.

4. **Optimization behavior**
   Investigate how the optimization changes when:

   * the learning rate is increased or decreased,
   * the square size is modified,
   * the initial translation is far from the correct value.

---

### Submission instructions

* Prepare a **Jupyter Notebook** (`.ipynb`) containing:

  * the executed code,
  * visual outputs,
  * written answers to the questions.
* Upload the notebook to the university learning management system.

