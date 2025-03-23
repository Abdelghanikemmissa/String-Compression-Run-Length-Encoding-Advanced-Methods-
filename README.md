# String-Compression-Run-Length-Encoding-Advanced-Methods-
This project focuses on implementing different levels of string compression, from simple Run-Length Encoding (RLE) to pattern-based compression. Additionally, we will include decompression, case-sensitive handling, and compression efficiency analysis.


📌 Project Tasks
1️⃣ Implement a simple Run-Length Encoding (RLE) algorithm

Replace consecutive repeating characters with <count><character>.

Example: "aaaabb" → "4a2b".

2️⃣ Implement the decompression algorithm

Convert the compressed string back to its original form.

Example: "4a2b" → "aaaabb".

3️⃣ Extend the algorithm to handle case sensitivity (A ≠ a)

Ensure that uppercase and lowercase letters are treated as different characters.

Example: "AAaa" → "2A2a".

4️⃣ Implement a function to detect if the compressed string is longer than the original

If compression increases the string length, return the original instead.

5️⃣ Add pattern-based compression

Detect repeating sequences instead of only single characters.

Example: "abcabcabc" → "3(abc)".

6️⃣ Compare compression ratios for different types of strings

Measure how much different types of strings (random, structured, mixed-case) are compressed.

