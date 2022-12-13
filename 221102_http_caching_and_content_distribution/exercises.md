# Exercises for CN, Application layer

## Exercises from Chapter 2 of Kurose and Ross on "Application Layer"

Review questions

* R3
Client er den der sender forespørgsler, serveren besvare forespørgelser og acceptere forbindelsen 
* R4
Når vi sender en besked i P2P er der altid en der sender og en der modtager, hvilket er synonymt med client og server
* R5
Der er brug for en socket (ipadresse:port) til modtageren
* R10
Før der kan sendes beskeder skal en forbindelse godkendes, en såkaldt "TCP Connection"
* R12
Brugerens egen data
* R15
HTTP beskeder skal være i ASCII, den første linje er en request line og de efterfølgende er kaldt for header line . SMTP begrænser alle beskeder sendt vha. af protokollen til 7-bit ascii

Problems

* P1
False, the objects are sent back-to-back over the same connection
True
False, one request one response in case of non-persistent connections
False, it indicates the time and date when the response HTTP response was created and sent
False, they can have if the POST method is used


* P4
/cs453/
HTTP/1.1
Consistent, since the protocol uses that as default
gai.a.cs.umass.edu
Mozilla, there can be different version of the website depending on the user-agent, fx mobile users gets another response
* P5
Yes it was (200 ok)
Sat, 10 dec 2005 18:27:48
3874
<!doc
* P10
In the non-persistent case the different object would sequentially block each other and create a bottleneck, in the persitent version the objects can be divided into frames that can be sent simultaneously and their would be less time spent on handshaking since everything can be done over one tcp connection.

## Programming
Browse the complete HTTP RFC and convince yourself that it is too long to read entirely. It can be found here: https://www.rfc-editor.org/rfc/rfc2616

Now create a simple, HTTP complient request client. It must be capable of sending GET or HEAD requests and only needs to send the Request-Line (section 5.1 of the RFC) with no accompanying message-body or headers. Send your messages to the non-replying server for feedback on if you've done it correctly. 

Optionally, send your request to the replying server to parse and print the response in C. In either case you should assemble your requests in C and parse and response to be printed. Do not simply input one long string to create a request, actually take the different parts (e.g. the method, request-uri and http-version) and join them together to form the request. Similarly, do not just print the entirety of the feedback but identify the seperate parts. Python clients have also been provided as inspiration and a guide, though do remember that just because some logic works in python does not mean it is a good idea to directly copy to C.
