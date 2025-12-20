## Discovering Community Structure in Graphs using PCA

### Objective

The goal of this exercise is to explore how **Principal Component Analysis (PCA)** can reveal
community structure in graphs by operating directly on the **adjacency matrix**.

You will work with a fixed graph that has a known community structure and analyze how PCA
maps high-dimensional connectivity patterns into a low-dimensional space.

---

### Graph generation (given – do not modify)

All students must work on the same graph.

```python
import numpy as np
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

1. Extract the **adjacency matrix** of the graph.

2. Apply **PCA** to reduce the node representations to **two dimensions**.

3. Visualize the graph using the 2D PCA coordinates.

4. Compare the PCA-based visualization with standard graph layouts
   (e.g., Spring, Circular, Kamada–Kawai).

5. Data representation task:
   Display, in a clear tabular or textual form, the relationship between:

   * each node’s adjacency vector (or a small selected part of it),
   * its corresponding 2D PCA coordinates,
   * and its true community label.

   The goal is to explicitly show how each row of the adjacency matrix is mapped
   to a point in the PCA space.
   Displaying only a subset of rows (e.g., first few nodes) is sufficient.

---

### Conceptual questions (for thinking only)

You do **not** need to write the answers in the notebook.

1. What does each row of the adjacency matrix represent geometrically?
2. Why can PCA separate communities even though it does not explicitly use graph edges?
3. What information does the explained variance ratio provide about the graph structure?

---

### Submission

Submit a **Jupyter Notebook (.ipynb)** containing:

* your code,
* generated visualizations,
* numerical outputs and tables.

Written answers to the conceptual questions are **not required**.
