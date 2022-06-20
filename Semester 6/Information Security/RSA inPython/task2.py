#!/usr/bin/python3
import math
import codecs

# Cypher a message
def main():
    p = 0x953AAB9B3F23ED593FBDC690CA10E703
    q = 0xC34EFC7C4C2369164E953553CDF94945
    e = 0x0D88C3
    n = p * q          # Common modulus
    f = (p-1) * (q-1)
    d = pow(e, -1, f) # Generate Private key

    m = int(bytes("Vasilhs Koumanhs", 'utf-8').hex(), 16)   #Bytes to hex to int  
    # Converting the message to bytes then the bytes into hex and lastly the hex into int

    C = pow(m, e, n)    #Cypher text   
    M = hex(pow(C, d, n)) #Decypher the message 
    asciiMsg = codecs.decode(hex(pow(C, d, n))[2::] , "hex")

    print ("p = ", p)
    print ("q = ", q)
    print ("e = ", e)
    print ("Cypher text of name 'Vasilhs Koymanhs' is =  {}".format(hex(C)))
    print ("The original message in hex is: {}".format(asciiMsg))
    
if __name__ == "__main__":
    main()
