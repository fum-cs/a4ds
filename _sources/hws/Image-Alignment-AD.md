## Exercise: 2D Image Alignment Using Automatic Differentiation

In this exercise, you will implement a simple 2D image registration method using PyTorch and automatic differentiation.
The goal is to recover the unknown translation parameters $(t_x, t_y)$ that best align a moving image to a target image.

You are given two synthetic images:

1. A target image that contains a white square.
2. A moving image that contains the same square, but shifted.

We assume that the transformation between the images is a simple translation.
The task is to estimate the translation parameters$ (t_x) $ and $ (t_y) $by minimizing the mean squared error:

$$
\mathcal{L}(t_x, t_y) = \frac{1}{HW} \sum_{i,j} \left( I_{\text{moving}}(x_i - t_x, y_j - t_y) - I_{\text{target}}(x_i, y_j) \right)^2
$$

Use PyTorch's automatic differentiation engine to compute gradients of the loss with respect to $(t_x, t_y)$, and update them using gradient descent.

A warping function is provided that uses `grid_sample` to translate the image.

Your task is to run the following code, understand it, visualize the alignment progress, and explain how automatic differentiation recovers the translation.

```python
import torch
import torch.nn.functional as F
import matplotlib.pyplot as plt

# synthetic target image (white square)
target = torch.zeros(1, 1, 80, 80)
target[:, :, 20:60, 20:60] = 1.0

# initial moving image: shifted version
moving = torch.zeros_like(target)
moving[:, :, 25:65, 10:50] = 1.0

# parameters to learn: translation tx, ty
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
    return F.grid_sample(img, grid.unsqueeze(0), mode="bilinear", align_corners=True)

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
```

### Questions to answer

1. What loss function is being minimized? Write it symbolically.
2. Why does `grid_sample` allow backpropagation through the geometric transformation?
3. What values should$ (t_x) $and$ (t_y) $converge to in this example?
4. Try modifying the square size or changing the learning rate. How does the optimization behave?

