#-------------------------------------------------------------------------------
# Name:        Affine Cipher
# Purpose:     Module for Affine Cipher (encryption, decryption)
#
# Author:      Shubham Raj
#
# Created:     11-09-2016
# Copyright:   (c) X 2016
# Licence:     MIT
#-------------------------------------------------------------------------------
import string

def gcd(a, b):
    rem = a%b
    while (rem != 0):
        a = b
        b = rem
        rem = a%b
    return b

def mod_inverse(a, m):
    a = a%m
    for x in range(1, m):
        if ((a*x)%m == 1):
            return x

def encrypt(data, key1, key2):
    if gcd(key1, 26) == 1:
        data = data.lower().split()
        encrypted_data = []
        for small_data in data:
            num_data = [ord(x) - 97 for x in small_data]
            #print num_data
            num_enc = [(key1*x + key2) % 26 for x in num_data]
            #print num_enc
            encrypted_small_data = [chr(x+97) for x in num_enc]
            encrypted_small_data = ''.join(encrypted_small_data).replace('`', 'z')
            encrypted_data.append(encrypted_small_data)
        encrypted_data = ' '.join(encrypted_data)
        return encrypted_data.upper()
    else:
        print "(%d and 26) must be a co-prime" % key1
        return "Exiting .."

def decrypt(cipher, key1, key2):
    if gcd(key1, 26) != 1:
        print "(%d and 26) is not a co-prime. Inverse doesn't exist" %key1
        return "Exiting .."
    else:
        cipher = cipher.lower().split()
        decrypted_data =[]
        for small_cipher in cipher:
            num_cipher = [ord(x) - 97 for x in small_cipher]
            num_dec = [(mod_inverse(key1, 26) * (x - key2)) % 26 for x in num_cipher]
            decrypted_small_data = [chr(x+97) for x in num_dec]
            decrypted_small_data = ''.join(decrypted_small_data)
            decrypted_data.append(decrypted_small_data)
        decrypted_data = ' '.join(decrypted_data)
        return decrypted_data.upper()

def main():
    print "To be used as module only, \nPlease import this module into your program to use"
    #print decrypt("IHHWVCSWFRCP", 5, 8)
    #print mod_inverse(5, 26)

if __name__ == '__main__':
    main()
