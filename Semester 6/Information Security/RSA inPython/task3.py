#!/usr/bin/python3
import math
import codecs 

#Decypher a message
def main():

    n = 0xDCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5 #p* q
    e = 0x010001    # Part of public key
    d = 0x74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D # Private key
    C = 0xCAF7D72776AFEFBAC8269E1A8B76CE44A3B28015CA9A54E22C239EF38FCFAFFA  # Cyphered message

    m = codecs.decode(hex(pow(C, d, n))[2::] , "hex") #pow = decrypted C (int) to hex > ascii
    # Decyphering the message then converting from integer to hex 
    # and lastly removing the "0x" and lastly turning int into ASCII with codecs.
    # Basically the [2::] tells python to remove the first 2 characters (0x)
    # Codecs helps me to decode a hex and turn it into ASCII so I'm able to print that later

    print ("Decrypted C message = {}".format(m))    

if __name__ == "__main__":
    main()