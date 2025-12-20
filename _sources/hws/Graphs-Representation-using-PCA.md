
## Discovering Community Structure in Graphs using PCA

### Objective

The goal of this exercise is to explore how **Principal Component Analysis (PCA)** can reveal
community structure in graphs by operating directly on the **adjacency matrix**.

You will work with a fixed graph that has a known community structure and analyze how PCA
embeds the nodes into a low-dimensional space.

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
2. Normalize the adjacency matrix before applying PCA.
3. Apply **PCA** to reduce the node representations to **two dimensions**.
4. Use the PCA coordinates to visualize the graph.
5. Compare the PCA-based visualization with standard graph layouts
   (e.g., Spring, Circular, Kamada–Kawai).

---

### Conceptual questions (for thinking only)

You do **not** need to write the answers in the notebook.

1. What does each row of the adjacency matrix represent geometrically?
2. Why is normalization important before applying PCA in this context?
3. Why can PCA separate communities even though it does not use graph connectivity explicitly?
4. What information does the explained variance ratio give about the graph structure?
5. What are the limitations of PCA-based embeddings for community detection?

---

### Submission

Submit a **Jupyter Notebook (.ipynb)** containing:

* your code,
* generated visualizations,
* numerical outputs.

Written answers to the conceptual questions are **not required**.