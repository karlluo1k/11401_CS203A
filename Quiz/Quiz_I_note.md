## Questions I wrote incorrectly
### **Quiz I :** 
- ### Q2: Memory Management Code Review
    The following code dynamically allocates memory for an integer array, processes the data, and then expands the array size as needed.
    ```C 
    double *array;
    int n = 10;

    array = (double *) malloc(n * sizeof(double));

    // ... processing code ...

    n = n * 2;
    array = (double *) realloc(array, n * sizeof(double));

    // ... more processing ...

    free(array);
    ```
    Task: Identify the specific memory management issues and provide solutions to ensure safe 
    memory management.
    <br>
    ### <font color = "green">Correct ans:</font>
    - issues:
    <ol type = "1">
        1. Missing malloc() error checking <br>
        2. Unsafe realloc() usage <br>
        3. No error handling strategy <br>
    </ol>

    - solution:
    <br>
        ~~array = (double *) realloc(array, n * sizeof(double));~~
    <br>
        temp = (double *) realloc(array, n * sizeof(double));
    ### Note:
    ```
    避免realloc失敗時遺失原本的array指標，還可以加上輸出錯誤訊息，保證記憶體分配失敗時程式能繼續運行且我們能夠得知。
    ```