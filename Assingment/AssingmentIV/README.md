# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++. 
Students are expected to implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

Developer: Yi-Kai Lo  
Email: karlluo1k@gmail.com

## My Hash Function
### Integer Keys 
- Formula / pseudocode:
  ```text
    FUNCTION myHashInt(key: Integer, m: Integer) -> Integer:
        RETURN key MOD 97
    END FUNCTION
  ```
- Rationale: 
    若是取除以質數的餘數作hash，餘數越大collisions發生的情形會越少，因為質數的因數只有1和自己，
    我的實作中用97是因為main給的integer keys皆小於97，若是取目前已知的最大質數那發生collisions的情形
    應該能降到最低。
### Non-integer Keys
- Formula / pseudocode:
  ```text
    FUNCTION myHashString(str: String, m: Integer) -> Integer:
        hash = 0  
        p = 10
        i = 0
        WHILE str[i] IS NOT NULL:
            char_value = INTEGER(str[i])
            p_power_i = pow_c(p, i)
            hash = hash + (char_value * p_power_i)
            i = i + 1
        RETURN INTEGER(hash MOD 97)
    END FUNCTION
    FUNCTION pow_c(base: Integer, exponent: Integer) -> Integer:
    END FUNCTION
  ```
- Rationale: 
    我先設一變數p，這個assingment中我將其設為10，以及i代表這是第i個字元，
    hash算法是把每一個字元的ascii碼乘以p的i次方後加總，最後取mod 97。
    加總的方式將字串中每個字元對 hash 值的影響分開，使得字串順序不同時也能得到不同的 hash 值，
    減少碰撞；而選擇97的原因如同integer keys的算法。

## Experimental Setup
- Table sizes tested (m): 10, 11, 37
- Test dataset:
  - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
  - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
- Compiler: GCC and G++
- Standard: C23 and C++23

## Results
| Table Size (m) | Index Sequence         | Observation              |
|----------------|------------------------|--------------------------|
| 10             | 1, 2, 3, 4, ...        | Pattern repeats every 10 |
| 11             | 10, 0, 1, 2, ...       | More uniform             |
| 37             | 20, 21, 22, 23, ...    | Near-uniform             |

## Compilation, Build, Execution, and Output

### Compilation
- The project uses a comprehensive Makefile that builds both C and C++ versions with proper flags:
  ```bash
  # Build both C and C++ versions
  make all
  
  # Build only C version
  make c
  
  # Build only C++ version
  make cxx
  ```

### Manual Compilation (if needed)
- Command for C:
  ```bash
  gcc -std=c23 -Wall -Wextra -Wpedantic -g -o C/hash_function C/main.c C/hash_fn.c
  ```
- Command for C++:
  ```bash
  g++ -std=c++23 -Wall -Wextra -Wpedantic -g -o CXX/hash_function_cpp CXX/main.cpp CXX/hash_fn.cpp
  ```

### Clean Build Files
- Remove all compiled files:
  ```bash
  make clean
  ```

### Execution
- Run the compiled binary:
  ```bash
  ./hash_function
  ```
  or
  ```bash
  ./hash_function_cpp
  ```

### Result Snapshot
- Output for integers:
  ```
  === Hash Function Observation (C Version) ===

  === Table Size m = 10 ===
  Key     Index
  -----------------
  21      21
  22      22
  23      23
  24      24
  25      25
  26      26
  27      27
  28      28
  29      29
  30      30
  51      51
  52      52
  53      53
  54      54
  55      55
  56      56
  57      57
  58      58
  59      59
  60      60

  === Table Size m = 11 ===
  Key     Index
  -----------------
  21      21
  22      22
  23      23
  24      24
  25      25
  26      26
  27      27
  28      28
  29      29
  30      30
  51      51
  52      52
  53      53
  54      54
  55      55
  56      56
  57      57
  58      58
  59      59
  60      60

  === Table Size m = 37 ===
  Key     Index
  -----------------
  21      21
  22      22
  23      23
  24      24
  25      25
  26      26
  27      27
  28      28
  29      29
  30      30
  51      51
  52      52
  53      53
  54      54
  55      55
  56      56
  57      57
  58      58
  59      59
  60      60
  ```

- Output for strings:
  ```
  === String Hash (m = 10) ===
  Key     Index
  -----------------
  cat     59
  dog     64
  bat     58
  cow     14
  ant     90
  owl     73
  bee     53
  hen     86
  pig     16
  fox     20

  === String Hash (m = 11) ===
  Key     Index
  -----------------
  cat     59
  dog     64
  bat     58
  cow     14
  ant     90
  owl     73
  bee     53
  hen     86
  pig     16
  fox     20

  === String Hash (m = 11) ===
  Key     Index
  -----------------
  cat     59
  dog     64
  bat     58
  cow     14
  ant     90
  owl     73
  bee     53
  hen     86
  pig     16
  fox     20

  === String Hash (m = 37) ===
  Key     Index
  -----------------
  cow     14
  ant     90
  owl     73
  bee     53
  hen     86
  pig     16
  fox     20
  ...
  ```

- Observations: 以上測資中integer與string的結果看起來都相當均勻，不過integer函式的測試數字都不大且不重複，因此有看起來每個index皆與key值相同的清況。

## Analysis
- 取mod使用質數可以減少collision發生的機率，單看collision發生的情況，質數越大效果越好。
- 不過如果使用過於大的質數且沒有做更多處理可能導致index過長、多數key值即為index等問題
- 處理string時每一個字元乘上不同的數字可以避免同樣的字元以不同順序出現時得到同樣的hash，也減少了碰撞並得到更均勻的分布。

## Reflection
1. Integer hash function 除了可以使用更大的質數，應該可以多做處理、控制hash address的大小以及降低key值即為hash address的發生，只是這勢必要在collision發生情況上做一定程度的妥協。
