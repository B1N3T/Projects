def decrypt_ceaser(shift,final_message):
    decrypted = []
    final_decrypted = []
    
    for number in final_message:
        decrypted.append(ord(number) - 96)

    for value in decrypted:
        value = value - shift
        if value <= 0:
            value = value + 26
        final_decrypted.append(chr(value + 96))
    
    final_decrypted = ''.join(final_decrypted)
    final_decrypted = final_decrypted.replace(':',' ')
    final_decrypted = final_decrypted.replace('H','.')
    return(final_decrypted)