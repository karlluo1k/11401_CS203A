## Questions I wrote incorrectly
### **Quiz III :**
- ### Q2. What is a “bucket” in a hash table?
    ### <font color = "green">Correct ans:</font>
    ```
    A container holding one or more records at a table index.
    ```
    ### Note:
    ```
    例如以一個Array作為bucket，每個index儲存linked list，以儲存有相同hash value的物件，for handling collisions。
    ```
___
- ### Q3. Define “load factor (α)” and explain why it affects performance.
    ### <font color = "green">Correct ans:</font>
    ```
    α = n/m; n = number of elements; m = table size;
    higher α -> more collisions -> longer probe chains.
    ```
    ### Note:
    ```
    簡單來說用來代表hash table有多滿，α越大代表越多的collision，是hashing的其中一個重要的概念。
    ```
___
- ### Q4. What is “primary clustering,” and which probing method suffers from it?
    ### <font color = "green">Correct ans:</font>
    ```
    Linear probing; long consecutive filled slots form. 
    ```
    <br>

- ### Q5. What is “secondary clustering,” and how is it different from primary clustering?
    ### <font color = "green">Correct ans:</font>
    ```
    Keys with same hash follow identical probe sequences; not consecutive but identical pattern. 
    ```
    ### Note:
    ```
    primary clustering會在使用linear probing時發生，主要是在說因為碰撞的處理方式，
    當已經有一段連續的slot被占用(cluster)，因為遇到slot被佔用時就會再往後塞，又導致cluster加長，
    又更容易遇到碰撞的惡性循環，導致插入與搜尋變慢；

    為了避免primary clustering，使用quadratic probing使數值更分散，而secondary clustering跟
    primary clustering不一樣的地方在於它不是連續導致的問題，而是有hash相同的情況。
    ```
    >I used ChatGPT to help me clarifying the concepts of linear probing, primary clustering, quadratic probing, and secondary clustering. 
___
- ### Q6. Briefly explain the difference between:
    - Open addressing
    - Separate chaining
<br>

    ### <font color = "green">Correct ans:</font>
    ```
    Open addressing stores all entries in table; chaining stores lists in buckets.
    ```
    ### Note:
    ```
    Separate chaining 有buckets，使用list儲存；Open addressing 則直接儲存於一表中。
    ```