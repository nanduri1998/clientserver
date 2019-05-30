<h1>C Client Server Code</h1>

<p>Run this code only on <b>Linux</b> based systems</p>
<hr>
<h3>Server Code</h4><hr>
<p>To compile this, use following commands</p>
<p>
<code>gcc server.c -o server.out</code> or <code>cc server.c -o server.out</code>
</p>
<p>Then to run it on a specified port, pass port as argument</p>
<p>
<code>./server.out 4000</code>
</p>
<hr>
<h3>Client Code</h4><hr>
<p>To compile this, use following commands</p>
<p>
<code>gcc client.c -o client.out</code> or <code>cc client.c -o client.out</code>
</p>
<p>Then to run it on a specified port, pass port as argument</p>
<p>
<code>./client.out YOUR_IP_HERE 4000</code>
</p>
<p><b>Note:</b> For testing on same PC, use localhost.</p>
<p><b>Note:</b> Put test.txt file in client side</p>
