# Exercises for Introduction to Computer Network

The following exercises relate to Chapter 1 in Kurose and Ross on the topic "Introduction to Computer Networks".

* R13
a) Two users, both can use the link since it is duplex
b) Each user only sends 1mbps 20 percent of time this is no problem for two users since the link is 2 mbps, but can be a problem with three users since 3*1mbps > 2mpbs
c) 20% as stated in the exercise
d) Probability that all users are transmitting = 2/10*2/10*2/10 = 8/1000 = 1/125. As soon as the link is preoccupied with two of the users the packets from the third will be added to the queue
* R14
If the two ISPs do not peer with each other, then when they send traffic to each other
they have to send the traffic through a provider ISP (intermediary), to which they
have to pay for carrying the traffic. By peering with each other directly, the two ISPs
can reduce their payments to their provider ISPs. An Internet Exchange Points (IXP)
(typically in a standalone building with its own switches) is a meeting point where
multiple ISPs can connect and/or peer together. An ISP earns its money by charging
each of the the ISPs that connect to the IXP a relatively small fee, which may depend
on the amount of traffic sent to or received from the IXP.

* P4
a) 4 circuit between each link, therefore the maximum amount connection will be 4*4=16
b) 8 connections
c) From a to c, we can route two connections through d to c and two connetions from b to c. The same can be done for b to d using a and c
* P13
When the first packet arrive there is no delay, the second packet will experience L/R delay, and third will experience 2*L/R and so on, and thus the average delay will be = N(N+1)/2
* P31 (optional)
* P33 (optional)

# Setup programming for the rest of the networking part
Verify that you can run Python3 and all the requird modules. If you can type the following into your command line in the same directory as this file and get a positive feedback message, you are good to go.

	python3 test.py

If you need to install python then follow this guide: https://realpython.com/installing-python/

Mostly we are just going to use standard libraries for Python3, but you may need to install PyYAML if you get a "No module named 'yaml'" error. You can do so with pip, the main python package manager which should come bundled with your python3 install. On some linux distributions it does not, in which case you should run:

	sudo apt install python3-pip

Once you have pip you can run the following:

	python3 -m pip install pyyaml

# Converting network communications
Complete the tasks in the src/conversion.c file. Here you will need to convert between different endianness's. Have a look at ( https://linux.die.net/man/3/htonl ) for some useful functions. Also note the functions added in the endian.h file.