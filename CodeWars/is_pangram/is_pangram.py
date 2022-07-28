def is_pangram(s):
    word_list = s
    char = ''
    sentence = ''
    lowercase = ''
    x = 1
    y = 0
    
    #remove spaces and turn all letters lowercase
    for words in word_list:
        sentence += words   
    for letter in sentence:
        lowercase += letter.lower()
    
    #check if letters are present and increment x by one if letter is found
    char_set = set(lowercase)
    for char in char_set:
        if ord(char) in range(ord('a'), ord('z')):
            x += 1
    
    #check if pangram or not
    if x == 26:
        y = True
    else:
        y = False
        
    return(y)