# Miniat-Crush
This program is an add-on executabile for the MiniAT micro-controller Virtual Machine. It runs commands that mash .asm files and runs thier .bin output with miniat_console. The pursope of this program is to create an easier way to test written assembly code with the miniat_console VM.   

# Setting up Crush 
Setting up Crush is very simple, just drag and drop the files in the Miniat-Crush folder into the <strong>/miniat/system/console</strong> directory. Once you have done that, run <strong>scons</strong> and crush should compile.

# Running Crush
While in the main miniat directory, type <strong>crush myfilename.asm</strong> into your terminal. Make sure the file you are trying to crush is also in the miniat main directory.