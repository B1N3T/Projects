def solution(n):
    count = 0
    count2 = 0
    count3 = 0
    sol4_n = ''
    numeral = ''
    sol_n = ''
    symbol_dict = {
       1000:'M',
        500:'D',
        100:'C',
         50:'L',
         10:'X',
          5:'V',
          1:'I'
    }
    n_list = [1000, 500, 100,
        50, 10, 5, 1]
    
    for number in n_list:
        while n - number >= 0:    
            sol4_n = sol4_n + symbol_dict[number]
            n = n - number
            if sol4_n[-1] == 'X':
                count2 += 1
                if count2 == 4:        
                    count2 = 0
                    sol4_n = sol4_n[:-3]
                    sol4_n = sol4_n + 'L'
                    if sol4_n[-3:] == 'LXL':
                        sol4_n = sol4_n[:-3]
                        sol4_n = sol4_n + 'XC'
                    if sol4_n[-3:] == 'DXD':
                        sol4_n = sol4_n[:-3]
                        sol4_n = sol4_n + 'XM'
            if sol4_n[-1] == 'C':
                count3 += 1
                if count3 == 4:        
                    count3 = 0
                    sol4_n = sol4_n[:-3]
                    sol4_n = sol4_n + 'D'
                    if sol4_n[-3:] == 'DCD':
                        sol4_n = sol4_n[:-3]
                        sol4_n = sol4_n + 'CM'
            if sol4_n[-1] == 'I':
                count += 1
                if count == 4:        
                    count = 0
                    sol4_n = sol4_n[:-3]
                    sol4_n = sol4_n + 'V'
                    if sol4_n[-3:] == 'VIV':
                        sol4_n = sol4_n[:-3]
                        sol4_n = sol4_n + 'IX'
                    if sol4_n[-3:] == 'LIL':
                        sol4_n = sol4_n[:-3]
                        sol4_n = sol4_n + 'IC'
                    if sol4_n[-3:] == 'DID':
                        sol4_n = sol4_n[:-3]
                        sol4_n = sol4_n + 'IM'                    
        encoded = sol4_n
    
    return(encoded)