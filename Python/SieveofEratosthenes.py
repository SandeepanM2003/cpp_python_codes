import time
def solver(number):
	start = time.process_time()
	numbers = [2]
	for i in range(3,number+1,2):
		numbers.append(i)
	numbers.sort()  
	for a in numbers:
		for b in numbers:
			if b % a == 0:
				numbers.remove(b)
		numbers.append(a)
	numbers.sort()
	print(numbers)
	print("Time Taken by the Script:"+ str(time.process_time() - start) +" seconds")
solver(101)
