# duck-engine
A game engine I'm currently working on.
I'm making this engine in C++, using SDL2 for rendering and spdlog for logging. I want a wide scripting language support, supporting languages like C and C++ via native shared libraries, but also C#, python and lua via embedding.
The scenes will be defined in xml.
My idea is that the a game will be a folder or an archive, and when you wanna start a game you run something like `duck-engine --run-game "path/to/your/game/"`. The folder/archive should look something like this:
```
my_game/
├── config.xml
├── resources.xml
├── assets/
├── scripts/
│   ├── game.so
│   └── scene1.so
└── scenes/
    └── scene1.xml
```
Basically everything will probably change during the development, but this is just what I'm imagining right now.

I appriciate any suggestions/criticism on this project or any of my other project.
