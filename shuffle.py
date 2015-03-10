import csv
import Queue
import collections
import string

q = collections.deque()

infile = open('shuffle_cards.csv', 'r')
outfile = open('shuffle_cards_index.csv', 'w')
firstLine = infile.readline()
outfile.write(firstLine)


cards = firstLine.split(',')
for card in cards:
	q.append(card)

# Rewind really
infile = open('shuffle_cards.csv', 'r')

deck = []
reader = csv.reader(infile)
writer = csv.writer(outfile)

for row in reader:
	for qitem in q:
		if qitem in row:
			deck.append(row.index(qitem))
	writer.writerow(deck)
	deck = []


			
		
	
	