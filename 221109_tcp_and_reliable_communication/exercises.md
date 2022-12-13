# Exercises for TCP

## Exercises from Chapter 3 of Kurose and Ross on "Transport Layer"

* P14
In a NAK only protocol, the loss of packet x is only detected by the receiver when packet
x+1 is received. That is, the receivers receives x-1 and then x+1, only when x+1 is
received does the receiver realize that x was missed. If there is a long delay between the
transmission of x and the transmission of x+1, then it will be a long time until x can be
recovered, under a NAK only protocol.

If errors are rare then the network wouldn't have to wait for ACK all the time, which would make the network quicker since it reduces the time to wait for feedback. 
* P15
First im calculating the transmission time:
trans = (8*1500)/10^9 = 0.000012
If we pipeline 30 packets then we can sent the 31'th packet after having recieved the first ACK:
0.000012+RTT = 0.000012+30msec = 0.030012sec
Then we need to solve the following:
(x*0.000012)/0.030012 = 98, x = 245098.0000
The window size needs to be larger than 245098 for the channel utilization to be greather than 98 percent

* P27
After the second segment, host A has sent 126+80 = 206, and thus the sequence number will be 206+1, the destination host and port number will just be the same.
If the first segment is recieved from host B for bytes  127 and through 206, then the sequence number will be 126+80+1 = 207
Then the sequence number will still be 127 since it is still waiting for first segment with 80 bytes to be recieved
Host A	 	  Host B
send pk1
send pk2	rcv pk1
     		rcv pk2

		send ack1
	failed
timeout
		send ack2

timeout stop
send pk1
rcv ack2

* P36

* P37
a)
GBN:
In GBN it would send packets 3 4 and 5 two times, since packet 2 causes a timeout and they were sent afterwards, therefore will host a have sent 9 packets in total including the retransmitted packet 2.
B sends 8 ACKs. There are 4 ACKS with sequence number 1 since the ACKS after the packet loss will just respond with the ordered sequence of packets it has read, and 4 ACKS with sequence numbers 2, 3, 4, and 5, which is the normal order after the timeout.
SR:
In SR packets 3 4 and 5 would just be buffered and packet 2 would be the only packets that would be retransmitted therefore 6 packets.
Sequence numbers: 1, 3, 4, 5, 2
TCP:
The same for TCP: 6 packets
Note that TCP always send an ACK with expected sequence
number.
## Programming Task	
Build your own timeout function for sending a single byte message and expecting a single byte reply. A Python server has been provided that will artificially take ages half the time. Create a C client that can handle this, such that it detects the timeout within a few seconds rather than waiting for the message to be handled.