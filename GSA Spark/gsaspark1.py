# GSA Spark question 1 - sum between 1 and n
# There is a closed formula for this summation - (n*(n+1)) / 2

n = 1234567890 # upper bound, inclusive
# avoid floating point error using integer division instead of float division
sum = (n*(n+1)) // 2
print(int(sum))