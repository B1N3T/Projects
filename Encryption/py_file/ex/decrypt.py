import os
from cryptography.fernet import Fernet

files = []

# Exceptions and encryption
for file in os.listdir():
    if file == "encrypt.py":
        continue
    if file == "key_file.key":
        continue
    if file == "decrypt.py":
        continue
    
    if os.path.isfile(file):
        files.append(file)

with open("key_file.key", "rb") as thekey:
    secretkey = thekey.read()

for file in files:
    with open(file,"rb") as thefile:
        contents = thefile.read()

    contents_decrypted = Fernet(secretkey).decrypt(contents)

    with open(file,"wb") as thefile:
        thefile.write(contents_decrypted)