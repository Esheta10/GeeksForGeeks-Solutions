<h2><a href="https://www.geeksforgeeks.org/problems/search-pattern0205/1">Search Pattern (KMP-Algorithm)</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 14pt;">Given two strings, one is a text string,&nbsp;<strong>txt</strong> and the other is a pattern string, <strong>pat</strong>. The task is to print the indexes of <strong>all the occurrences</strong> of the pattern string in the text string. Use<strong> 0-based</strong> indexing while returning the indices.&nbsp;<br>Note:<strong>&nbsp;</strong>Return an empty list in case of no occurrences of pattern.<br></span></p>
<p><span style="font-size: 14pt;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>txt = "abcab", pat = "ab"
<strong>Output:</strong> [0, 3]
<strong>Explanation</strong>: The string "ab" occurs twice in txt, one starts are index 1 and the other at index 4. 
</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input</strong>: txt = "abesdu", pat = "edu"
<strong>Output:</strong> []
<strong>Explanation</strong>: There's not substring "edu" present in txt.<br></span></pre>
<pre><span style="font-size: 14pt;"><strong>Input</strong>: txt = "aaaaa", pat = "aa"
<strong>Output:</strong> [0, 1, 2, 3]
<strong>Explanation</strong>: The string "aa" occurs four times, starts from indexes 0, 1, 2, 3.</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong><br>1 ≤ txt.size() ≤ 10<sup>6</sup><br>1 ≤ pat.size() &lt; txt.size()<br>Both the strings consist of lowercase English alphabets.</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Microsoft</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Pattern Searching</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;