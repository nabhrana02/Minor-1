# Minor 1 

# Box’em up with OPENGL:
Our goal is to create a multiplayer game using Opengl that our generation has played a lot during our boring school days.  

Interface:
The first screen, the players will have when running the program will be a full menu. This menu will contain on the top left corner the name of the game. After that on the right side on the same level as the name will be a cube of points (only the points, not the vertices). This will be basically like our game logo. 
Below the name of the game will be a rectangular selection area with all the features we need the players to input. In the rectangular,
•	The first option will be for the player to choose the size of the grid to play in. The size will have 4 size options like 10*10, 14*14, 18*18 and 20*20.
•	Next will be the number of players playing in a single time. The maximum number of players will be 4.
•	 After that, there will be blanks the same number as the number of players where they can input their initials and choose a color to represent them.
All these options will have pre-determined answers on which a player can click to choose them. They only have to use the keyboard to enter the initial they want to use.
To the right of this rectangular will be a huge button with “START” on it. Clicking on this button will make the background white and get the game screen interface as the next screen the player sees.

Interface 2:
This is the second interface i.e. the actual game. On this, the left side of the window has a rectangular area with the grid of points specified by the player in the previous interface. These points in the grid are equally distanced from each other and there are lines/vertices connecting all the points with each other. These lines right now are very blurred and very faded.
On the right of the rectangular is another rectangular area which is longer than it is wider covering the remaining part of the screen. At the top of this area are the initials the players input previously with the color after it. These colors will become brighter and faded depending on whose turn it is to play.  
And lastly there will be a cross button on top of the screen to close the window to exit the game.


Logic of the game:
The players will play based on their turns. The main objective of the game is to form squares or boxes with 4 vertices using the single vertex a player can use on their turns.
When a user clicks on any faded vertex connecting the points in the main grid of the game, it will be converted into a real vertex connecting the 2 dots. When a player completes a 1-unit box, then his/her initially selected color will fill inside the box and he/she will be granted a point. Also, the player who succeeds in making a box will be given another turn to play again, otherwise, turn passes to the next player. The player with, most boxes with his initially selected color wins the game.
What we are going to use to make this project:
For the whole project open gl will be mainly used with some other functions and libraries present in C. There will also be use of loops, conditional statements, 2D arrays, switch cases. etc.

Some additional features to add in if permitted by time:
1.	When making the grid, we can randomly seal off some points/dots which will give the players no points even on completion of a box around them or even penalize them with negative points.
2.	We also have a vague idea of introducing a computer player which will be playing against a single user trying its best to win the game.
