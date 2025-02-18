# **Complete and Elaborated Definition of LPS (Longest Prefix Suffix)**

## The **Longest Prefix Suffix (LPS) array** is a fundamental component of the **Knuth-Morris-Pratt (KMP) pattern-matching algorithm**. It is an auxiliary array used to optimize pattern searching by avoiding unnecessary re-evaluations of characters

### **Definition**

### The **LPS array** for a given pattern **P** is an array where each entry **LPS[i]** represents the length of the longest proper **prefix** of the substring P[0:i] (from the start of the pattern to the i-th index) that is also a **suffix** of the same substring

In simpler terms, LPS[i] stores the **longest length** of a prefix of P that is also a **proper suffix** ending at index i.

---

### **Understanding Prefix and Suffix**

- A **prefix** of a string is any substring that starts from index 0.
  - Example: Prefixes of "ABAB": "A", "AB", "ABA", "ABAB"
- A **suffix** of a string is any substring that ends at the last character.
  - Example: Suffixes of "ABAB": "B", "AB", "BAB", "ABAB"
- A **proper prefix** is a prefix that is **not the entire string**.
  - Example: Proper prefixes of "ABAB": "A", "AB", "ABA"
- A **proper suffix** is a suffix that is **not the entire string**.
  - Example: Proper suffixes of "ABAB": "B", "AB", "BAB"

#### **Example:**  

For the pattern "ABABAB", the LPS array is:

`LPS = [0, 0, 1, 2, 3, 4]`

This means:

- `LPS[0] = 0` → No prefix matches any suffix.
- `LPS[2] = 1` → "A" (prefix) is equal to "A" (suffix).
- `LPS[3] = 2` → "AB" (prefix) is equal to "AB" (suffix).
- `LPS[4] = 3` → "ABA" (prefix) is equal to "ABA" (suffix).
- `LPS[5] = 4` → "ABAB" (prefix) is equal to "ABAB" (suffix).

---

### **Properties of LPS (Longest Prefix Suffix)**

1️⃣ **LPS array helps in skipping unnecessary comparisons**

- Instead of re-evaluating characters after a mismatch, the **LPS array** provides information on where to resume searching in the pattern.
- This reduces redundant computations and ensures an **efficient time complexity of O(n + m)** for pattern matching.

2️⃣ **The value of LPS[i] is always ≤ i**

- Since it represents the length of the longest prefix-suffix pair, **LPS[i]** can never be greater than i (the length of the substring P[0:i]).

3️⃣ **If LPS[i] > 0, the prefix and suffix must be contiguous**

- The matching prefix and suffix must be **adjacent and consecutive**.
- Example: "ABCABC" has `LPS = [0, 0, 0, 1, 2, 3]`, meaning "ABC" at the start also appears at the end.

4️⃣ **If LPS[i] = k, then the first k characters are repeated**

- If `LPS[i] = k`, then the substring P[0:k−1] (first k characters) appears again at the end of the substring P[0:i].

5️⃣ **LPS values are non-decreasing**

- The values in the LPS array either increase or stay the same, never decreasing suddenly.
- This ensures that the pattern **reuses the longest prefix information effectively**.

6️⃣ **The last value of the LPS array (LPS[m-1]) indicates the longest border of the entire pattern**

- If `LPS[m-1]` is nonzero, it means the pattern itself is composed of repeating structures.

---

### **Mathematical Definition of LPS**

For a pattern P of length m, the **LPS array** LPS[0:m−1] is defined as:

```
LPS[i] = max { k | P[0:k−1] = P[i−k+1:i] }
```

where `P[0:k−1]` is a proper prefix, and `P[i−k+1:i]` is a proper suffix.

---

### **Example Calculation of LPS Array**

Let’s compute the **LPS array** for the pattern "AABAACAABAA".

#### **Step 1: Initialize LPS array**

`LPS = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]`

#### **Step 2: Compute LPS values**

| Index | Pattern Prefix | Longest Prefix-Suffix | LPS Value |
|-------|---------------|----------------------|-----------|
| 0     | "A"           | No match            | **0**     |
| 1     | "AA"         | "A" = "A"          | **1**     |
| 2     | "AAB"        | No match            | **0**     |
| 3     | "AABA"       | "A" = "A"          | **1**     |
| 4     | "AABAA"      | "AA" = "AA"        | **2**     |
| 5     | "AABAAC"     | No match            | **0**     |
| 6     | "AABAACA"    | "A" = "A"          | **1**     |
| 7     | "AABAACAA"   | "AA" = "AA"        | **2**     |
| 8     | "AABAACAAB"  | "AAB" = "AAB"      | **3**     |
| 9     | "AABAACAABA" | "AABA" = "AABA"    | **4**     |
| 10    | "AABAACAABAA"| "AABAA" = "AABAA"  | **5**     |

Final LPS array:

`LPS = [0, 1, 0, 1, 2, 0, 1, 2, 3, 4, 5]`

---

### **Applications of LPS Array**

1️⃣ **KMP Algorithm**: Used to efficiently find occurrences of a pattern in a string.  
2️⃣ **Pattern Repetition Detection**: Helps find repeating sequences in a given string.  
3️⃣ **String Periodicity**: Used in **cyclic string problems** and **string compression**.  
4️⃣ **Automata and Text Processing**: Helps in preprocessing steps in **text editors and compilers**.

---

### **Conclusion**

The **LPS (Longest Prefix Suffix) array** is a key component of the **KMP pattern-matching algorithm**, ensuring that pattern searches are efficient by avoiding unnecessary character comparisons. It is calculated in **O(m) time** and is crucial in many **string processing applications**.

Would you like a **code implementation of LPS calculation**? 🚀
