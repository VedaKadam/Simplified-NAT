NAME: VEDA SHYAM KADAM
EMAIL: vedaskadam@gmail.com


This is a simplified NAT consisting of 3 files:
main.cpp
NAT.txt
FLOW.txt

I tested my solution on the basis of test NAT and test FLOW files uploaded on my repository.

I copied contents of the files into a vector so as to save time in fectching from memory. 
For larger datasets this can be changed depending on the need of space or time optimization.
I have considered time optimization.

I first solved it using brute-force solution i.e. comparing each flow with each entry of NAT untill I get a match.
This made the time complexity of my solution to be O(m*n), where m is no. of enteries in flow table and n is no. of enteries in NAT table

To lower this time complexity, I used map for data from NAT file.
Key to this map was input IP-port pair in NAT and value was output IP-port.
The search run time for map is log n.

Hence the time complexity of my solution is O(m*log n)

Some minor improvements I would have included with more time would be to test data on heavy/large datasets and possibly order the input file items to find a better match rate.
