def is_valid_walk(walk):
    valid = False
    location_ns = 0
    location_ew = 0
    
    ns_dict ={
        'n' :  1,
        's' : -1,
        'e' : 0,
        'w' : 0
    }
    
    ew_dict ={
        'n' : 0,
        's' : 0,
        'e' : 1,
        'w' : -1
    }
    if len(walk) == 10:
        for direction in walk:
            print(location_ns)
            location_ns = location_ns + ns_dict[direction]
            location_ew = location_ew + ew_dict[direction]
            if location_ew == 0 and location_ns == 0:
                valid = True
            else:
                valid = False
    else:
        valid = False
        
    return(valid)