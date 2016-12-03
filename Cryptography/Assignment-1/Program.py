#-------------------------------------------------------------------------------
# Name:        Assignment-1
# Purpose:     Count Frequencies Of Letters & Generate Graph
#
# Author:      Shubham Raj
#
# Created:     17-08-2016
# Copyright:   (c) X 2016
# Licence:     MIT
#-------------------------------------------------------------------------------

from collections import Counter, OrderedDict
import string
import matplotlib.pyplot as plt

fname = raw_input("\n[=] Please enter the file name: ")
read_file = open(fname).read()
length = len(read_file)
print "[+] Length of the file is : ", length

chars_to_remove = ['.', '!', '?',' ', '\x91', '\x96', "'", '"', '?', '-', ',', '?', '?', '\n', '\x92', '\x93', '\x94', '\x85', '(', ')', ':', ';', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
read_file = read_file.translate(None, ''.join(chars_to_remove))

print "[+] After removing all symbols and white spaces, Length is : " + str(len(read_file)) + "\n"

read_file = read_file.lower()

c = Counter(read_file)

alphabets = list(string.lowercase)
L = []
alpha_percentage = {}
for letters in alphabets:
	val = c[letters]
	per = round((val/float(length))*100, 3)
	L.append(per)
	print "Frequency of " + letters + " is: " + str(val) + " - ", str(per)
	alpha_percentage[letters] = per

try:
	alpha_percentage = OrderedDict(sorted(alpha_percentage.items()))
	plt.figure(figsize=(18,7))
	rects = plt.bar(range(len(alpha_percentage)), alpha_percentage.values(), width=0.7, color='r', align='center', edgecolor='b')
	plt.xticks(range(len(alpha_percentage)), alpha_percentage.keys())
	plt.yticks(range(int(max(L)+3)))
	plt.title('Frequency Of Letters')
	plt.ylabel('Frequency')
	plt.xlabel('Letters')
	plt.grid()
	#rects = plt.patches
	for rect, label in zip(rects, alpha_percentage.values()):
		height = rect.get_height()
		#print height
		plt.text(rect.get_x() + rect.get_width()/2, height + 0.3, str(round(label, 2)), ha='center', va='bottom', color='blue', fontweight='bold')
		#print str(round(label, 2))
	#plt.show()
	plt.savefig("Graph.png", dpi=300, format='png', pad_inches=0.1)
	plt.show()
except KeyboardInterrupt as e:
	pass

