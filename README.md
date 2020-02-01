# pic24-mdb-sniff
Sniffing 9-bit Multi Drop Bus commands on PIC24

By Beep Technologies Pte Ltd
- hello@beepbeep.tech
- https://www.beepbeep.tech

What is this
======
MDB (Multi Drop Bus) Protocol is a popular protocol for American & European vending machines to communicate with their peripherals (e.g: Coin, Bill and Card devices) 
- https://www.ccv.eu/wp-content/uploads/2018/05/mdb_interface_specification.pdf
- This code enables one to analyze the incoming data from the 9 bit serial channel for debugging purposes


How is this different from other "sniffers"?
=====
As the MDB Protocol regretfully lacks a reliable SOH/ETX method, most implementations work by performing a checksum on the incoming bytes to differenciate incoming payloads. There might be scenarios where the checksum is equal to an incoming byte, leading to truncation of data.

We use a time-based logic which measures the inter-byte interval to reliably differenciate commands.
In fact we use a more advanced version of this code in our commercial MDB/VCCS+JVMA (yes, the pesky Japanese protocol) solutions for implementing the 10H and 60H cashless device.

The MDB Sniffer approach is also useful in obtaining data from the coin/cash peripherals by implementing the CASH SALE protocol.

Why on earth do you use Microchip PIC in 2019??
=====
- It is a good learning experience (especially for students who previously only dealt with Arduino)
- It has a pretty good IDE 
- The Japanese use it in their vending machine equipment 
- It cannot be easily reverse engineered (Search 抄板解密打样 “Copy board, rip firmware & make a prototype” on Taobao)

Hi guys, can you share more about VCCS/JVMA please?? :))
=====
Reverse engineering is an epic (and costly) journey to the center of one’s soul.

Drop us a note at hello@beepbeep.tech

License
=====
This is released under the Mozilla Public License 2.0
