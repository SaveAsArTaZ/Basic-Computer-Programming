#جا به جایی یکان و دهگان
#Mohammad Hossein Rangraz


if __name__ == '__main__':
    x = list(input())
    x[len(x)-1],x[len(x)-2] = x[len(x)-2],x[len(x)-1]
    y = ""
    for i in x:
        y += i
    print(y)