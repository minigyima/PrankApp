# PrankApp
Random app used for pranking people
-----------------------------------
Just a quick C++ project, I mainly wrote it, as a challange
# Payloads
-----------------------------------
The program starts of by dropping some VBS scripts, than executing them.
These scripts can be found in the 'MakeScripts' function in the program. They're basically just MessageBoxes with a simple loop.
-----------------------------------
After the scripts are dropped and executed, the program enters a loop, where it scans the process list, and proactively kills task manager.
After every kill attempt, the program plays the imfamous 'OOF' sound effect from Roblox, and executes the VBS scripts again.
This cycle continues.
