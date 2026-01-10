## About BFS:
### The answer:
- Breadth-First Search (BFS):
    1. Uses a queue. 
    2. Starts from a selected node (usually the top-left or labeled root).
    3. Visits nodes level by level (distance 1, then distance 2, etc.).
    4. Ensures that all neighbors of the current node are visited before moving deeper.
    5. Requires a visited set to avoid revisiting nodes.

### Note:
```
使用queue是紀錄同一level的節點，以達到"Visits nodes level by level"；
而「需要紀錄節點是否被拜訪過，避免重複訪問」是我考試時所漏寫的。
```
___
## About Shaped-based binary tree:
### The answer:
- Shaped-based binary tree
    1. Complete Binary Tree
        - Every level is fully filled except possibly the last (required)
        - Nodes in the last level are filled left to right (required)
        - Used in heap implementations (optional)
    2. Full Binary Tree
        - Every node has 0 or 2 children (required)
    3. Perfect Binary Tree
        - All internal nodes have 2 children and all leaves are at the same depth (required)

### Note:
```
我寫的答案以complete binary tree 作為shaped-based binary tree 的例子，寫到了除了最後一層外，
其他層都需要被填滿，以及最後一層需要由左至右填入，未寫到其用來implement heap。
```
