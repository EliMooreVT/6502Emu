# 6502Emu - by Eli Moore


A personal project where I am creating a from-scratch emulator for a 6502-based computer.
Right now, the application includes basic 6502 instructions that can be read in through a binary file (Which can be created through my .txt to .bin file converter) that includes the opcodes for the instructions. Soon, I will have an assembler that would take in a .asm file and convert into opcodes for quick assembly development. The emulator currently runs with a debugger that monitors memory locations, flags, etc. 

I am using github as a project organiser, so on the Projects and Issues tab, you can see what I am currently working on and what I will be implementing in the future. So far this project is only being created by me in Visual Studio C++, and I am using no external libraries (at the moment). I hope to keep this as strictly from-scratch work, but in the future, I might use the Win32 api or other apis to help with creating a GUI or optimized debugger. 

I am hoping for this to evolve into a full computer emulator (with graphics and sound), either emulating the NES, or a commodore-like machine of my own creation.

Full readme will be updated soon. 

## Building
### Windows with Visual Studio
- The 6502Emu folder is the solution directory
- Open 6502Emu.sln to get into the solution within Visual Studio
- Change the configuration to Debug x86 before building
### Linux with cmake
- Install ncurses and X11 libraries
- If using VSCode, open the workspace in the 6502Emu folder, NOT the root directory. Make sure you have CMake tools installed and set up properly and you're good to go
- Cmake using the CMakeLists.txt and output to a folder called "build"
- When testing, make sure that any code files that you want to use on the program are in the same folder as the executable
(Note: Input is currently finnicky on Linux)


- While debugging, the code.txt file in the 'Resources' filter of EmuWrapper is where opcodes are written (hex byte - space - hex byte - space, etc), which is converted into code.bin.
- In Emu-Wrapper>Main.cpp, there are a few debugger options that can be turned on and off by using commands before using `Emu::startSystem()`:
  - `Debug::enablePrint()` - Turns on a 'verbose' mode where you can see what the program is currently doing. Mainly for tracking bugs in the system rather than in an assembly program
  - `Debug::mvEnable()` - Turns on the Memory Viewer(MV) that monitors the memory that is being manipulated. This is currently the only way to see what is going on within the system
  - `Debug::enableSteps()` - Makes the program halt after each instruction so that you can debug step-by-step while developing assembly code

Simpler and more interactable methods of controlling the system and the program itself will be implemented once the emulator itself is further developed
