..\_\_FOREST WARS\_\_..
===
Author: Christeen T Jose
---
### Project demonstration can be viewed from [YouTube](https://youtu.be/zj5-134iEjQ)


---
> *“Forest wars is a 2019 strategic; maze based multiplayer game developed using the 
double sided stack data structure and hashing algorithms as a tribute to the video game developers 
of the golden era and has been implemented in the C language."*

---
**T**he game has been developed in a manner similar to those of arcade games created during the golden era of 1970’s 
that paved way for modern gaming technology until the video game crash of 1983. The video game crash of 1983, 
also known as the Atari shock in Japan was a large scale recession in the video game industry that occurred from 1983 to 1985, 
primarily in North America, which abruptly ended the second generation of console video gaming, and led to the 
bankruptcy of several video game production companies. The introduction of home gaming systems and a shift in interest 
towards personal computers were factors that contributed to the recession.
The game is a tribute to those developers of the golden era.


The basic layout for the game is shown below:

![](https://github.com/ChristeenTJose/Forest-Wars-a-C-game/blob/master/Images/Layout.jpg)

---
### Note to users:

**The game will be running in DOS shell using a turbo C++ compiler as certain features have been removed from the 
standard ANSI C version in most modern compilers.** 

---
### RULES:

In the game each player will receive two lives, which will be indicated by a heart symbol. 
The game will be over when either of the players has lost both of his/her lives. 
The player that still has at least one of his/her lives remaining is declared to have won the game. 
When the game begins each player will be allotted a random site in the forest. 
From those sites he/she can make his/her move towards his/her left, right, top, and bottom or even 
get to use his special powers (limited). Each player will get to make his/her choice alternatively 
starting with player 1. When a player makes a movement towards his/her adjacent site a tree will 
be planted in the previous site. A player will lose his/her life if he/she gets cornered on all four sides. 
When a player loses a life, all the trees he/she has planted will also be lost (popped). 

### DOUBLE-SIDED STACK:
The game works on the principle of coordinate systems and the technology behind its implementation is a “double-sided stack”, 
used to store coordinates of players and their trees. 

The choice of a “double-sided stack” in place of two stacks each of the same size as required by the program in the 
worst case scenario where one player manages to fill almost completely the grid or forest was to ensure efficient management of memory. 

[As a site occupied by player1 cannot be occupied by player 2 (mutually exclusive), 
a lot of memory will go unused in the case of two separate stacks.  There are a total of 406 sites in the forest or grid.]

![](https://github.com/ChristeenTJose/Forest-Wars-a-C-game/blob/master/Images/Double-sided-stack.jpg)

The stacks are used to store the indices of sites that have been planted by each player with the last one inserted being popped first
when the player loses a life. The index of each site is calculated from its x and y coordinates using the hash function.

### Hash function:
**Index=(i-4)\*14+(j-5)**

Where ‘i’ is x-coordinate and ‘j’ is y coordinate.

(4, 5) is the upper left corner boundary coordinate of the 14x29 matrix. 

![](https://github.com/ChristeenTJose/Forest-Wars-a-C-game/blob/master/Images/Coordinates.png)

The hash function defines a unique index to each site in the grid which varies from 0 to 405.

The hash function helps to achieve insertion (pushing), deletion (popping) and searching with a complexity of order O(1).

---
### SIMULATION:

![](https://github.com/ChristeenTJose/Forest-Wars-a-C-game/blob/master/Images/Simulation1.png)

![](https://github.com/ChristeenTJose/Forest-Wars-a-C-game/blob/master/Images/Simulation2.png)

![](https://github.com/ChristeenTJose/Forest-Wars-a-C-game/blob/master/Images/Simulation3.png)

![](https://github.com/ChristeenTJose/Forest-Wars-a-C-game/blob/master/Images/Simulation4.png)

![](https://github.com/ChristeenTJose/Forest-Wars-a-C-game/blob/master/Images/Simulation5.png)


