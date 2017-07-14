#!/usr/bin/python

import turtle

RIGHTANGLE = 90

def drawTriangle(points, color, insTurtle):
    insTurtle.fillcolor(color)
    insTurtle.up()
    insTurtle.goto(points[0][0],points[0][1])
    insTurtle.down()
    insTurtle.begin_fill()
    insTurtle.goto(points[1][0],points[1][1])
    insTurtle.goto(points[2][0],points[2][1])
    insTurtle.goto(points[0][0],points[0][1])
    insTurtle.end_fill()

def getMid(p1, p2):
    return ((p1[0]+p2[0]) / 2, (p1[1] + p2[1]) / 2)

def sierpinski(points,degree,insTurtle):
    colormap = ['blue','red','green','white','yellow',
                'violet','orange']
    drawTriangle(points, colormap[degree], insTurtle)
    if degree > 0:
        sierpinski([points[0],
                        getMid(points[0], points[1]),
                        getMid(points[0], points[2])],
                   degree-1, insTurtle)
        sierpinski([points[1],
                        getMid(points[0], points[1]),
                        getMid(points[1], points[2])],
                   degree-1, insTurtle)
        sierpinski([points[2],
                        getMid(points[2], points[1]),
                        getMid(points[0], points[2])],
                   degree-1, insTurtle)

if __name__ == '__main__':
    myTurtle = turtle.Turtle()
    myWin = turtle.Screen()

    myPoints = [[-200,-100], [0,200], [200,-100]]
    sierpinski(myPoints, 3, myTurtle)

    myWin.exitonclick()