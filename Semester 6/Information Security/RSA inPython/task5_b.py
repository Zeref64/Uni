#!/usr/bin/python3
import math
def main():
    M = b"Please transfer me $2000.Alice."   #plain text into bytes
    S = 0xDB3F7CDB93483FC1E70E4EACA650E3C6505A3E5F49EA6EDF3E95E9A7C6C7A320 #signature
    e = 0x010001 #public key 1
    n = 0xDCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5 #p * q

    validation_S = pow(S, e, n) # Decyphering the signature using the public key
    plaintextInt = int.from_bytes(M, byteorder = "big") #Normally this is supposed to be a hash
    # This is the same from the previous task
    print ("Is the signature valid? ", validation_S == plaintextInt) #Validation process

if __name__ == "__main__":
    main()