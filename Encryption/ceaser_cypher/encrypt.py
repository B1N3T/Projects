import random

def encrypt_ceaser(word):
    letter_place = []
    letter_shift = random.randint(1,25)
    final_message = []

    for number in word:
        letter_place.append(ord(number) - 96)

    for value in letter_place:
        value = value + letter_shift
        if value > 26:
            value = value - 26
        final_message.append(chr(value + 96))
    
    final_message = ''.join(final_message)
    return(letter_shift, final_message)