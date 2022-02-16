
def rec(digit, keypad, output, ans, index):

    if index >= len(digit):
        ans.append(output)
        return

    number = digit[index]   # number = 0, 1, 2 .. in digits
    value = keypad[number]  # abc, def ....

    for i in range(len(value)):
        output += value[i]
        rec(digit, keypad, output, ans, index + 1)
        output = output[:-1]

    return ans


ans = []
letter_list = []
keypad = {"0" : "", "1" : "", "2": "abc", "3": "def", "4": "ghi", "5": "jkl", "6": "mno",
          "7": "pqrs", "8": "tuv", "9": "wxyz"}

digits = input()
output = ""
index = 0
print(rec(digits, keypad, output, ans, index))
