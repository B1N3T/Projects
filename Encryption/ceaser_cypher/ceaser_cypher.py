import encrypt
import decrypt

new_entry = input("Enter Message: ")

shift,scrambled_message = encrypt.encrypt_ceaser(new_entry.lower())
print(shift,scrambled_message)

decision = input("Would you like to see the message?[y/n]")
final_message = decrypt.decrypt_ceaser(shift,scrambled_message)

if decision == 'y' or 'Y':
    print(final_message)