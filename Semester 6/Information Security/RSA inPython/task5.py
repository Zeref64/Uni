#!/usr/bin/python3
import math
def main():
    M =b"Launch a missile."  # Plain text in bytes
    n = 0xAE1CD4DC432798D933779FBD46C6E1247F0CF1233595113AA51B450F18116115  # p * q
    e = 0x010001    # Part of Public key
    S = 0x643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6802F  #Signed message (M)

    validation_S = pow(S, e, n) #"Decyphering" the signature with Bob's public key 
    plaintextInt = int.from_bytes(M, byteorder = "big") #Normally this is supposed to be a hash
    #I'm converting the plain text from bytes into an integer in Big Endian so I can compare later.
    print ("Is the signature valid? ", validation_S == plaintextInt)
    #Basically if the validation equals the integer from the hash then the Signature is valid.

    # Part 2
    #Changing the last byte of the signature into 3F from 2F
    corruptedSignature = 0x643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6803F 
    # Decyphering the signature again
    corruptedValidation = pow(corruptedSignature, e, n)
    print ("Is the corrupted signature valid? ", corruptedValidation == plaintextInt)
    # The signature was corrupted so the result is obviously false

if __name__ == "__main__":
    main()