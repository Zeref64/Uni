#!/usr/bin/python3
import math
def main():

    #Public Key 
    N = 0xC14BB3654770BCDD4F58DBEC9CEDC366E51F311354AD4A66461F2C0AEC6407E52EDCDCB90A20EDDFE3C4D09E9AA97A1D8288E51156DB1E9F58C251E72C340D2ED292E156CBF1795FB3BB87CA25037B9A52416610604F571349F0E8376783DFE7D34B674C2251A6DF0E9910ED57517426E27DC7CA622E131B7F238825536FC13458008B84FFF8BEA75849227B96ADA2889B15BCA07CDFE951A8D5B0ED37E236B4824B62B5499AECC767D6E33EF5E3D6125E44F1BF71427D58840380B18101FAF9CA32BBB48E278727C52B74D4A8D697DEC364F9CACE53A256BC78178E490329AEFB494FA415B9CEF25C19576D6B79A72BA2272013B5D03D40D321300793EA99F5
    e = 0x10001 #65537

    #Signature from openssl
    S = 0xaa9fbe5d911bade44e4ecc8f07644435b4ad3b133fc129d8b4abf3425149463bd6cf1e4183e10b572f83697965076f59038c51948918103e1e5cedba3d8e4f1a1492d32bffd498cba7930ebcb71b93a4424246d9e5b11a6b682a9b2e48a92f1d2ab0e3f820945481502eeed7e0207a7b2e67fbfad817a45bdcca0062ef23af7a58f07a740cbd4d43f18c0287dce3ae09d2f7fa373cd24bab04e543a5d255110e41875f38a8e57a5e4c46b8b6fa3fc34bcd4035ffe0a471740ac1208be3544784d518bd519b405ddd423012d13aa5639aaf9008d61bd1710b067190ebaeadafba5fc7db6b1e78a2b4d10623a763f3b543fa568c50177b1c1b4e106b220e845294
    # SHA256 hash that is used to create the Signature 'S'
    hash = 0x7061df0a50b8f2ba3367ecfabab273a16f3bb1378dbe1fe524e6dfd90dfa3b91
    #For the validation of the signature I'm decyphering the signature using the public key
    validation_S = pow(S, e, N)
    #Now that i got the validation hash i'm going to compare it with the hash i got from openssl 
    print ("Validation Hash in Hex = ", hex(validation_S))
    print ("Hash in Hex  = " , hex(hash))
    #In the result screen is is visible that the validation hash contains the hash
    #That tells us that the signature is indeed valid.

if __name__ == "__main__":
    main()