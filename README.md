# OpenRPG
OpenRPG is still in its infancy and I want it to do a lot by v1.0.0!  
What OpenRPG aims to accomplish two fold.  

First, it will be a tool for someone to use to quickly create content
for a tabletop RPG world. v1.0.0 will focus specifically on the
5e rules, however I hope to have that expand out to include
Pathfinder and as far back as AD&D.

Secondly, OpenRPG should be structured in such a way that game developers
that want to emulate the d20 system in a video game could easily implement
our libraries in their games to help speed production of back end tools.

Some of the features this tool will include by v1.0.0 are:
- A GUI front-end for the CLI tools
- A dice simulation tool
- A name generator tool
- A character generator tool (with the option to autofill a character sheet)
- A town generator tool
- An encounter/combat generator tool
- A world generator tool
- A world/town map generator

... And more (hopefully)!

v0.1.0 will be a basis for the CLI/developer version, but v1.0.0 will contain a
portable GUI that works on Windows, Linux, and macOS.

# Building
Currently we require `cmake` (at least v2.8.4) and `make`

Create a build directory `$ mkdir build && cd build`  
Run cmake `$ cmake ..` OR  
Optionally run `$ cmake -DCMAKE_INSTALL_PREFIX=/desired/install/location ..`  
Run make `$ make`  
Run make check `$ make check` 

# Installing
After building run make install `$ make install`

# License
GNU GENERAL PUBLIC LICENSE, Version 3, 29 June 2007 (GPL-3.0)