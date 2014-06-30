#!/usr/bin/env python
from pdb import set_trace

grades = open("Grades - Sheet1.tsv")
gradestxt = grades.readlines()


class student():
	def gradeaverage(self):
		return sum(self.grades)/len(self.grades)
	def __init__(self, incommingname):
		self.name = incommingname
	def __str__(self):
		return(self.name)


studentlist = []
for line in gradestxt[1:]:
	person = student(line.strip().split("\t")[0])
	stringGrades = line.split()[1:]
	numberGrades = []
	for stringGrade in stringGrades:
		numberGrades.append(int(stringGrade))
	person.grades = numberGrades
	studentlist.append(person)

	

	
class room():
	studentlist = []
	def roomaverage(self):
		studentaverages = []
		for stud in self.studentlist:
			studentaverages.append(stud.gradeaverage())
		try:
			return sum(studentaverages)/len(studentaverages)
		except ZeroDivisionError:
			return("There are no students")
	def __init__(self, studentlist=[]):
		self.studentlist = studentlist

myroom = room(studentlist)
print myroom.roomaverage()
raw_input()
