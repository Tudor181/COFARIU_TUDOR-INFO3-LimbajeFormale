import basic

while True:
    text = input("basic > ")
    result, error = basic.run(file_name="<stdin>", text=text)

    if error:
        print(error.as_string())
    else:
        print(result)
