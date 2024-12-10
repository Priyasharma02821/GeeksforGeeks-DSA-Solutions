<h2><a href="https://www.geeksforgeeks.org/problems/stable-sort-and-position1359/1?page=1&sortBy=difficulty">Stable Sort and Position</a></h2><h3>Difficulty Level : Difficulty: Basic</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 14pt;">Given an array <strong>arr</strong> integers that may contain duplicate elements, the index of an element of this array is given to us <strong>k </strong>(0-based indexing), the task is to find the final position of this element in the array after the stable sort is applied to the array.&nbsp;</span></p>
<p><span style="font-size: 14pt;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input:</strong> arr[]= [3, 4, 3, 5, 2, 3, 4, 3, 1, 5], k = 5
<strong>Output:</strong> 4
<strong>Explanation</strong>: Element initial index – 5 (3) After sorting array by stable sorting algorithm, we get array as shown [1(8), 2(4), 3(0), 3(2), 3(5), 3(7), 4(1), 4(6), 5(3), 5(9)] with their initial indices shown in parentheses next to them.</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input:</strong> arr[]= [3, 4, 3, 5, 2, 3, 4, 3, 1, 5], k = 2
<strong>Output:</strong> 3
<strong>Explanation</strong>: Element initial index – 2 (3) After sorting array by stable sorting algorithm, we get array as shown [1(8), 2(4), 3(0), 3(2), 3(5), 3(7), 4(1), 4(6), 5(3), 5(9)] with their initial indices shown in parentheses next to them.</span></pre>
<p><span style="font-size: 14pt;"><strong>Expected Time Complexity:</strong> O(n).<br><strong>Expected Auxiliary Space:</strong> O(1).</span></p>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong><br>1 ≤ arr.size() ≤ 10<sup>6<br></sup>1 ≤ arr[i] ≤ 10<sup>5</sup><sup><br></sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Sorting</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;