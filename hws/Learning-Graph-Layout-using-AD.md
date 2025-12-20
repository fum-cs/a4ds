
## Learning a Graph Layout using Automatic Differentiation

### Objective

In this exercise, you will learn how to compute a 2D layout of a graph by **directly optimizing
node coordinates** using gradient-based methods and **automatic differentiation**.

Instead of using a predefined layout algorithm, you will define an energy function and let
the optimizer discover a good layout.

---

### Graph generation (given – do not modify)

All students must work on the same graph.

```python
import networkx as nx

n_communities = 2
community_sizes = [15, 15]
p_in = 0.7
p_out = 0.05

G = nx.stochastic_block_model(
    community_sizes,
    [[p_in, p_out], [p_out, p_in]],
    seed=42
)
````

---

### Tasks

You are asked to implement the following steps:

1. Assign each node a 2D coordinate initialized randomly.
2. Treat the node coordinates as **learnable parameters**.
3. Define an energy (loss) function that includes:

   * attraction between connected nodes,
   * repulsion between all nodes,
   * additional separation between nodes from different communities.
4. Use **PyTorch Autograd** to compute gradients of the energy function.
5. Optimize the node coordinates using gradient descent or Adam.
6. Visualize the graph layout at different optimization steps.

---

### Conceptual questions (for thinking only)

You do **not** need to submit written answers.

1. What are the optimization variables in this problem?
2. Why are both attractive and repulsive forces needed?
3. What role does the community separation term play?
4. Why is automatic differentiation particularly useful here?
5. How is this approach related to classical force-directed layouts?

---

### Submission

Submit a **Jupyter Notebook (.ipynb)** containing:

* your implementation,
* intermediate and final visualizations,
* numerical outputs if applicable.

Written answers to the conceptual questions are **not required**.
