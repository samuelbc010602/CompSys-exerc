# Exercises for Introduction to security and encryption

## Exercises from Chapter 8 of Kurose and Ross on "Security"
* P3
Yes the intruder can go through each cipher letter and see how many letters it has been shifted with according to the original letter and from there guess the of the monoalphabets that are used to encode messages. 
* P8
n = 5*11 = 55
z = 4*10 = 40
e = 3 since e<n and gcd(e,z) = 1.
solve((d*3) mod 40 = 1) = d = 1/3
m^e mod n = ciphertext
9^3 mod 55 = 14

* P9
g and p are prime numbers
S_a = 123
S_b = 321
P_a = g^123 mod p
P_b = g^321 mod p
secret key alice = (g^321 mod p)^123 mod p
secret key bob = (g^123 mod p)^321 mod p
a)
Since (a mod n)^d mod n = a^d mod n
Then we can rewrite both secrete keys the following way:
secret key alice = (g^(321*123)) mod p, since the order of factors doesnt matter the secret keys will be the same
b)
alice public key = 2^5 mod 11 = 10
bob public key = 2^12 mod 11 = 4
c)
S = 4^5 mod 11 = 1
S' = 10^12 mod 11 = 1
d)



* P10
Fejl tjek op på
* P13
The file is broken into blocks of equal size. For each block, calculate the hash (for
example with MD5 or SHA-1). The hashes for all of the blocks are saved in the .torrent
file. Whenever a peer downloads a block, it calculates the hash of this block and
compares it to the hash in the .torrent file. If the two hashes are equal, the block is valid.
Otherwise, the block is bogus, and should be discarded.
* P15
Fejl
* P17

* P19

## Not Promgramming Task
Create a diagram for your solution to A4. This should show each of the different processes/threads and how they communicate with each other. Identify any points of deadlock present and then either justfiy why they won't occur, or redesign your solution. You may find your design is deadlock free, in which case justify this asssessment. 

Make a note of any shared variables between different processes/threads and determine if any race conditions will occur. If so, alter your design to account for this either my managing access to those variables or not sharing them at all.

As a note, this is the sort of thing that looks very nice in a report, along with any discussion relating to it.