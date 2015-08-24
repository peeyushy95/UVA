#AUTHOR  : Peeyush Yadav

while 1 :
    n = int(raw_input())
    result = n
    if n == 0 :
        break

    i = 2

    while i*i <= n :
        if n%i == 0:
            while n%i == 0 :
                n/=i
            result = result - result/i
        i=i+1
    if n > 1 :
        result = result - result/n
    print result
