#!/usr/bin/python3
import math
def main():

    n = 0xDCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5 # p * q
    e = 0x010001 # Part of public key

    d = 0x74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D # Private key
    C = 0xCAF7D72776AFEFBAC8269E1A8B76CE44A3B28015CA9A54E22C239EF38FCFAFFA # Cypher text

    m = int(bytes("Vasilhs Koumanhs", 'utf-8').hex(), 16)   # Plain text
    m2 = int(bytes("Vosilhs Koumanhs", 'utf-8').hex(), 16)  # Corrupted plain text, changed 1 letter
    
    # Turning the message into: bytes > hex > integer
    s = hex(pow(m,d,n)) #Signing the message with the private key 
    s2 = hex(pow(m2,d,n)) #This is the signature for the corrupted message.

    print ("Original signature m: {}".format(s)) 
    print ("Changed signature m2: {}".format(s2)) 
    # The difference is huge while only 1 letter has changed
if __name__ == "__main__":
    main()