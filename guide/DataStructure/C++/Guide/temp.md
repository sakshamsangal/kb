isEmptyCell()
    check for empty cell 
    empty found
        do workaround
    all are filled
        return true

    get the choices in which we can fill the cell
    do the safety test of the cell 
    pass = insert that choice 
        check for other cell 
    fail = make another choice 
    if all choice fail return false