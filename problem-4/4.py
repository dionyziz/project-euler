def is_palindrome(s):
    return str(s)[::-1] == str(s)

products = [i * j for i in range(100, 999) for j in range(100, 999)]
print max(filter(is_palindrome, products))
