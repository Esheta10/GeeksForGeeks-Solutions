<h2><a href="https://www.geeksforgeeks.org/problems/k-closest-elements3619/1">K closest elements</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p data-start="0" data-end="183"><span style="font-size: 14pt;">You are given a sorted array <strong><code data-start="29" data-end="36">arr[]</code></strong> of unique integers, an integer <strong><code data-start="68" data-end="71">k</code></strong>, and a target value <strong><code data-start="92" data-end="95">x</code></strong>. Return exactly <strong><code data-start="112" data-end="115">k</code></strong> elements from the array closest to <strong><code data-start="151" data-end="154">x</code></strong>, excluding <code data-start="166" data-end="169"><strong>x</strong></code> if it exists.</span></p>
<p data-start="185" data-end="229"><span style="font-size: 14pt;">An element <strong><code data-start="196" data-end="199">a</code></strong> is closer to <strong><code data-start="213" data-end="216">x</code></strong> than <strong><code data-start="222" data-end="225">b</code></strong> if:</span></p>
<p><span style="font-size: 14pt;"> </span></p>
<ul>
<li><span style="font-size: 14pt;"><code data-start="233" data-end="252">|a - x| &lt; |b - x|</code>, or</span></li>
<li><code style="font-size: 14pt;" data-start="261" data-end="281">|a - x| == |b - x|</code><span style="font-size: 14pt;"> and </span><code style="font-size: 14pt;" data-start="286" data-end="293">a &gt; b</code><span style="font-size: 14pt;"> (i.e., prefer the larger element if tied)</span></li>
</ul>
<p><span style="font-size: 14pt;"> </span></p>
<p data-start="122" data-end="249"><span style="font-size: 14pt;"> </span></p>
<p data-start="337" data-end="416" data-is-last-node="" data-is-only-node=""><span style="font-size: 14pt;">Return the <strong><code data-start="348" data-end="351">k</code></strong> closest elements in order of closeness.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr[] = [1, 3, 4, 10, 12], k = 2, x = 4
<strong>Output:</strong> [3, 1]
<strong>Explanation:</strong> 4 is excluded from the consideration.<br>The closest element to 4 is 3 with a distance of 1.<br>The next closest element is 1 with a distance of 3.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr[] = [10, 20, 30, 40, 50], k = 3, x = 25
<strong>Output:</strong> [30, 20, 40]
<strong>Explanation:</strong> </span><span style="font-size: 18px;">First closest element to 25 is 30, since 30 &gt; 20.
Second closest element to 25 is 20.
Third closest element to 25 is 40.<br></span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ arr.size() ≤ 10<sup>5</sup><br>1 ≤ k ≤ arr.size()<br>1 ≤ x ≤ 10<sup>6</sup></span><br><span style="font-size: 18px;">1 ≤ arr[i] ≤ 10<sup>6</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>OYO Rooms</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Binary Search</code>&nbsp;<code>Algorithms</code>&nbsp;<code>STL</code>&nbsp;<code>priority-queue</code>&nbsp;