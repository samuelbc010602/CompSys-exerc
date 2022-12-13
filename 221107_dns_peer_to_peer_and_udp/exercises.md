# Exercises for DNS

## Exercises from Chapter 2 of Kurose and Ross on "Application Layer"

* P19
Made in terminal
  * Read the dig and nslookup man pages. [This short tutorial on dig](https://www.linode.com/docs/networking/dns/use-dig-to-perform-manual-dns-queries/) might be of interest to you.
  * You can install it by installing [bind-tools](http://www.isc.org/downloads/bind/) package if you are on a UNIX machine or the client bind tools for Windows. 
* P21
Yes, the website is cached and the time to lookup the ip-address for that website will therefore be significantly less than other websites that hasn't recently been searched for. 
* P26
No because if Bob doesnt upload to anyone he wont have any peers, which makes him choked. The peers that Alice has is always updated and fixed to the set of peers that have the highest rate of supplying data. Since Bob doesn't upload his rate will eventually fall and he will be dropped. He can be randomly chosen (optimistically unchoked) but that wont last very long.
Charlies isn't right sine all newcommers to the network start with zero chunks

## Create a C programme for DNS lookups
Use the C functions getaddrinfo (https://man7.org/linux/man-pages/man3/gai_strerror.3.html) and (https://man7.org/linux/man-pages/man3/inet_ntop.3.html) to create a program that takes a human readable address such as 'www.google.com', converts it into an appropriate IP address, and prints it to the user.


