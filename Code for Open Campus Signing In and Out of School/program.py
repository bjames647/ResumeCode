import time
import datetime

running = True

from pdb import set_trace as debug
direction = 0

peopleMap = {"647":"Brian James", "30":"Queen Mukami", "847":"Austin Lietz"}
directionMap = {0:"out", 1:"in"}
while running == True:

	LN = raw_input("Lunch Number: ")
	
	name = peopleMap.get(LN, None)
	if name:
		localtime = datetime.datetime.now().strftime("%a %b %d, %Y %I:%M %p")
		#print peopleMap.get(LN)
		f = open("{0}.txt".format(name), 'a')
		f.write( "{0} signed {1} on {2}\n".format(name, directionMap.get(direction), localtime) )
		f.close()
		direction = int(not direction)







