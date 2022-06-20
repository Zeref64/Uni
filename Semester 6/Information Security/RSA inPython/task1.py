#!/usr/bin/python3
import math 

# Generate Private Key

def main ():
    p = 0x953AAB9B3F23ED593FBDC690CA10E703  # Given values
    q = 0xC34EFC7C4C2369164E953553CDF94945
    e = 0x0D88C3

    n = p * q           # Common modulus
    f = (p-1) * (q-1)   # φ function (Oiler)
    # Calculating the Oiler function which is needed to calculate the private key
    d = pow(e, -1, f)   # Private Key, Modular inverse
    #calculating the private key 

    print ("p = ", p)
    print ("q = ", q)
    print ("e = ", e)
    print ("n = p * q: {}".format(hex(n)))
    print ("F = (p-1) * (q-1): {}".format(hex(f)))
    print ("d = e^-1 mod f {}".format(hex(f))) 
if __name__ == "__main__":
    main()