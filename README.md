# pic24-mdb-sniff
Sniffing 9-bit Multi Drop Bus commands on PIC24

By Beep Technologies Pte Ltd
- hello@beepbeep.tech
- https://www.beepbeep.tech

What is this
======
MDB (Multi Drop Bus) Protocol is a popular protocol vending machines to communicate with their peripherals (e.g: Coin, Bill and Card devices) (https://www.ccv.eu/wp-content/uploads/2018/05/mdb_interface_specification.pdf)
This code enables one to analyze the incoming data from the 9 bit serial channel


How is this different from other "sniffers"?
=====
As the MDB Protocol regretfully lacks a reliable SOH/ETX method, most implementations work by performing a checksum on the incoming bytes to differenciate incoming payloads. There might be scenarios where the checksum is equal to an incoming byte, leading to truncation of data.

We use a time-based logic which measures the inter-byte interval to reliably differenciate commands, and use a more advanced version of this code in our commercial MDB solutions for implementing the 10H and 60H cashless device.
