<h2><a href="https://www.geeksforgeeks.org/problems/asteroid-collision/1">Asteroid Collision</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an integer array <strong>asteroids[]</strong>&nbsp;</span><span style="font-size: 14pt;">where each value represents an asteroid’s size and direction: </span></p>
<ul>
<li><span style="font-size: 14pt;">Positive means it moves right.</span></li>
<li><span style="font-size: 14pt;">Negative means it moves left. </span></li>
</ul>
<p><span style="font-size: 14pt;">All asteroids move at the same speed, and when two asteroids moving in opposite directions meet, the smaller one explodes. If both are the same size, both are destroyed. Asteroids moving in the same direction never collide. </span></p>
<p><span style="font-size: 14pt;">Return the final state of the asteroids after all collisions.</span></p>
<p><span style="font-size: 18px;"><strong>Examples :&nbsp;</strong></span></p>
<pre><span style="font-size: 18px;"><strong style="font-size: 18px;">Input:</strong><span style="font-size: 18px;"> asteroids[] = [3, 5, -3]</span><br><strong style="font-size: 18px;">Output:</strong><span style="font-size: 18px;"> [3, 5]</span><br><span style="font-size: 18px;"><strong>Explanation:</strong> The asteroid 5 and -3 collide resulting in 5. The 5 and 3 never collide.</span></span></pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> asteroids[] = [10, -10]<br><strong>Output:</strong> []<br><strong>Explanation:</strong> The asteroid -10 and 10 collide exploding each other.</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ asteroids.size() ≤ 10<sup>5</sup><br>-1000 ≤ asteroids[i] ≤ 1000<br>asteroids[i] != 0</span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Stack</code>&nbsp;<code>Data Structures</code>&nbsp;