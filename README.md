# CIS210

========================================================================================================================================================================================

## Summarize the project and what problem it was solving.

This project is designed to help a grocery store organize and interpret a list of all items sold at the grocery store in the form of a .txt file and translate it into meaningful data for the store to use. 
The program gives the user several options in the form of a main menu, and provide different basic functions depending on input. 
The program organizes and formats the data and creates a .dat file of each item sold with a quantity value associated to it.

## What did you do particularly well?

I think in this project I did a good job at seperating the functions from the main program, and avoided repeating the same code and cluttering the project.
I also think that the initial storing of the data into a map and incrementing the value if it was already created was executed very efficiently.


## Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?

I did notice toward the end of the project that I may have added too many functions dependent on each other which may cause difficulty for troubleshooting.
For example the program utilizes several functions to validate input by chaining into each other, and it may add complexity for no reason.


## Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

I had a very difficult time writing the code to properly access and iterate through the map once the values were stored. 
I ended up using an iterator to go through each indiviual item in the map, but it was not very easy for me to understand at first.
Thankfully there are a lot of online resources I was able to use to help educate me on maps, including the zybooks section on maps, as well as https://cplusplus.com/reference/map/map/
The cplusplus.com website was very helpful for understanding each of the functions included with maps, which proved to be very useful.


## What skills from this project will be particularly transferable to other projects or course work?

During this project I went through many different layouts and design ideas, and I think the only reason I was able to do that and not overwhelm myself was thanks to efficiently organizing the code.
Even though I ended up refactoring large portions of the code many times, I was always able to easily rearrange or make minor changes in the proper places without having too much confusion.
I also learned in depth about the use of maps in the project and can see how useful they are, I look forward to attempting to utilize them whenever possible in future projects.


## How did you make this program maintainable, readable, and adaptable?

I attempted to seperate the seperate functions as well as I could for this project, and made it so each function has a logical purpose and does not rely on outside sources allowing it to be easily edited and understood.
It is also very easy to add functions thanks to how I stored the map values. 
The data was already organized as it was read from the .txt file so accessing it is very straightforward. 
The main() function is also very concise thanks to the heavy use of functions so it is very easy to see how each section of code interacts with another.
