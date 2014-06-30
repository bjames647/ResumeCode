#!/usr/bin/python
import sys
import os
import pygame
from pygame.locals import *


pygame.init()

screen = pygame.display.set_mode((640, 480))
clock = pygame.time.Clock()


player = pygame.image.load("guy1.png")
background = pygame.image.load('bg.png')
buildingOne = pygame.image.load('buildingone.png')
#############################################
red = (255,0,0)								#
green = (0,255,0)							#
blue = (0,0,255)							# Colors
darkBlue = (0,0,128)						#
white = (255,255,255)						#
black = (0,0,0)								#
gray =(128, 128, 128)						#
#############################################					

bOneCoordx = 100
bOneCoordy = 100

class playerSprite(pygame.sprite.Sprite):
	def __init__(self):
		pygame.sprite.Sprite.__init__(self)
		self.image = pygame.image.load("guy1.png")
		self.rect = self.image.get_rect()

class buildingOneSprite(pygame.sprite.Sprite):
	def __init__(self):
		pygame.sprite.Sprite.__init__(self)
		self.image = pygame.image.load("buildingone.png")
		self.rect = self.image.get_rect()			

		
playerSpriteNotClass = playerSprite()
buildingOneSprite = buildingOneSprite()


sprites = pygame.sprite.Group()
sprites.add(playerSpriteNotClass)
sprites.add(buildingOneSprite)


xspeed = 0
yspeed = 0
xcoord = 0
ycoord = 0


while True:
	clock.tick(60)
	
	screen.fill(white)
	
	x,y = pygame.mouse.get_pos()
	
	screen.blit(background, (0,0))
	screen.blit(player, (xcoord, ycoord))
	screen.blit(buildingOne, (100, 100))

	if pygame.sprite.collide_rect(playerSpriteNotClass, buildingOneSprite) == False:
		xspeed = 0
		yspeed = 0
		
	for event in pygame.event.get():
		if event.type == pygame.KEYDOWN:
			if event.key == pygame.K_a:
				xspeed = -1.5
			if event.key == pygame.K_d:
				xspeed = 1.5
			if event.key == pygame.K_w:
				yspeed = -1.5
			if event.key == pygame.K_s:
				yspeed = 1.5

		if event.type == pygame.KEYUP:
			if event.key == pygame.K_a:
				xspeed = 0
			if event.key == pygame.K_d:
				xspeed = 0
			if event.key == pygame.K_w:
				yspeed = 0
			if event.key == pygame.K_s:
				yspeed = 0



		if event.type == QUIT:
			pygame.quit()
			sys.ext()
	
	xcoord += xspeed
	ycoord += yspeed

	
	
	pygame.display.update()