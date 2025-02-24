import re
while True :
    number = input("Number : ")
    if (bool(re.fullmatch(r"\d+", number)) == True):
        break
    print("INVALID")

card_number_length = len(str(number))
first_two_digits = int(number[:2])

digits_list = [int(d) for d in number][::-1]

sum_even = 0
sum_multiplied_odd = 0

for i in range(len(digits_list)):
    if i % 2 == 1:
        x = digits_list[i] * 2
        sum_multiplied_odd += ((x % 10) + (x // 10))
    else:
        sum_even += digits_list[i]


checksum = sum_even + sum_multiplied_odd
last_digit_checksum = checksum % 10

if checksum % 10 == 0:

    if((first_two_digits == 34 or first_two_digits == 37) and card_number_length == 15):
        print("AMEX")
    elif((first_two_digits == 51 or first_two_digits == 52 or first_two_digits == 53 or first_two_digits == 54 or first_two_digits == 55) and card_number_length == 16):
        print("MASTERCARD")
    elif(int(number[:1]) == 4 and (card_number_length == 13 or card_number_length ==16)):
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")
