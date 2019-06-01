<h1>C Client Server Code for Linux</h1>

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
<p>Then to run it on a specified port, pass IP Address and port as argument</p>
<p>
<code>./client.out YOUR_IP_HERE 4000</code>
</p>
<p><b>Note:</b> For testing on same PC, use localhost.</p>
<p><b>Note:</b> Put test.txt file in client side</p>
<hr>
<hr>
<h1>C Client and Server code for Windows</h1>
<p>Run this code only on <b>Windows</b> based systems</p>
<hr>
<h3>TCPserver</h3><hr>
<p> To compile this, use the following commands </p>
<p>
  <code>gcc TCPserver.c -o server -lws2_32</code>
</p>
<p> Then for running the code 
  <code>./server.exe</code>
  the port is hardcoded as 55555 and the IP address is 127.0.0.1 
</p>
<h3>TCPclient</h3><hr>
<p>To compile this, use following commands</p>
<p>
<code>gcc client.c -o client -lws2_32 </code>
<p> Then for running the code 
  <code>./client.exe</code>
  the port is hardcoded as 55555 and the IP address is 127.0.0.1 
</p>



  
  
