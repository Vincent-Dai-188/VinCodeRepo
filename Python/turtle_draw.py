#!/usr/bin/python

import turtle
#import time

RIGHTANGLE = 90

def drawSpiral(insTurtle, lineLen):
    if lineLen > 0:
        insTurtle.forward(lineLen)
        insTurtle.right(RIGHTANGLE)
        drawSpiral(insTurtle, lineLen-10)

def drawTree(branchLen, insTurtle):
    if branchLen > 5:
        insTurtle.forward(branchLen)
        insTurtle.right(20)
        drawTree(branchLen-15, insTurtle)
        insTurtle.left(40)
        drawTree(branchLen-15, insTurtle)
        insTurtle.right(20)
        insTurtle.backward(branchLen)

if __name__ == '__main__':
    myTurtle = turtle.Turtle()
    myWin = turtle.Screen()

    myWin.setup(width=500, height=500, startx=0, starty=0)
    myTurtle.setpos(-100, 100)
    drawSpiral(myTurtle,200)
    
    myTurtle.left(90)
    myTurtle.up()
    myTurtle.backward(100)
    myTurtle.down()
    myTurtle.color("green")
    myTurtle.pensize(3)
 
    drawTree(75, myTurtle)
    
    #time.sleep(3)
    #myWin.bye()

    myWin.exitonclick()
