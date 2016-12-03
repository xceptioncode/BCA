#-------------------------------------------------------------------------------
# Name:        Assignment 5
# Purpose:     Affine Cipher Encryption and Decryption
#
# Author:      Shubham Raj
#
# Created:     11-09-2016
# Copyright:   (c) X 2016
# Licence:     <your licence>
#-------------------------------------------------------------------------------

import string
from affine_cipher import encrypt, decrypt

def main():
    try:
        choice = int(raw_input("\n\t\t\t#Afiine Cipher Program#\n\nChoose an option: \n1. Encryption \n2. Decryption\n\nEnter your choice: "))


        key1 = int(raw_input("Enter key1 value: "))
        key2 = int(raw_input("Enter key2 value: "))
        info = {
        1: "Enter plan text to encrypt: ",
        2: "Enter cipher text to decrypt: "
        }

        try:
            data = raw_input(info[choice])
        except Exception as e:
            print "Please select correct option."
            exit()

        options = {
        1: encrypt,
        2: decrypt}

        error = {
        1: "I am only designed to encrypt alphabets.",
        2: "I am only designed to decrypt alphabets."}

        result = {
        1: "\n[+] Enrypted text: ",
        2: "\n[+] Decrypted text: "}

        chars_to_remove = ['.', '!', '?', '\x91', '\x96', "'", '"', '?', '-', ',', '?', '\n', '\x92', '\x93', '\x94', '\x85', '(', ')', ':', ';', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
        data = data.translate(None, ''.join(chars_to_remove))
        if len(data) == 0:
            print error[choice]
        else:
            print result[choice] + options[choice](data, key1, key2)

    except Exception as KeyboardInterrupt:
        print "Process Interrupted .. Exiting"
        exit()


if __name__ == '__main__':
    main()