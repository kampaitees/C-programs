import pygame
import time

pygame.init()

display_width = 1000
display_height = 800

black = (0, 0, 0)
white = (255, 255, 255)

red = (255, 0, 0)
blue = (0, 0, 255)
green = (0, 255, 0)

gameDisplay = pygame.display.set_mode((display_width,display_height))
pygame.display.set_caption("Learning Pygame")

initial = False

lead_x = display_width // 2
lead_y = display_height // 2

x_change = 0
y_change = 0

FPS = 30

block_size = 10
clock = pygame.time.Clock()

font = pygame.font.Font(None, 50)

def mess_to_screen(text, color):
	screen_text = font.render(text, True, color)
	gameDisplay.blit(screen_text,[display_width // 2 - 135, display_height // 2 - 100])
	
	
while not initial:
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			initial = True
		if event.type == pygame.KEYDOWN:
			if event.key == pygame.K_LEFT:
				x_change = -block_size
				y_change = 0
			elif event.key == pygame.K_RIGHT:
				x_change = block_size
				y_change = 0
			elif event.key == pygame.K_UP:
				x_change = 0
				y_change = -block_size
			elif event.key == pygame.K_DOWN:
				x_change = 0
				y_change = block_size
		if  event.type == pygame.KEYUP:
			if  event.key == pygame.K_LEFT  or   event.key == pygame.K_RIGHT:
				x_change = 0
				y_change = 0
									
	if lead_x >= display_width or lead_x < 0 or lead_y >= display_height or lead_y < 0:
		initial = True
				
	lead_x += x_change
	lead_y += y_change
				
	gameDisplay.fill(blue)
	
	pygame.draw.rect(gameDisplay, green, [lead_x,lead_y,block_size,block_size])
	
	pygame.display.update()
	
	
	clock.tick(FPS)
	
mess_to_screen("You lost, fucking loser!", red)
pygame.display.update()
time.sleep(2)

pygame.quit()
quit()


