#Brian James
#


#!/usr/bin/python
import sys
import os
import pygame
from pygame.locals import *


pygame.init()

screen = pygame.display.set_mode((640, 480))
clock = pygame.time.Clock()

playerImage = pygame.image.load('player.png')

red = (255,0,0)								
green = (0,255,0)							
blue = (0,0,255)							
darkBlue = (0,0,128)						
white = (255,255,255)						
black = (0,0,0)								
gray =(128, 128, 128)

class playerSprite(pygame.sprite.Sprite):
	def __init__(self):
		pygame.sprite.Sprite.__init__(self)
		self.image = pygame.image.load('player.png')
		self.rect = self.image.get_rect()

class enemySprite(pygame.sprite.Sprite):
	def __init__(self):
		pygame.sprite.Sprite.__init__(self)
		self.image = pygame.Surface([32,32])
		self.image.fill(red)
		self.rect = self.image.get_rect()
		
		
		
player = playerSprite()
enemy = enemySprite()
sprites = pygame.sprite.Group()
sprites.add(player)
sprites.add(enemy)




pygame.mouse.set_visible(0)

xspeed = 0
yspeed = 0
xcoord = 0
ycoord = 0



while True:
	clock.tick(60)
	
	screen.fill(white)
	
	x,y = pygame.mouse.get_pos()
	
	screen.blit(playerImage, (x, y))
	

	
	
	for event in pygame.event.get():
		if event.type == pygame.KEYDOWN:
			if event.key == pygame.K_a:
				xspeed = -2			
			if event.key == pygame.K_d:
				xspeed = 2
			if event.key == pygame.K_w:
				yspeed = -2			
			if event.key == pygame.K_s:
				yspeed = 2
			
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