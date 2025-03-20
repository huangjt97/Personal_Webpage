from sympy import isprime, primerange, prime

# Check if a number is prime
print(isprime(17))  # True

# Get prime numbers in a range
list(primerange(1, 20))  # [2, 3, 5, 7, 11, 13, 17, 19]

# Get nth prime number
print(prime(5))  # 11