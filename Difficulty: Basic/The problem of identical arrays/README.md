<h2><a href="https://www.geeksforgeeks.org/problems/the-problem-of-identical-arrays3229/1?page=1&sortBy=difficulty">The problem of identical arrays</a></h2><h3>Difficulty Level : Difficulty: Basic</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Check whether given two arrays <strong>arr1[]</strong>, <strong>arr2[]&nbsp;</strong>are identical or not. Two arrays are called identical arrays if they contain the same element with the same count, regardless of the order of elements.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> arr1[] = [1, 2, 3, 4, 5], arr2[] = [3, 4, 1, 2, 5]
<strong>Output:</strong> true
<strong>Explanation: </strong>Here we can see array arr1[] = [1, 2, 3, 4, 5] and arr2[] = [3, 4, 1, 2, 5]. If we look both the array then we can get that array arr2[] is the permutation of arr1[]. So, both array.are identical. </span></pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> arr1[] = [1, 2, 4], arr2[] = [3, 2, 1]
<strong>Output:</strong> false
<strong>Explanation: </strong>Here we can see that, arr2 is missing 4 and has 3 so they are not identical.</span></pre>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(n).<br><strong>Expected Auxiliary Space:</strong> O(1).</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ arr1.size(), arr2.size() ≤ 10<sup>5<br></sup>arr1.size() = arr2.size()<br>1 ≤ arr1[i],arr2[i] ≤ 10<sup>5</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Sorting</code>&nbsp;<code>Binary Search</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;